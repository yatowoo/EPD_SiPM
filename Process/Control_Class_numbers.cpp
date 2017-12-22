#ifndef CONTROL_CLASS_CPP
#define CONTROL_CLASS_CPP

#include "Status_Class.cpp"

#define SIGNAL_START (500)
#define SIGNAL_END (600)
#define SIGNAL_LENGTH (SIGNAL_END)-(SIGNAL_START)

#define SAMPLE_GAP 10

#define SAVE_FIRST (SIGNAL_START)-(SIGNAL_LENGTH)-(SAMPLE_GAP)
#define SAVE_LAST (SIGNAL_END)+(SAMPLE_GAP)+(SIGNAL_LENGTH)
#define SAVE_BINS (SAVE_LAST)-(SAVE_FIRST)



class Channel_Control : public Channel_Status
{
public:
  Channel_Control(Board_All_Name &board_Name, int channel, TFile *file): Board_Name(board_Name), Channel_Status(channel), tree(to_char("Channel_" + to_string(Channel)), to_char("Channel_" + to_string(Channel))),
  f(file)
  {
    // cout << Board_Name << endl;
    // Board_Name . Print_All_Information();
  }


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

  cout << "Channel: " << Channel << endl << endl;
  // cout << Board_Name << endl;

  Write_Noise();

  Write_DAC();

  Write_Signal();

  cout << "Done!" << endl << endl << endl << endl << endl;




}

void Channel_Control::Write_Noise()
{

  string s_channel = to_string(Channel);

  if(f -> cd(to_char("/Channel" + s_channel)) == false)
  {
    f -> cd("/");
    f -> mkdir(to_char("Channel" + s_channel));
    f -> cd(to_char("Channel" + s_channel));
  }


  int Events = 0;


  // Write Noise

  // Set Noise Entry address
  double voltage_Noise = Board_Name. Get_Voltage_Noise();

  wave_data wave_temp("Wave", "Wave");
  TH1F wave = wave_temp;

  auto branch_noise = tree . Branch(to_char(Board_Name . Noise_Branch_Name(Channel)), "TH1F", &wave);


  auto Noise_Slope = Noise_Slope_Hist(to_char(Board_Name . Noise_Slope_Hist_Name(Channel)), to_char(Board_Name . Noise_Slope_Hist_Name(Channel)));
  auto Noise_Ped = Noise_Ped_Hist(to_char(Board_Name . Noise_Ped_Hist_Name(Channel)), to_char(Board_Name . Noise_Ped_Hist_Name(Channel)));
  auto Noise_FFT = Noise_FFT_Hist(to_char(Board_Name . Noise_FFT_Hist_Name(Channel)), to_char(Board_Name . Noise_FFT_Hist_Name(Channel)));



  // Read Noise
  ifstream fin;
  fin . open( to_char(Board_Name . Noise_File_Name(Channel)));
  if(fin . is_open() == false)
  {
    range_error r("File Didn't open");
    throw r;
  }


  for(int j = 0; fin . eof() == 0; j++)
  {


    for(int i = 0; i < 1024; i++)
    {
      float temp;
      // fin >> temp;
      fin . read((char *)&temp, sizeof(temp));
      // cout << temp << endl;
      wave . SetBinContent(i + 1, temp);
    }
    // throw 1;

    // if(j < 200)
    // {
    //   continue;
    // }



    {
      // TF1 f1("tempf", "[0]+[1]*x", 0, 1024);
      // wave . Fit(&f1, "NQR", "", 0, 1024);
      // Noise_Slope . Fill(f1 . GetParameter(1));
      // Noise_Ped . Fill(f1 . GetParameter(0));
    }
    Noise_Ped . Fill(wave . Integral() / 1024);


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
  //gPad->SetLogy();
  Noise_FFT . Write();


  fin . close();

  Is_Noise_Saved = true;

  cout << endl;
  cout << "DAC = 0 Pedestal standard deviration: " << Noise_Ped . GetStdDev() << endl;
  if(Noise_Ped . GetStdDev() > 1)
  {
    cout << "Warning: DAC = 0 standard deviration is a little large, suggest to check again." << endl;
  }





}

void Channel_Control::Write_DAC()
{
  string s_channel = to_string(Channel);

  if(f -> cd(to_char("/Channel" + s_channel)) == false)
  {
    f -> cd("/");
    f -> mkdir(to_char("Channel" + s_channel));
    f -> cd(to_char("Channel" + s_channel));
  }


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
    TH1F wave = wave_temp;

    auto branch = tree . Branch(to_char(Board_Name . DAC_Branch_Name(Channel, i)), "TH1F", &wave);
    Noise_Ped_Hist DAC_Ped_temp(Board_Name . DAC_Ped_Hist_Name(Channel, i), Board_Name . DAC_Ped_Hist_Name(Channel, i));
    TH1F DAC_Ped = DAC_Ped_temp;

    fin . open(Board_Name . DAC_File_Name(Channel, i));
    // cout << "****************************************************************************************************************************************" << endl;
    // cout << Board_Name . DAC_File_Name(Channel, i) << endl << endl;
    // auto h1 = new Noise_Ped_Hist(Board_Name . DAC_Ped_Hist_Name(Channel, i), Board_Name . DAC_Ped_Hist_Name(Channel, i));



    for(int j = 0; fin . eof() == 0; j ++)
    {
      for(int k = 0; k < 1024; k++)
      {
        float temp;
        // fin >> temp;
        fin . read((char *)&temp, sizeof(temp));
        // wave . SetBinContent(i + 1, temp);
        wave . SetBinContent(k + 1, temp);
      }

      // if(j < 200)
      // {
      //   continue;
      // }

        {
          // TF1 f("f", "[0]+[1]*x", 0, 1024);
          // wave.Fit(&f, "NQR", "", 0, 1024);
          // DAC_Ped . Fill(f . GetParameter(0));
        }
        DAC_Ped . Fill(wave . Integral() / 1024);


      // if(f.GetParameter(1) < 1e-7)
      // {
      //   continue;
      // }
      // else
      // {
      //   DAC_Ped . Fill(f . GetParameter(0));
      // }



      // cout << wave.GetMean(2) << endl;
      // auto h = new TH1F(wave);cout << h << endl;
      // throw 1;

      if(j % 70 == 0)
      {
        branch -> Fill();
      }


    }

    // branch -> Write();
    DAC_Ped . Write();
    fin . close();

    cout << endl;
    cout << "DAC = " << to_string(DACs[i]) << " Pedestal standard deviration: " << DAC_Ped . GetStdDev() << endl;
    if(DAC_Ped . GetStdDev() > 1)
    {
      cout << "Warning: pedestal standard deviration is a little large, suggest check again." << endl;
    }



  }




}

void Channel_Control::Write_Signal()
{
  string s_channel = to_string(Channel);

  if(f -> cd(to_char("/Channel" + s_channel)) == false)
  {
    f -> cd("/");
    f -> mkdir(to_char("Channel" + s_channel));
    f -> cd(to_char("Channel" + s_channel));
  }

  int Events = 0;

  wave_data wave_temp("Wave", "Wave");
  TH1F wave = wave_temp;

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

  TH1F * h = (TH1F *)dir -> Get(to_char(Board_Name . Noise_Slope_Hist_Name(Channel)));

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

    // const char *c_temp = to_char(Board_Name . Signal_Branch_Name(Channel, k) + "[" + to_string(SAVE_BINS) + "]/S");

    // const char *c = (const char *)c_temp;
    char c[128];
    int signal_bins = SAVE_BINS;
    sprintf(c, "f[%d]", signal_bins);
    float wave_numbers[SAVE_BINS];

    // auto branch = tree . Branch(to_char(Board_Name . Signal_Branch_Name(Channel, k)), wave_numbers, c);
    auto branch = tree . Branch(to_char(Board_Name . Signal_Branch_Name(Channel, k)), wave_numbers, c);
    // auto branch = tree . Branch(to_char(Board_Name . Signal_Branch_Name(Channel, k)), "TH1F", &wave);


    // signal_branches . push_back(branch);
    Signal_Charge_Hist Signal_Charge_temp(to_char(Board_Name . Signal_Charge_Hist_Name(Channel, k)), to_char(Board_Name . Signal_Charge_Hist_Name(Channel, k)), 1);

    TH1F Signal_Charge = Signal_Charge_temp;


    Events = 0;




    for(int j = 0; fin . eof() == 0; j++, Events ++)
    {
      for(int i = 0; i < 1024; i++)
      {
        float temp;
        // fin >> temp;
        fin . read((char *)&temp, sizeof(temp));
        wave . SetBinContent(i + 1, temp);
        if(i >= SAVE_FIRST && i <= SAVE_LAST && i - SAVE_FIRST < SAVE_BINS)
        {
          wave_numbers[i - SAVE_FIRST] = temp;
          // cout << wave_numbers[i] << endl;
        }
        // cout << i << "\t";
      }

      // if(j < 200)
      // {
      //   continue;
      // }



      // TF1 f2("tempf", "[0]+[1]*x", 0, 1024);
      //
      // wave . Fit(&f2, "N", "", 0, 600);
      //
      // if(abs(f2 . GetParameter(1) - Slope_Mean) > Slope_Dev)
      // {
      //   continue;
      // }

      // wave . Add(&f2, -1);
      double inter = wave . Integral(SIGNAL_START, SIGNAL_END);
      double low = wave . Integral(SAVE_FIRST, SIGNAL_START - SAMPLE_GAP);
      double high = wave . Integral(SIGNAL_END + SAMPLE_GAP, SAVE_LAST);
      // cout << to_char(Board_Name . Signal_File_Name(Channel, k));
      // cout << "***********************************************************" << endl;


      // signal_charges[k] -> Fill(inter * Charge_Coefficience);
      Signal_Charge . Fill(inter - (low + high) / 2);


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


    cout << endl;
    cout << "Signal: U = " << 60 << "V " << "Mean: " << Signal_Charge . GetMean() << endl;
    if(Signal_Charge . GetMean() > -100)
    {
      cout << "Warning: Signal Mean is a little small, please check again." << endl;
    }


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

    TH1F * h = (TH1F *)f -> Get(to_char(Board_Name . Signal_Charge_Hist_Name(Channel, i)));

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
  Board_Control(string root_folder, int Board_Num): Board_Basic_Status(root_folder, Board_Num)
  {
    // auto file_temp = new TFile(to_char(Board_Basic_Status . Root_File_Name()));
    // if(file_temp -> IsOpen() == true)
    // {
    //   f = file_temp;
    //   Is_Done = true;
    // }
    // else
    // {
    //   f =  new TFile(to_char(Board_Basic_Status . Root_File_Name()), "recreate");
    //   Is_Done = false;
    // }
    cout << SAVE_FIRST << endl;
    cout << SAVE_LAST << endl;
    cout << SAVE_BINS << endl;

    f =  new TFile(to_char(Board_Basic_Status . Root_File_Name()), "recreate");
    Is_Done = false;


  }

  ~Board_Control()
  {
    End();
  }

  void Start()
  {
    if(Is_Done == false)
    {
      for(int i = 0; i < 16; i++)
      {
        Channel_Control channel(Board_Basic_Status, i, f);
        channel . Write_Channel();
      }

    }
    else
    {
      cout << "Have already been done!" << endl;
      cout << "Just read it." << endl;
    }


  }

  void Start(int Channel)
  {
    if(Is_Done == false)
    {
      Channel_Control channel(Board_Basic_Status, Channel, f);
      channel . Write_Channel();

    }
    else
    {
      cout << "Have already been done!" << endl;
      cout << "Just read it." << endl;
    }

  }

  void End()
  {
    f -> Close();
    f = NULL;
    delete f;
  }

  void Print_All_Information()
  {
    Board_Basic_Status . Print_All_Information();
  }

  TH1F *Draw_Signal(int Channel, int voltage_num, int number)
  {
    string s("Channel");
    auto dir = f -> GetDirectory(to_char(s + to_string(Channel)));
    auto tree = (TTree *) dir -> Get(to_char(s + "_" + to_string(Channel)));

    // tree -> Print();
    auto branch = tree -> GetBranch(to_char(Board_Basic_Status . Signal_Branch_Name(Channel, voltage_num)));

    float wave_numbers[SAVE_BINS];
    branch -> SetAddress(wave_numbers);

    branch -> GetEntry(number);

    auto h = new TH1F("h", "h", SAVE_BINS, 0, SAVE_BINS);
    for(int i = 0; i < SAVE_BINS; i++)
    {
      // cout << wave_numbers[i] << endl;
      h -> SetBinContent(i + 1, wave_numbers[i]);
    }

    return h;




  }

  void Draw_Auto(int Channel, int voltage_num)
  {
    string s("Channel");
    auto dir = f -> GetDirectory(to_char(s + to_string(Channel)));
    auto tree = (TTree *) dir -> Get(to_char(s + "_" + to_string(Channel)));

    // tree -> Print();
    auto branch = tree -> GetBranch(to_char(Board_Basic_Status . Signal_Branch_Name(Channel, voltage_num)));

    auto c1 = new TCanvas("c", "c", 1);

    for(int i = 0; i < branch -> GetEntries(); i++)
    {
      c1 -> cd();
      cout << branch -> GetEntries() << endl;
      auto h = Draw_Signal(Channel, voltage_num, i);
      h -> Draw("same");
      // delete h;
      // usleep(1000000);

    }

  }

  bool Write_Other_Object(TObject * obj)
  {
    if(f -> cd("/") == false)
    {
      return false;
    }
    obj -> Write();
    return true;
  }

    TFile *f = NULL;


private:

  Board_All_Name Board_Basic_Status;
  bool Is_Done = false;
};



#endif
