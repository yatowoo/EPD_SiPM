// For TMultiGraph visualization

#include<cstring>

int DrawUICurve(
  const char* fileName = "UICurve.root", 
  const char* mgName = "ui",
	const char* label_prefix = "CH_")
{
  TFile* file = new TFile(fileName,"UPDATE");
  TMultiGraph* mg = (TMultiGraph*)(file->Get(mgName));
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
    gr->Fit(fcnName.c_str(),"Q","",59,63);
    fcn->SetRange(53.,63.);
    fcn->Draw("same");
    fcn->Write(0,TObject::kOverwrite);
    lgd->AddEntry(gr,label.c_str());
  }

  lgd->Draw("same");
  lgd->Write(0,TObject::kOverwrite);
  mg->Write(0,TObject::kOverwrite);
  file->Save();
  return 0;
}