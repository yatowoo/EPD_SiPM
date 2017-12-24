// For TMultiGraph visualization

#include<cstring>

const double CURRENT_BASE = 0.02; // uA
double FindInflection(TGraph* gr)
{
  double v_inflection = 53.;
  double* vset = gr->GetX();
  double* imon = gr->GetY();
  for(int i = 0 ; i < gr->GetN() ; i ++){
    if((imon[i] > CURRENT_BASE) && (imon[i] > imon[0])){
      cout << "[-] Test - Inflection found : " << gr->GetName() << " at " << vset[i-1] << endl;
      return vset[i-1];
    }
  }
  return 0.;
}

bool DrawUICurve(
  TMultiGraph* mg,
	const char* label_prefix = "CH_")
{
  if(!mg){
    cout << "[X] ERROR - Fail to find TMultiGraph." << endl;
    return false;
  }

  mg->Draw("ALP");

  TLegend* lgd = new TLegend(0.16,0.45,0.53,0.84);
  lgd->SetNColumns(2);
  lgd->SetName("lgd");
  lgd->SetShadowColor(kWhite);
  TList* grs = (TList*)(mg->GetListOfGraphs());
  for(int i = 0 ; i < grs->GetSize(); i++){
    TGraph* gr = (TGraph*)(grs->At(i));
    gr->SetLineColor(kOrange + i * 5);
    string label = label_prefix + to_string(i);
    gr->SetName(label.c_str());
    string fcnName = "fit" + to_string(i);
    TF1* fcn = new TF1(fcnName.c_str(), "pol3", 53., 63.);
    gr->Fit(fcnName.c_str(),"Q","",FindInflection(gr),63);
    fcn->SetRange(53.,63.);
    fcn->Draw("same");
    lgd->AddEntry(gr,label.c_str());
  }

  lgd->Draw("same");

  return true;
}

int UICurve(  const char* fileName = "UICurve.root", 
  const char* mgName = "ui",
	const char* label_prefix = "CH_")
{
  TFile* file = new TFile(fileName,"UPDATE");
  TMultiGraph* mg = (TMultiGraph*)(file->Get(mgName));
  if(!DrawUICurve(mg)){
    return -1;
  }
  mg->Write(0,TObject::kOverwrite);
  file->Save();
  return 0;
}