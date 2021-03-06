//
// // Board是一个root文件
// class Board
// {};
//
// // Channel是一个tree
// class Channel
// {
// public:
//   Channel() = default;
//   Channel()
// };
//
// // Voltage is a TBranch with a fixed name, title,
// template<double V> class Voltage : public TBranch
// {};

// 一个wave是含有1024个bin的TH1F，同时做好标定
#ifndef DATA_CLASS
#define DATA_CLASS

// #define to_char(s) (const char *)(s.data())


const char *to_char(string s)
{
  char *c = new char[s.size()];
  for(int i = 0; i < s . size(); i++)
  {
    c[i] = s[i];
  }
  return (const char *)(s.data());
}


class wave_data : public TH1F
{
public:
  wave_data() = default;
  wave_data(string name, string title);
  wave_data(string name, string title, vector<double> &wave);

  bool fill_wave(vector<double> wave);
  bool is_filled();

  void print();
  TCanvas* draw(TCanvas * c = NULL);

  ~wave_data() = default;

private:
  bool filled;

};

wave_data::wave_data(string name, string title):
TH1F((const char *)(name . data()), (const char *)(title . data()), 1024, 0, 1024), filled(false){}

wave_data::wave_data(string name, string title, vector<double> &wave):
TH1F((const char *)(name . data()), (const char *)(title . data()), 1024, 0, 1024)
{
  // cout << name . data() << endl << title . data() << endl;

  try
  {
    if(wave . size() != 1024)
    {
      range_error r("error: waveform size is " + to_string(wave.size()));
      throw r;
    }
    for(int i = 0; i < 1024; i++)
    {
      SetBinContent(i + 1, wave[i]);
    }
    filled = true;
  }
  catch (range_error &r)
  {
    cout << r . what() << endl;
    filled = false;
  }

}

bool wave_data::fill_wave(vector<double> wave)
{
  if(filled == true)
  {
    cout << "Wave has already been filled, refill it!" << endl;
  }
  if(wave . size() != 1024)
  {
    cout << "Error: Wrong input range" << endl;
    return false;
  }
  else
  {
    for(int i = 0; i < 1024; i++)
    {
      SetBinContent(i + 1, wave[i]);
    }
    filled = true;
    return true;
  }
}

bool wave_data::is_filled()
{
  return filled;
}

void wave_data::print()
{
  for(int i = 0; i < 1024; i++)
  {
    cout << i << "\t" << GetBinContent(i) << endl;
  }
}

TCanvas* wave_data::draw(TCanvas *c = NULL)
{
  if(c != NULL)
  {
    c -> cd();
    Draw();
  }
  else
  {
    string s1(GetName()), s2(GetTitle());
    s1 += "_c";
    s2 += "_Canvas";
    c = new TCanvas((const char*)(s1 . data()), (const char *)(s2 . data()), 1);
    c -> cd();
    Draw();
  }
  return c;
}



class Noise_FFT_Hist : public TH1D
{
public:
  Noise_FFT_Hist() = default;
  Noise_FFT_Hist(string name, string title):
  TH1D(to_char(name), to_char(title), 512, 0, 500e6)
  {}
  // wave_data(string name, string title, vector<double> &wave);
};

class Noise_Slope_Hist : public TH1F
{
public:
  Noise_Slope_Hist() = default;
  Noise_Slope_Hist(string name, string title):
  TH1F(to_char(name), to_char(title), 200, 0, 0.02)
  {}
};

class Noise_Ped_Hist : public TH1F
{
public:
  Noise_Ped_Hist() = default;
  Noise_Ped_Hist(string name, string title):
  TH1F(to_char(name), to_char(title), 10000, 1900, 2750)
  {}
};

class Signal_Charge_Hist : public TH1F
{
public:
  Signal_Charge_Hist() = default;
  Signal_Charge_Hist(string name, string title, double Calibration_Coefficience = 2.60925e-1 * 1e-9 * 1e-3 / 5):
  TH1F(to_char(name), to_char(title), 3000, -4000 * Calibration_Coefficience, 1000 * Calibration_Coefficience){}
};





#endif
