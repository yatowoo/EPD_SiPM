// For TMultiGraph visualization

#include<cstring>

int DrawUICurve(
  const char* fileName = "UICurve.root", 
  const char* mgName = "ui",
	const char* label_prefix = "CH-")
{
  TFile* file = new TFile(fileName,"UPDATE");
  TMultiGraph* mg = (TMultiGraph*)(file->Get(mgName));
  TLegend* lgd = new TLegend(0.16,0.45,0.53,0.84);
  lgd->SetNColumns(2);
  lgd->SetName("lgd");
  TList* grs = (TList*)(mg->GetListOfGraphs());
  for(int i = 0 ; i < grs->GetSize(); i++){
    TGraph* gr = (TGraph*)(grs->At(i));
    gr->SetLineColor(kOrange + i * 10);
    string label = label_prefix + to_string(i);
    gr->SetName(label.c_str());
    gr->Fit("pol3","","",59,63);
    lgd->AddEntry(gr,label.c_str());
  }
  mg->Draw("ALP");
  lgd->Draw("same");
  lgd->Write("lgd",TObject::kWriteDelete);
  mg->Write("ui",TObject::kWriteDelete);
  file->Save();
  return 0;
}