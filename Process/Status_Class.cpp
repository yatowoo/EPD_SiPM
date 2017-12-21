#ifndef STATUS_CLASS_CPP
#define STATUS_CLASS_CPP


#include "Data_Class.cpp"


// class Board;

class Board_Status
{
public:
  Board_Status() = default;
  Board_Status(int Board_Num);
  Board_Status(int Board_Num, int voltage_Nums, double *Voltages);
  Board_Status(int board_Num, int voltage_Nums, double *voltages, int dac_Nums, int * DACs);
  ~Board_Status();

  void print()
  {
    cout << "----------------" << endl;
    cout << "Board Number: " << Board_Num << endl;
    cout << "Noise Voltage: " << Voltage_Noise << endl;
    cout << "Signal Voltage: " << endl;
    for(int i = 0; i < Voltage_Nums - 1; i++)
    {
      cout << i << " th Voltage: " << Voltage_Signal[i] << endl;
    }

    cout << "----------------" << endl;

  }

  const int Get_Board_Num() {return Board_Num;}
  const int Get_Voltage_Nums() {return Voltage_Nums;}
  const double Get_Voltage_Noise() {return Voltage_Noise;}
  const int Get_DAC_Nums(){return DAC_Nums;}
  const int Get_DAC(int i)
  {
    if(i >= 0 && i < DAC_Nums)
    {
      return DAC[i];
    }
    else return 0;
  }

  double operator [](int i)
  {
    if(i >= 0 && i < Voltage_Nums - 1)
    {
      return Voltage_Signal[i];
    }
    else
    {
      range_error r("range error!");
      throw r;
    }
  }

protected:
  const int Board_Num;

  const int Voltage_Nums;
  const double Voltage_Noise;
  double Voltage_Signal[100];

  const int DAC_Nums;
  int DAC[100];

  // friend:
  // void operator <<(ostream &os);

};

Board_Status::Board_Status(int board_Num):
Board_Num(board_Num), Voltage_Nums(2), Voltage_Noise(46), DAC_Nums(3), Voltage_Signal{60}, DAC{-127, 0, 127}
{
  // Voltage_Signal = new const double[5]{56, 58, 60, 62, 64};
  //
  // DAC = new const int[3]{-64, 0, 64};
}

Board_Status::Board_Status(int board_Num, int voltage_Nums, double *voltages):
Board_Num(board_Num), Voltage_Nums(voltage_Nums), Voltage_Noise(voltages[0]), DAC_Nums(3), DAC{-127, 0, 127}
{
  // double *temp = new double[Voltage_Nums - 1];
  for(int i = 0; i < Voltage_Nums - 1; i++)
  {
    // temp[i] = voltages[i + 1];
    Voltage_Signal[i] = voltages[i + 1];
  }
  // Voltage_Signal = temp;

  // DAC = new const int[3]{-64, 0, 64};
}

Board_Status::Board_Status(int board_Num, int voltage_Nums, double *voltages, int dac_Nums, int * DACs):
Board_Num(board_Num), Voltage_Nums(voltage_Nums), Voltage_Noise(voltages[0]), DAC_Nums(dac_Nums)
{
  // double *temp = new double[Voltage_Nums - 1];
  for(int i = 0; i < Voltage_Nums - 1; i++)
  {
    Voltage_Signal[i] = voltages[i + 1];
  }
  // Voltage_Signal = temp;

  // int * i_temp = new int[DAC_Nums];
  for(int i = 0; i < DAC_Nums; i++)
  {
    DAC[i] = DACs[i];
  }
  // DAC = i_temp;

}


Board_Status::~Board_Status()
{
  // delete Voltage_Signal;
}

ostream &operator <<(ostream &os, Board_Status &board)
{
  os << board . Get_Voltage_Nums() << endl;
  os << "Noies: " << board . Get_Voltage_Noise() << "V" << endl;

  os << "Signal: " ;
  for(int i = 0; i < board . Get_Voltage_Nums() - 1; i++)
  {
    os << board[i] << "V\t";
  }
  os << endl;

  os << "DAC: ";
  for(int i = 0; i < board . Get_DAC_Nums(); i++)
  {
    os << board . Get_DAC(i) << "\t";
  }
  os << endl;

  return os;
}






class Board_All_Name : public  virtual Board_Status
{
public:
  Board_All_Name() = default;
  Board_All_Name(string root_folder, int Board_Num);
  Board_All_Name(string root_folder, int Board_Num, int voltage_Nums, double * Voltages);
  Board_All_Name(string root_folder, int Board_Num, int voltage_Nums, double * Voltages, int DAC_Nums, int * DACs);


  string Root_File_Name();

  string UI_File_Name(int Channel);
  string UI_Gr_Name(int Channel);


  string Noise_File_Name(int Channel);
  string Noise_Branch_Name(int Channel);
  string Noise_Ped_Hist_Name(int Channel);
  string Noise_Slope_Hist_Name(int Channel);
  string Noise_FFT_Hist_Name(int Channel);

  string DAC_File_Name(int Channel, int DAC_Num);
  string DAC_Branch_Name(int Channel, int DAC_Num);
  string DAC_Ped_Hist_Name(int Channel, int DAC_Num);
  string DAC_Slope_Hist_Name(int Channel, int DAC_Num);


  string Signal_File_Name(int Channel, int Voltage_Num);
  string Signal_Branch_Name(int Channel, int Voltage_Num);
  string Signal_Charge_Hist_Name(int Channel, int Voltage_Num);

  void Print_All_Information();
  void Check_Information();

  ~Board_All_Name() = default;
  // string channel
private:
  string root_folder;
  string Board;

};


Board_All_Name::Board_All_Name(string root_folder, int Board_Num):
root_folder(root_folder), Board_Status(Board_Num), Board(to_string(Board_Num))
{}

Board_All_Name::Board_All_Name(string root_folder, int Board_Num, int voltage_Nums, double * Voltages):
root_folder(root_folder), Board_Status(Board_Num, voltage_Nums, Voltages), Board(to_string(Board_Num))
{}

Board_All_Name::Board_All_Name(string root_folder, int Board_Num, int voltage_Nums, double * Voltages, int DAC_Nums, int * DACs):
root_folder(root_folder), Board_Status(Board_Num, voltage_Nums, Voltages, DAC_Nums, DACs), Board(to_string(Board_Num))
{}

void Board_All_Name::Print_All_Information()
{
  char c_temp[30];

  cout << "---------------------" << endl;
  cout << "****"<< "No." << Board_Num << "****" << endl;
  cout << "---------------------" << endl;

  cout << "Board Basic Information: " << endl;
  cout << "---------------------" << endl;
  cout << "Board Noise Voltage: " << Voltage_Noise << endl;

  cout << "Board DACs: ";
  for(int i = 0; i < DAC_Nums; i++)
  {cout << " " << DAC[i];}
  cout << endl;

  cout << "Board Signal Voltages: ";
  for(int i = 0; i < Voltage_Nums - 1; i++)
  {cout << " " << Voltage_Signal[i];}
  cout << endl;

  cout << "---------------------" << endl;

  cout << "Board File Information: " << endl;
  cout << "---------------------" << endl;
  cout << "Original Datas: " << endl;

  cout << "-- Noise: " ;
  sprintf(c_temp, "%2.0f", Voltage_Noise);
  cout << (string)"/" + c_temp + "V/";
  cout << endl;

  cout << "-- DACs: " << endl;
  for(int i = 0; i < DAC_Nums; i++)
  {
    cout << "   |" << endl;
    cout << "   --- ";
    char c[20];
    int dac = DAC[i];
    sprintf(c, "DAC_%d", dac);

    if(dac == 0)
    {
      sprintf(c_temp, "%2.0f", Voltage_Noise);
      cout << (string)"/" + c_temp + "V/";
      cout << "(Same as Noise)";
    }
    else
    {
      string s_DAC(c);

      double voltage = Voltage_Noise;
      char c_voltage[20];
      sprintf(c_voltage, "%2.0f", voltage);
      string s_voltage(c_voltage);

      cout << "/" + s_DAC + "_" + s_voltage + "V/";
    }

    cout << endl;
  }
  cout << endl;


  cout << "-- Signals: " << endl;
  for(int i = 0; i < Voltage_Nums - 1; i++)
  {
    cout << "   |" << endl;
    cout << "   --- ";
    char c[20];
    sprintf(c, "%2.0f", Voltage_Signal[i]);
    string voltage(c);
    cout << "/" + voltage + "V/";
    cout << endl;
  }

  cout << endl;
  cout << "Output Datas: " << endl;
  cout << "- Root: ";
  cout << Root_File_Name() << endl;
  cout << " |" << endl;
  cout << " -- Channels: " << "16 Channel Folders" << endl;

  cout << "    |" << endl;
  cout << "    -- Tree: ";
  cout << "Noise, DACs, Signals Sample Histograms, Events" << endl;

  cout << "    |" << endl;
  cout << "    -- UI Curve " << endl;
  cout << "    |" << endl;
  cout << "    -- Noise Pedestal " << endl;
  cout << "    |" << endl;
  cout << "    -- Noise Slope " << endl;
  cout << "    |" << endl;
  cout << "    -- Noise FFT " << endl;
  cout << "    |" << endl;
  cout << "    -- DAC Pedestal " << endl;
  cout << "    |" << endl;
  cout << "    -- Signal Charges " << endl;
}

void Board_All_Name::Check_Information()
{
  cout << "Root_File_Name: " << Root_File_Name() << endl << endl;

  cout << "UI_File_Name: " << UI_File_Name(0) << endl;
  cout << "UI_Gr_Name: " << UI_Gr_Name(0) << endl << endl;


  cout << "Noise_File_Name: " << Noise_File_Name(0) << endl;
  cout << "Noise_Branch_Name: " << Noise_Branch_Name(0) << endl;
  cout << "Noise_Ped_Hist_Name: " << Noise_Ped_Hist_Name(0) << endl;
  cout << "Noise_Slope_Hist_Name: " << Noise_Slope_Hist_Name(0) << endl;
  cout << "Noise_FFT_Hist_Name: " << Noise_FFT_Hist_Name(0) << endl << endl;

  cout << "DAC_File_Name: " << DAC_File_Name(0, 0) << endl;
  cout << "DAC_Branch_Name: " << DAC_Branch_Name(0, 0) << endl;
  cout << "DAC_Ped_Hist_Name: " << DAC_Ped_Hist_Name(0, 0) << endl;
  cout << "DAC_Slope_Hist_Name: " << DAC_Slope_Hist_Name(0, 0) << endl << endl;


  cout << "Signal_File_Name: " << Signal_File_Name(0, 0) << endl;
  cout << "Signal_Branch_Name: " << Signal_Branch_Name(0, 0) << endl;
  cout << "Signal_Charge_Hist_Name: " << Signal_Charge_Hist_Name(0, 0) << endl << endl;

}


string Board_All_Name::Root_File_Name()
{
  return root_folder + "/" + "B" + Board + "/" +"Board_" + Board + ".root";
}

string Board_All_Name::UI_File_Name(int Channel)
{
  string UI_File_Name1(root_folder);
  UI_File_Name1 += "/B" + Board;
  UI_File_Name1 += "/UIcurve_" + to_string(Channel) + "C";
  return UI_File_Name1;
}

string Board_All_Name::UI_Gr_Name(int Channel)
{
  return "B" + Board + "_UI_Graph_" + to_string(Channel) + "C";
}

string Board_All_Name::Noise_File_Name(int Channel)
{
  char c[20];
  sprintf(c, "%2.0f", Voltage_Noise);
  string voltage(c);
  return root_folder + "/B" + Board + "/" + voltage + "V/" + "wave_" + to_string(Channel) + ".dat";
}

string Board_All_Name::Noise_Branch_Name(int Channel)
{
  char c[20];
  sprintf(c, "%2.0f", Voltage_Noise);
  string voltage(c);
  return "B" + Board + "_Noise_Branch_" + c + "V" + "_" + to_string(Channel) + "C";
}

string Board_All_Name::Noise_Ped_Hist_Name(int Channel)
{
  return "B" + Board + "_Noise_Pedestal" + "_" + to_string(Channel) + "C";
}

string Board_All_Name::Noise_Slope_Hist_Name(int Channel)
{
  return "B" + Board + "_Noise_Slope" + "_" + to_string(Channel) + "C";
}

string Board_All_Name::Noise_FFT_Hist_Name(int Channel)
{
  return "B" + Board + "_Noise_FFT" + "_" + to_string(Channel) + "C";
}

string Board_All_Name::DAC_File_Name(int Channel, int DAC_Num)
{
  char c[20];
  int dac = DAC[DAC_Num];
  sprintf(c, "DAC_%d", dac);

  if(dac == 0)
  {
    return Noise_File_Name(Channel);
  }
  else
  {
    string s_DAC(c);

    double voltage = Voltage_Noise;
    char c_voltage[20];
    sprintf(c_voltage, "%2.0f", voltage);
    string s_voltage(c_voltage);

    return root_folder + "/B" + Board + "/" + s_DAC + "_" + s_voltage + "V/" + "wave_" + to_string(Channel) + ".dat";
  }

}

string Board_All_Name::DAC_Branch_Name(int Channel, int DAC_Num)
{
  char c[20];
  int dac = DAC[DAC_Num];
  sprintf(c, "%d", dac);

  if(dac == 0)
  {
    return Noise_Branch_Name(Channel);
  }
  else
  {
    string s_DAC(c);

    double voltage = Voltage_Noise;
    char c_voltage[20];
    sprintf(c_voltage, "%2.0f", voltage);
    string s_voltage(c_voltage);

    // return root_folder + "/B" + Board + "/" + s_DAC + "_" + s_voltage + "V/" + "wave_" + to_string(Channel) + ".dat";
    return "B" + Board + "_DAC_Branch_" + s_DAC + "_" + s_voltage + "V" + "_" + to_string(Channel) + "C";

  }
}

string Board_All_Name::DAC_Ped_Hist_Name(int Channel, int DAC_Num)
{
  char c[20];
  int dac = DAC[DAC_Num];
  sprintf(c, "%d", dac);

  if(dac == 0)
  {
    return Noise_Ped_Hist_Name(Channel);
  }
  else
  {
    string s_DAC(c);

    double voltage = Voltage_Noise;
    char c_voltage[20];
    sprintf(c_voltage, "%2.0f", voltage);
    string s_voltage(c_voltage);

    // return root_folder + "/B" + Board + "/" + s_DAC + "_" + s_voltage + "V/" + "wave_" + to_string(Channel) + ".dat";
    // return "B" + Board + "_DAC_Branch_" + s_DAC + "_" + s_voltage + "V" + "_" + to_string(Channel) + "C";
    return "B" + Board + "_DAC_Ped_" + s_DAC + "_" + s_voltage + "V" + "_" + to_string(Channel) + "C";


  }
}

string Board_All_Name::DAC_Slope_Hist_Name(int Channel, int DAC_Num)
{
  char c[20];
  int dac = DAC[DAC_Num];
  sprintf(c, "%d", dac);

  if(dac == 0)
  {
    return Noise_Slope_Hist_Name(Channel);
  }
  else
  {
    string s_DAC(c);

    double voltage = Voltage_Noise;
    char c_voltage[20];
    sprintf(c_voltage, "%2.0f", voltage);
    string s_voltage(c_voltage);

    return "B" + Board + "_DAC_Slope_" + s_DAC + "_" + s_voltage + "V" + "_" + to_string(Channel) + "C";

  }
}

string Board_All_Name::Signal_File_Name(int Channel, int Voltage_Num)
{
  char c[20];
  sprintf(c, "%2.0f", Voltage_Signal[Voltage_Num]);
  string voltage(c);
  return root_folder + "/B" + Board + "/" + voltage + "V/" + "wave_" + to_string(Channel) + ".dat";
}

string Board_All_Name::Signal_Branch_Name(int Channel, int Voltage_Num)
{
  char c[20];
  sprintf(c, "%2.0f", Voltage_Signal[Voltage_Num]);
  string voltage(c);
  return "B" + Board + "_Signal_Branch_" + c + "V" + "_" + to_string(Channel) + "C";
}

string Board_All_Name::Signal_Charge_Hist_Name(int Channel, int Voltage_Num)
{
  char c[20];
  sprintf(c, "%2.0f", Voltage_Signal[Voltage_Num]);
  string voltage(c);
  return "B" + Board + "_Signal_Charge_" + c + "V" + "_" + to_string(Channel) + "C";
}






class Channel_Status
{
public:
  // Channel_Status()
  // Channel_Status() = default;
  Channel_Status(int channel): Channel(channel){}
  ~Channel_Status() = default;

protected:
  // bool Is_Create_Root_File = 0;
  bool Is_Noise_Saved = false;
  bool Is_Charge_Saved = false;
  bool Is_Gain_Saved = false;


  int Channel;
  vector<int> v_Events;

  double Amplitude = 2.60925e-1;
  double Charge_Coefficience = Amplitude * 1e-9 * 1e-3 / 5;

};





#endif
