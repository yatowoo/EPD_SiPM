#ifndef CONTROL_CLASS_CPP
#define CONTROL_CLASS_CPP

#include "Status_Class.cpp"

class Channel_Control : public Channel_Status
{
public:
  Channel_Control(Board_All_Name &board_Name, int channel, TFile *file): Board_Name(board_Name), Channel_Status(channel), tree(to_char("Channel_" + to_string(Channel)), to_char("Channel_" + to_string(Channel))),
  f(file)
  {
    // cout << Board_Name << endl;
    // Board_Name . Print_All_Information();
  }

  // TH1S* Read_Noise_File();
  // void Save_Noise_Ped_Hist();
  // void Save_Noise_Slope_Hist();
  // void Save_Noise_FFT_Hist();
  //
  // void Read_Signal_File();
  // void Save_Signal_Branch();
  // void Save_Signal_Charge();
  //
  // void Noise_File();

  void Write_Channel();


  double Get_BD_Voltage();


  ~Channel_Control()
  {
    tree.Write();
    // delete
  }


protected:
  // Channel_Status channel_Status;
  Board_All_Name Board_Name;
  TTree tree;

  TFile *f;

  void Write_Noise();

  void Write_DAC();

  void Write_Signal();



  // void Write_One(TFile *f, TBranch * branch, string file_name);

};

void Channel_Control::Write_Channel()
{
  if(f -> IsOpen() == false)
  {
    range_error r("Error! File didn't open.");
    cout << r.what() << endl;
    throw r;
  }
  Write_Noise();

  Write_DAC();

  Write_Signal();




}

void Channel_Control::Write_Noise()
{

  string s_channel = to_string(Channel);

  f -> cd("/");
  f -> mkdir(to_char("Channel" + s_channel));
  f -> cd(to_char("Channel" + s_channel));


  int Events = 0;

  cout << Channel << endl;
  cout << Board_Name << endl;

  // Write Noise

  // Set Noise Entry address
  double voltage_Noise = Board_Name. Get_Voltage_Noise();

  wave_data wave_temp("Wave", "Wave");
  TH1S wave = wave_temp;

  auto branch_noise = tree . Branch(to_char(Board_Name . Noise_Branch_Name(Channel)), "TH1S", &wave);


  auto Noise_Slope = Noise_Slope_Hist(to_char(Board_Name . Noise_Slope_Hist_Name(Channel)), to_char(Board_Name . Noise_Slope_Hist_Name(Channel)));
  auto Noise_Ped = Noise_Ped_Hist(to_char(Board_Name . Noise_Ped_Hist_Name(Channel)), to_char(Board_Name . Noise_Ped_Hist_Name(Channel)));
  auto Noise_FFT = Noise_FFT_Hist(to_char(Board_Name . Noise_FFT_Hist_Name(Channel)), to_char(Board_Name . Noise_FFT_Hist_Name(Channel)));



  // Read Noise
  ifstream fin;
  fin . open( to_char(Board_Name . Noise_File_Name(Channel)));


  for(int j = 0; fin . eof() == 0; j++)
  {

    for(int i = 0; i < 1024; i++)
    {
      double temp;
      fin >> temp;
      // if(i > 0 &&)
      wave . SetBinContent(i + 1, temp);
    }

    TF1 f1("tempf", "[0]+[1]*x", 0, 1024);

    wave . Fit(&f1, "N", "", 0, 1024);
    Noise_Slope . Fill(f1 . GetParameter(1));
    Noise_Ped . Fill(f1 . GetParameter(0));

    Noise_FFT_Hist fft_temp("fft_temp", "fft_temp");
    wave . FFT(&fft_temp, "MAG R2C EX");
    Noise_FFT . Add(&fft_temp);

    if(j % 70 == 0)
    {
      branch_noise -> Fill();
    }

    Events ++;
  }
  Noise_FFT . Scale(1.0 / Events);
  v_Events . push_back(Events);

  //Save Noise File
  Noise_Slope . Write();
  Noise_Ped . Write();
  Noise_FFT . Write();


  fin . close();

  Is_Noise_Saved = true;




}

void Channel_Control::Write_DAC()
{

  ifstream fin;


  int numbers = Board_Name . Get_DAC_Nums();

  vector<int> DACs;
  for(int i = 0; i < numbers; i++)
  {
    DACs . push_back(Board_Name . Get_DAC(i));
  }


  for(int i = 0; i < numbers; i++)
  {
    if(DACs[i] == 0)
    {
      continue;
    }

    wave_data wave_temp("temp", "temp");
    TH1S wave = wave_temp;

    auto branch = tree . Branch(to_char(Board_Name . DAC_Branch_Name(Channel, i)), "TH1S", &wave);
    Noise_Ped_Hist DAC_Ped_temp(Board_Name . DAC_Ped_Hist_Name(Channel, i), Board_Name . DAC_Ped_Hist_Name(Channel, i));
    TH1S DAC_Ped = DAC_Ped_temp;

    fin . open(Board_Name . DAC_File_Name(Channel, i));
    // cout << "****************************************************************************************************************************************" << endl;
    // cout << Board_Name . DAC_File_Name(Channel, i) << endl << endl;
    // auto h1 = new Noise_Ped_Hist(Board_Name . DAC_Ped_Hist_Name(Channel, i), Board_Name . DAC_Ped_Hist_Name(Channel, i));



    for(int j = 0; fin . eof() == 0; j ++)
    {
      for(int k = 0; k < 1024; k++)
      {
        double temp;
        fin >> temp;
        wave . SetBinContent(k + 1, temp);
      }

      TF1 f("f", "[0]+[1]*x", 0, 1024);
      wave.Fit(&f, "N", "", 0, 1024);

      if(f.GetParameter(1) < 1e-7)
      {
        continue;
      }
      else
      {
        DAC_Ped . Fill(f . GetParameter(0));
      }

      if(j % 70 == 0)
      {
        branch -> Fill();
      }


    }

    // branch -> Write();
    DAC_Ped . Write();
    fin . close();


  }


}

void Channel_Control::Write_Signal()
{
  string s_channel = to_string(Channel);

  int Events = 0;

  wave_data wave_temp("Wave", "Wave");
  TH1S wave = wave_temp;

  ifstream fin;



  if(Is_Noise_Saved == false)
  {
    range_error r("Error! Noies didn't save!");
    cout << "Error! Channel "<< to_string(Channel) << " noise didn't save!"<< endl;
    throw r;
  }
  string dir_name = "Channel" + to_string(Channel);
  TDirectory *dir = f -> GetDirectory(to_char(dir_name));

  // dir -> ls();

  TH1S * h = (TH1S *)dir -> Get(to_char(Board_Name . Noise_Slope_Hist_Name(Channel)));

    // Read Signal File

    // vector<Signal_Charge_Hist *> signal_charges;



    // vector<TBranch *> signal_branches;

    double Slope_Mean = h -> GetMean();
    double Slope_Dev = h -> GetStdDev();

    // for(int i = 0; i < Board_Name . Get_Board_Num() - 1; i++)
    // {
    //   auto Signal_Charge = new Signal_Charge_Hist(to_char(Board_Name . Signal_Charge_Hist_Name(Channel, i)), to_char(Board_Name . Signal_Charge_Hist_Name(Channel, i)), 1);
    //   signal_charges . push_back(Signal_Charge);
    // }
    // cout << "***********************************************************" << endl;

    for(int k = 0; k < Board_Name . Get_Voltage_Nums() - 1; k++)
    {


      fin . open( to_char(Board_Name . Signal_File_Name(Channel, k)));
      if(fin . is_open() == false)
      {
        range_error r("hfldks");
        cout << Board_Name . Signal_File_Name(Channel, k) << endl;
        cout << Board_Name << endl;
        throw r;
      }

      auto branch = tree . Branch(to_char(Board_Name . Signal_Branch_Name(Channel, k)), "TH1S", &wave);
      // signal_branches . push_back(branch);
      Signal_Charge_Hist Signal_Charge_temp(to_char(Board_Name . Signal_Charge_Hist_Name(Channel, k)), to_char(Board_Name . Signal_Charge_Hist_Name(Channel, k)), 1);

      TH1S Signal_Charge = Signal_Charge_temp;


      Events = 0;




      for(int j = 0; fin . eof() == 0; j++, Events ++)
      {
        for(int i = 0; i < 1024; i++)
        {
          double temp;
          fin >> temp;
          wave . SetBinContent(i + 1, temp);
        }

        TF1 f2("tempf", "[0]+[1]*x", 0, 1024);

        wave . Fit(&f2, "N", "", 0, 600);

        if(abs(f2 . GetParameter(1) - Slope_Mean) > Slope_Dev)
        {
          continue;
        }

        wave . Add(&f2, -1);
        double inter = wave . Integral(700, 900);
        // cout << to_char(Board_Name . Signal_File_Name(Channel, k));
        // cout << "***********************************************************" << endl;


        // signal_charges[k] -> Fill(inter * Charge_Coefficience);
        Signal_Charge . Fill(inter);


        if(j % 70 == 0)
        {
          branch -> Fill();
        }



      }

      // TF1 f("Gausf", "gaus(0)+gaus(3)+gaus(6)+gaus(9)", -1, 1);
      // Signal_Charge[k] . Fit(&f, "", "", -1, 1);// Lots of problems here!!!
      //



      v_Events . push_back(Events);

      fin . close();

      Signal_Charge . Write();


    }


    auto branch_events = tree . Branch("Events", &Events, "Events/I");
    for(int i = 0; i < v_Events . size(); i++)
    {
      Events = v_Events[i];
      branch_events -> Fill();
    }
    // branch_events . Write();
    // tree . Write();

    Is_Charge_Saved = true;


}

double Channel_Control::Get_BD_Voltage()
{
  if(Is_Charge_Saved == false)
  {
    cout << "Error: Charge isn't saved" << endl;
    return -1;
  }

  vector<double> x, y;

  for(int i = 0; i < Board_Name . Get_Voltage_Nums() - 1; i++)
  {
    x . push_back(Board_Name[i]);

    TH1S * h = (TH1S *)f -> Get(to_char(Board_Name . Signal_Charge_Hist_Name(Channel, i)));

    TF1 f_fit("fit_gain", "gaus(0)+gaus(3)+gaus(6)+gaus(9)", -1, 1);
    h -> Fit(&f_fit);

    y . push_back(f_fit . GetParameter(1));

  }

  auto gr = new TGraph();


  for(int i = 0; i < x . size(); i++)
  {
    gr -> SetPoint(i, x[i], y[i]);
  }

  gr -> Write();

  return 0;// Not finished yet.


}



class Board_Control
{
public:
  Board_Control(string root_folder, int Board_Num): Board_Basic_Status(root_folder, Board_Num){}
  ~Board_Control()
  {
    End();
  }

  void Start()
  {
    if(f == NULL)
    {
      f =  new TFile(to_char(Board_Basic_Status . Root_File_Name()), "recreate");
    }

    for(int i = 0; i < 16; i++)
    {
      Channel_Control channel(Board_Basic_Status, i, f);

      channel . Write_Channel();

      // channel . Write_Noise(f);
      //
      // channel . Write_DAC(f);
      //
      // channel . Write_Signal(f);

      // channel . Get_BD_Voltage(f);
    }

  }

  void Start(int Channel)
  {
    if(f == NULL)
    {
      f =  new TFile(to_char(Board_Basic_Status . Root_File_Name()), "recreate");
    }

    Channel_Control channel(Board_Basic_Status, Channel, f);

    channel . Write_Channel();
    // channel . Write_Noise(f);
    // // cout << endl << "***********************************************************" << endl;
    //
    // channel . Write_DAC(f);
    //
    // channel . Write_Signal(f);
    // return channel;

  }

  void End()
  {
    f -> Close();
    f = NULL;
    delete f;
  }

private:

  Board_All_Name Board_Basic_Status;
  TFile *f = NULL;
};



#endif
