// Mainframe macro generated from application: /mnt/j/cpp/root/root_v6_08_06/bin/root.exe
// By ROOT version 6.08/06 on 2017-12-16 00:27:13

#include "TGDockableFrame.h"
#include "TGMenu.h"
#include "TGMdiDecorFrame.h"
#include "TG3DLine.h"
#include "TGMdiFrame.h"
#include "TGMdiMainFrame.h"
#include "TGMdiMenu.h"
#include "TGColorDialog.h"
#include "TGColorSelect.h"
#include "TGListBox.h"
#include "TGNumberEntry.h"
#include "TGScrollBar.h"
#include "TGComboBox.h"
#include "TGuiBldHintsEditor.h"
#include "TGuiBldNameFrame.h"
#include "TGFrame.h"
#include "TGFileDialog.h"
#include "TGShutter.h"
#include "TGButtonGroup.h"
#include "TGCanvas.h"
#include "TGFSContainer.h"
#include "TGFontDialog.h"
#include "TGuiBldEditor.h"
#include "TGButton.h"
#include "TGFSComboBox.h"
#include "TGLabel.h"
#include "TGMsgBox.h"
#include "TRootGuiBuilder.h"
#include "TGTab.h"
#include "TGListView.h"
#include "TGSplitter.h"
#include "TGStatusBar.h"
#include "TGListTree.h"
#include "TGuiBldGeometryFrame.h"
#include "TGToolTip.h"
#include "TGToolBar.h"
#include "TRootEmbeddedCanvas.h"
#include "TCanvas.h"
#include "TGuiBldDragManager.h"

#include "Riostream.h"

TGMainFrame* fgMainFrame = NULL;
// User Interface
  // IO
TGNumberEntry *fgNumTestID = NULL;
TGTextEntry *fgTextPath = NULL;
  // FEE
TGTextEntry *fgTextFEENo = NULL;
TGNumberEntry *fgNumVset = NULL;
TGNumberEntry *fgNumVslope = NULL;
TGNumberEntry *fgNumDAC = NULL;
TGNumberEntry *fgNumUIVstart = NULL;
TGNumberEntry *fgNumUIVstop = NULL;
TGNumberEntry *fgNumUIVstep = NULL;
  // DGTZ
TGTextEntry *fgTextDGTZInfo = NULL;
TGNumberEntry *fgNumDGTZTime = NULL;
  // Analyzer
TGTextButton *fgButtonUI = NULL;
TGTextButton *fgButtonProduce = NULL;
TGTextButton *fgButtonSlope = NULL;
TGTextButton *fgButtonGain = NULL;
TGTextButton *fgButtonVb = NULL;
  // Controller
TGTextButton *fgButtonCheck = NULL;
TGTextButton *fgButtonStart = NULL;
TGTextButton *fgButtonSave = NULL;
void MonitorBuilder()
{

   // main frame
   fgMainFrame = new TGMainFrame(gClient->GetRoot(),324,445,kMainFrame | kVerticalFrame);
   fgMainFrame->SetWindowName("EPD SiPM Test @ USTC");
   fgMainFrame->SetName("fgMF");
   fgMainFrame->SetLayoutBroken(kTRUE);

/* 
  vertical frame - Program IO
*/
   TGVerticalFrame *fVerticalFrame560 = new TGVerticalFrame(fgMainFrame,320,85,kVerticalFrame | kSunkenFrame);
   fVerticalFrame560->SetName("fgVFIO");
   fVerticalFrame560->SetLayoutBroken(kTRUE);

   TGFont *ufont;         // will reflect user font changes
   ufont = gClient->GetFont("-*-helvetica-bold-r-*-*-14-*-*-*-*-*-*-*");

   TGGC   *uGC;           // will reflect user GC changes
   // graphics context changes
   GCValues_t vall663;
   vall663.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",vall663.fForeground);
   gClient->GetColorByName("#e8e8e8",vall663.fBackground);
   vall663.fFillStyle = kFillSolid;
   vall663.fFont = ufont->GetFontHandle();
   vall663.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall663, kTRUE);
   TGLabel *fLabel663 = new TGLabel(fVerticalFrame560,"Program IO",uGC->GetGC(),ufont->GetFontStruct());
   fLabel663->SetTextJustify(36);
   fLabel663->SetMargins(0,0,0,0);
   fLabel663->SetWrapLength(-1);
   fVerticalFrame560->AddFrame(fLabel663, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel663->MoveResize(2,2,80,18);
   TGLabel *fLabel664 = new TGLabel(fVerticalFrame560,"Test ID");
   fLabel664->SetTextJustify(36);
   fLabel664->SetMargins(0,0,0,0);
   fLabel664->SetWrapLength(-1);
   fVerticalFrame560->AddFrame(fLabel664, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel664->MoveResize(2,26,39,16);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valEntry665;
   valEntry665.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry665.fForeground);
   gClient->GetColorByName("#e8e8e8",valEntry665.fBackground);
   valEntry665.fFillStyle = kFillSolid;
   valEntry665.fFont = ufont->GetFontHandle();
   valEntry665.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry665, kTRUE);
   fgNumTestID = new TGNumberEntry(fVerticalFrame560, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fgNumTestID->SetNumber(0);
   fgNumTestID->Resize(100,fgNumTestID->GetDefaultHeight());
   fVerticalFrame560->AddFrame(fgNumTestID, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgNumTestID->MoveResize(124,26,100,22);
   TGLabel *fLabel666 = new TGLabel(fVerticalFrame560,"Path");
   fLabel666->SetTextJustify(36);
   fLabel666->SetMargins(0,0,0,0);
   fLabel666->SetWrapLength(-1);
   fVerticalFrame560->AddFrame(fLabel666, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel666->MoveResize(2,50,25,16);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valEntry667;
   valEntry667.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry667.fForeground);
   gClient->GetColorByName("#e8e8e8",valEntry667.fBackground);
   valEntry667.fFillStyle = kFillSolid;
   valEntry667.fFont = ufont->GetFontHandle();
   valEntry667.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry667, kTRUE);
   fgTextPath = new TGTextEntry(fVerticalFrame560, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground);
   fgTextPath->SetMaxLength(4096);
   fgTextPath->SetAlignment(kTextLeft);
   fgTextPath->SetText("..");
   fgTextPath->Resize(100,fgTextPath->GetDefaultHeight());
   fVerticalFrame560->AddFrame(fgTextPath, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgTextPath->MoveResize(124,50,100,22);

   fgMainFrame->AddFrame(fVerticalFrame560, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fVerticalFrame560->MoveResize(1,1,320,85);

/* 
  vertical frame - FEE
*/
   TGVerticalFrame *fVerticalFrame1662 = new TGVerticalFrame(fgMainFrame,320,96,kVerticalFrame | kSunkenFrame);
   fVerticalFrame1662->SetName("fgVFFEE");
   fVerticalFrame1662->SetLayoutBroken(kTRUE);

   ufont = gClient->GetFont("-*-helvetica-bold-r-*-*-14-*-*-*-*-*-*-*");

   // graphics context changes
   GCValues_t vall669;
   vall669.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",vall669.fForeground);
   gClient->GetColorByName("#e8e8e8",vall669.fBackground);
   vall669.fFillStyle = kFillSolid;
   vall669.fFont = ufont->GetFontHandle();
   vall669.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall669, kTRUE);
   TGLabel *fLabel669 = new TGLabel(fVerticalFrame1662,"FEE",uGC->GetGC(),ufont->GetFontStruct());
   fLabel669->SetTextJustify(36);
   fLabel669->SetMargins(0,0,0,0);
   fLabel669->SetWrapLength(-1);
   fVerticalFrame1662->AddFrame(fLabel669, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel669->MoveResize(2,2,30,18);
   TGLabel *fLabel670 = new TGLabel(fVerticalFrame1662,"Serial No.");
   fLabel670->SetTextJustify(36);
   fLabel670->SetMargins(0,0,0,0);
   fLabel670->SetWrapLength(-1);
   fVerticalFrame1662->AddFrame(fLabel670, new TGLayoutHints(kLHintsNormal));
   fLabel670->MoveResize(9,23,55,16);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valEntry671;
   valEntry671.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry671.fForeground);
   gClient->GetColorByName("#e8e8e8",valEntry671.fBackground);
   valEntry671.fFillStyle = kFillSolid;
   valEntry671.fFont = ufont->GetFontHandle();
   valEntry671.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry671, kTRUE);

   ULong_t ucolor;        // will reflect user color changes
   gClient->GetColorByName("#e8e8e8",ucolor);
   fgTextFEENo = new TGTextEntry(fVerticalFrame1662, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground,ucolor);
   fgTextFEENo->SetMaxLength(4096);
   fgTextFEENo->SetAlignment(kTextLeft);
   fgTextFEENo->SetText("#0x0");
   fgTextFEENo->Resize(99,fgTextFEENo->GetDefaultHeight());
   fVerticalFrame1662->AddFrame(fgTextFEENo, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgTextFEENo->MoveResize(100,23,128,22);
   TGLabel *fLabel672 = new TGLabel(fVerticalFrame1662,"Vset");
   fLabel672->SetTextJustify(36);
   fLabel672->SetMargins(0,0,0,0);
   fLabel672->SetWrapLength(-1);
   fVerticalFrame1662->AddFrame(fLabel672, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel672->MoveResize(5,45,30,16);
   TGLabel *fLabel673 = new TGLabel(fVerticalFrame1662,"UI Curve");
   fLabel673->SetTextJustify(36);
   fLabel673->SetMargins(0,0,0,0);
   fLabel673->SetWrapLength(-1);
   fVerticalFrame1662->AddFrame(fLabel673, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel673->MoveResize(10,67,62,16);
   fgNumVset = new TGNumberEntry(fVerticalFrame1662, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fgNumVset->SetName("fgNumVset");
   fgNumVset->SetNumber(60.);
   fVerticalFrame1662->AddFrame(fgNumVset, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgNumVset->MoveResize(35,45,64,22);

   TGLabel *fLabelDAC = new TGLabel(fVerticalFrame1662,"DAC");
   fLabelDAC->SetTextJustify(36);
   fLabelDAC->SetMargins(0,0,0,0);
   fLabelDAC->SetWrapLength(-1);
   fVerticalFrame1662->AddFrame(fLabelDAC, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabelDAC->MoveResize(120,47,30,16);

   fgNumDAC = new TGNumberEntry(fVerticalFrame1662, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fgNumDAC->SetName("fgNumDAC");
   fgNumDAC->SetNumber(0.);
   fVerticalFrame1662->AddFrame(fgNumDAC, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgNumDAC->MoveResize(160,45,64,22);   
   
   TGTextButton* fgButtonFEESet = new TGTextButton(fVerticalFrame1662,"SET",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fgButtonFEESet->SetTextJustify(36);
   fgButtonFEESet->SetMargins(0,0,0,0);
   fgButtonFEESet->SetWrapLength(-1);
   fgButtonFEESet->Resize(80,22);
   fVerticalFrame1662->AddFrame(fgButtonFEESet, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgButtonFEESet->MoveResize(240,45,30,22);
   fgButtonFEESet->SetCommand("DoFEESet()");

   fgNumUIVstart = new TGNumberEntry(fVerticalFrame1662, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fgNumUIVstart->SetName("fgNumUIVstart");
   fVerticalFrame1662->AddFrame(fgNumUIVstart, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgNumUIVstart->MoveResize(100,67,64,22);
   fgNumUIVstart->SetNumber(53.);

   fgNumUIVstop = new TGNumberEntry(fVerticalFrame1662, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fgNumUIVstop->SetName("fgNumUIVstop");
   fVerticalFrame1662->AddFrame(fgNumUIVstop, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgNumUIVstop->MoveResize(167,67,64,22);
   fgNumUIVstop->SetNumber(63.);
   
   fgNumUIVstep = new TGNumberEntry(fVerticalFrame1662, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fgNumUIVstep->SetName("fgNumUIVstep");
   fVerticalFrame1662->AddFrame(fgNumUIVstep, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgNumUIVstep->MoveResize(234,67,64,22);
   fgNumUIVstep->SetNumber(0.5);

   fgMainFrame->AddFrame(fVerticalFrame1662, new TGLayoutHints(kLHintsExpandX));
   fVerticalFrame1662->MoveResize(1,86,320,96);

/*
  vertical frame - DGTZ
*/
   TGVerticalFrame *fVerticalFrame1682 = new TGVerticalFrame(fgMainFrame,320,88,kVerticalFrame | kSunkenFrame);
   fVerticalFrame1682->SetName("fgVFFEE");
   fVerticalFrame1682->SetLayoutBroken(kTRUE);

   ufont = gClient->GetFont("-*-helvetica-bold-r-*-*-14-*-*-*-*-*-*-*");

   // graphics context changes
   GCValues_t vall691;
   vall691.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",vall691.fForeground);
   gClient->GetColorByName("#e8e8e8",vall691.fBackground);
   vall691.fFillStyle = kFillSolid;
   vall691.fFont = ufont->GetFontHandle();
   vall691.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall691, kTRUE);
   TGLabel *fLabel691 = new TGLabel(fVerticalFrame1682,"DGTZ",uGC->GetGC(),ufont->GetFontStruct());
   fLabel691->SetTextJustify(36);
   fLabel691->SetMargins(0,0,0,0);
   fLabel691->SetWrapLength(-1);
   fVerticalFrame1682->AddFrame(fLabel691, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel691->MoveResize(2,3,39,18);
   TGLabel *fLabel692 = new TGLabel(fVerticalFrame1682,"Type");
   fLabel692->SetTextJustify(36);
   fLabel692->SetMargins(5,0,0,0);
   fLabel692->SetWrapLength(-1);
   fVerticalFrame1682->AddFrame(fLabel692, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel692->MoveResize(2,31,40,16);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valEntry980;
   valEntry980.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry980.fForeground);
   gClient->GetColorByName("#e8e8e8",valEntry980.fBackground);
   valEntry980.fFillStyle = kFillSolid;
   valEntry980.fFont = ufont->GetFontHandle();
   valEntry980.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry980, kTRUE);

   fgTextDGTZInfo = new TGTextEntry(fVerticalFrame1682, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground,ucolor);
   fgTextDGTZInfo->SetMaxLength(4096);
   fgTextDGTZInfo->SetAlignment(kTextLeft);
   fgTextDGTZInfo->SetText("Unknown");
   fgTextDGTZInfo->Resize(88,fgTextDGTZInfo->GetDefaultHeight());
   fVerticalFrame1682->AddFrame(fgTextDGTZInfo, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgTextDGTZInfo->MoveResize(128,31,88,22);
   TGLabel *fLabel989 = new TGLabel(fVerticalFrame1682,"Sampling Time(s)");
   fLabel989->SetTextJustify(36);
   fLabel989->SetMargins(0,0,0,0);
   fLabel989->SetWrapLength(-1);
   fVerticalFrame1682->AddFrame(fLabel989, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel989->MoveResize(2,59,100,16);

   // vertical frame - Sampling Time
   TGVerticalFrame *fVerticalFrame1260 = new TGVerticalFrame(fVerticalFrame1682,80,24,kVerticalFrame);
   fVerticalFrame1260->SetName("fVerticalFrame1260");
   fgNumDGTZTime = new TGNumberEntry(fVerticalFrame1260, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fgNumDGTZTime->SetName("fgNumDGTZTime");
   fVerticalFrame1260->AddFrame(fgNumDGTZTime, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgNumDGTZTime->SetNumber(15);
   TGLabel *fLabel1279 = new TGLabel(fVerticalFrame1260,"(s)");
   fLabel1279->SetTextJustify(36);
   fLabel1279->SetMargins(0,0,0,0);
   fLabel1279->SetWrapLength(-1);
   fVerticalFrame1260->AddFrame(fLabel1279, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));

   fVerticalFrame1682->AddFrame(fVerticalFrame1260, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fVerticalFrame1260->MoveResize(128,59,80,24);

   fgMainFrame->AddFrame(fVerticalFrame1682, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fVerticalFrame1682->MoveResize(1,184,320,88);

/* 
  vertical frame - Analyzer
*/
   TGVerticalFrame *fVerticalFrame1410 = new TGVerticalFrame(fgMainFrame,320,80,kVerticalFrame | kSunkenFrame);
   fVerticalFrame1410->SetName("fgVFAnayzer");
   fVerticalFrame1410->SetLayoutBroken(kTRUE);

   ufont = gClient->GetFont("-*-helvetica-bold-r-*-*-14-*-*-*-*-*-*-*");

   // graphics context changes
   GCValues_t vall1597;
   vall1597.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",vall1597.fForeground);
   gClient->GetColorByName("#e8e8e8",vall1597.fBackground);
   vall1597.fFillStyle = kFillSolid;
   vall1597.fFont = ufont->GetFontHandle();
   vall1597.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall1597, kTRUE);
   TGLabel *fLabel1597 = new TGLabel(fVerticalFrame1410,"Analyzer",uGC->GetGC(),ufont->GetFontStruct());
   fLabel1597->SetTextJustify(36);
   fLabel1597->SetMargins(0,0,0,0);
   fLabel1597->SetWrapLength(-1);
   fVerticalFrame1410->AddFrame(fLabel1597, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1597->MoveResize(2,3,59,18);
   fgButtonUI = new TGTextButton(fVerticalFrame1410,"UI Curve",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fgButtonUI->SetTextJustify(36);
   fgButtonUI->SetMargins(0,0,0,0);
   fgButtonUI->SetWrapLength(-1);
   fgButtonUI->Resize(80,22);
   fVerticalFrame1410->AddFrame(fgButtonUI, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgButtonUI->MoveResize(4,27,80,22);
   fgButtonUI->SetCommand("TestUICurve()");
   
   fgButtonVb = new TGTextButton(fVerticalFrame1410,"V Breakdown",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fgButtonVb->SetTextJustify(36);
   fgButtonVb->SetMargins(0,0,0,0);
   fgButtonVb->SetWrapLength(-1);
   fgButtonVb->Resize(80,22);
   fVerticalFrame1410->AddFrame(fgButtonVb, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fgButtonVb->MoveResize(101,27,80,22);
   fgButtonVb->SetCommand("DoProcessUICurve()");

   fgMainFrame->AddFrame(fVerticalFrame1410, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fVerticalFrame1410->MoveResize(1,276,320,80);

/*
  vertical frame - Controller
*/
   TGVerticalFrame *fVerticalFrame2090 = new TGVerticalFrame(fgMainFrame,320,82,kVerticalFrame | kSunkenFrame);
   fVerticalFrame2090->SetName("fVerticalFrame2090");
   fVerticalFrame2090->SetLayoutManager(new TGMatrixLayout(fVerticalFrame2090,3,1,2,0));
   fVerticalFrame2090->SetLayoutBroken(kTRUE);

   ufont = gClient->GetFont("-*-helvetica-bold-r-*-*-17-*-*-*-*-*-*-*");

   // graphics context changes
   GCValues_t valButton2206;
   valButton2206.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#ffffff",valButton2206.fForeground);
   gClient->GetColorByName("#e8e8e8",valButton2206.fBackground);
   valButton2206.fFillStyle = kFillSolid;
   valButton2206.fFont = ufont->GetFontHandle();
   valButton2206.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valButton2206, kTRUE);

   gClient->GetColorByName("#00ffcc",ucolor);
   fgButtonCheck = new TGTextButton(fVerticalFrame2090,"Check",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
   fgButtonCheck->SetTextJustify(36);
   fgButtonCheck->SetMargins(0,0,0,0);
   fgButtonCheck->SetWrapLength(-1);
   fgButtonCheck->Resize(320,24);
   fgButtonCheck->ChangeBackground(ucolor);
   fVerticalFrame2090->AddFrame(fgButtonCheck, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsExpandX,2,2,2,2));
   fgButtonCheck->MoveResize(2,3,320,24);
   fgButtonCheck->SetCommand("DoCheck()");

   ufont = gClient->GetFont("-*-helvetica-bold-r-*-*-17-*-*-*-*-*-*-*");

   // graphics context changes
   GCValues_t valButton2236;
   valButton2236.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valButton2236.fForeground);
   gClient->GetColorByName("#e8e8e8",valButton2236.fBackground);
   valButton2236.fFillStyle = kFillSolid;
   valButton2236.fFont = ufont->GetFontHandle();
   valButton2236.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valButton2236, kTRUE);

   gClient->GetColorByName("#ff0000",ucolor);
   fgButtonStart = new TGTextButton(fVerticalFrame2090,"START",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
   fgButtonStart->SetTextJustify(36);
   fgButtonStart->SetMargins(0,0,0,0);
   fgButtonStart->SetWrapLength(-1);
   fgButtonStart->Resize(320,22);
   fgButtonStart->ChangeBackground(ucolor);
   fVerticalFrame2090->AddFrame(fgButtonStart, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsExpandX,2,2,2,2));
   fgButtonStart->MoveResize(2,29,320,22);
   fgButtonStart->SetCommand("DoStart()");

   ufont = gClient->GetFont("-*-helvetica-bold-r-*-*-17-*-*-*-*-*-*-*");

   // graphics context changes
   GCValues_t valButton2277;
   valButton2277.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valButton2277.fForeground);
   gClient->GetColorByName("#e8e8e8",valButton2277.fBackground);
   valButton2277.fFillStyle = kFillSolid;
   valButton2277.fFont = ufont->GetFontHandle();
   valButton2277.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valButton2277, kTRUE);

   gClient->GetColorByName("#ffffff",ucolor);
   fgButtonSave = new TGTextButton(fVerticalFrame2090,"Save",-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame);
   fgButtonSave->SetTextJustify(36);
   fgButtonSave->SetMargins(0,0,0,0);
   fgButtonSave->SetWrapLength(-1);
   fgButtonSave->Resize(320,22);
   fgButtonSave->SetState(kButtonDown);
   gClient->GetColorByName("#ffffff",ucolor);
   fgButtonSave->ChangeBackground(ucolor);
   fVerticalFrame2090->AddFrame(fgButtonSave, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsExpandX,2,2,2,2));
   fgButtonSave->MoveResize(2,55,320,22);
   fgButtonSave->SetCommand("DoSave()");

// Render MainFrame
   fgMainFrame->AddFrame(fVerticalFrame2090, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fVerticalFrame2090->MoveResize(1,360,320,82);

   fgMainFrame->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fgMainFrame->MapSubwindows();

   fgMainFrame->Resize(fgMainFrame->GetDefaultSize());
   fgMainFrame->MapWindow();
   fgMainFrame->Resize(324,445);
}

/*
* EPD FEE Driver
* TODO: Wrapped as C++ Class
*/
#include "EPDFEE.h"

uint64_t owaddr = 0x3800000007EA673AULL; // DS2413 adapter #1 for new FEE testing
struct linkusb_dev linkusb;
uint64_t serial;
int swaddr = 0; // address on the switch on this FEE (or can loop over a set of them)
const int N_SIPM = 16;

// Check FEE link status, get serial number
uint64_t CheckFEE()
{
  if (linkusb_open(&linkusb, 0))
    return -1; // error messages in linkusb_open

  EPD_connect_FEE(&linkusb, owaddr, swaddr); // connect to FEE at switch address 0
  DS28CM00_read(&linkusb, owaddr, &serial);
  printf("[-] CHECK - FEE %d serial number: 0x%016llx\n", swaddr, serial);

  EPD_disconnect_FEE(&linkusb, owaddr);
  linkusb_close(&linkusb);
  return serial;
}

// FEE initial setup
int SetFEE(double _voltage = 55.0, double _vslope = 0.054, int _pedestal = 0)
{
  // LOG
  cout << "[-] FEE - Initial setup : vset="<< _voltage
    << " vslope=" << _vslope << " pedestal=" << _pedestal << endl;
  
  // Open FEE LinkUSB Interface
  if (linkusb_open(&linkusb, 0))
    return -1; // error messages in linkusb_open
  EPD_connect_FEE(&linkusb, owaddr, swaddr); // connect to FEE at switch address 0
  
  //EPD quick first tests
  for (int k = 0; k < N_SIPM; k++)
    EPD_set_voltage(&linkusb, owaddr, k, _voltage); //hacked for offset test 7/2 put it back!!  56.5);//57);
  EPD_set_vslope(&linkusb, owaddr, _vslope);
  for (int k = 0; k < N_SIPM; k++)
    EPD_set_ped(&linkusb, owaddr, k, _pedestal);
  // Close FEE connect
  EPD_disconnect_FEE(&linkusb, owaddr);
  linkusb_close(&linkusb);
  return 0;
}

int SetVoltage(double _vset)
{
  // LOG
  cout << "[-] FEE - Set voltage : " << _vset << endl;

  // Open FEE LinkUSB Interface
  if (linkusb_open(&linkusb, 0))
    return -1; // error messages in linkusb_open
  EPD_connect_FEE(&linkusb, owaddr, swaddr); // connect to FEE at switch address 0
  for(int ch = 0 ; ch < N_SIPM ; ch++)
      EPD_set_voltage(&linkusb, owaddr, ch, _vset);
  // Close FEE connect
  EPD_disconnect_FEE(&linkusb, owaddr);
  linkusb_close(&linkusb);  
  return 0;
}

int SetDAC(int _pedestal)
{
  // LOG
  cout << "[-] FEE - Set pedestal : " << _pedestal << endl;

  // Open FEE LinkUSB Interface
  if (linkusb_open(&linkusb, 0))
    return -1; // error messages in linkusb_open
  EPD_connect_FEE(&linkusb, owaddr, swaddr); // connect to FEE at switch address 0
  for(int ch = 0 ; ch < N_SIPM ; ch++)
      EPD_set_ped(&linkusb, owaddr, ch, _pedestal);
  // Close FEE connect
  EPD_disconnect_FEE(&linkusb, owaddr);
  linkusb_close(&linkusb);  
  return 0;
}

/*
* DGTZ Manager (@call WaveDump)
* TODO : ADD log output/print
*/
#include "TSystem.h"
#include "TThread.h"
// Controlled by TThread
//  [TODO] Implemented with CAEN DGTZ/WaveDump Library
void* OpenDGTZ(void* _PATH){
  char cmd[256] = "";
  sprintf(cmd,"%s%s%s",
    "cd ", (const char*)_PATH,
    ";/usr/local/bin/wavedump <$OLDPWD/tmp;");
  TString log = gSystem->GetFromPipe(cmd);
  return NULL;
}
int ReadDGTZ(const char* _PATH=".", int _samplingTime = 5000){
  cout << "[-] DGTZ - Read and Write data into " << _PATH 
    << " for " << _samplingTime/1000. << " second(s)" << endl;

  const int BUUFFER_TIME = 2000; // Prepare buffer data for writing
  TThread* th = new TThread("dgtz",OpenDGTZ);
  gSystem->Exec("echo >tmp");
  th->Run((void*)_PATH);
  gSystem->Exec("echo s >>tmp"); // Start acquisition
  gSystem->Sleep(BUUFFER_TIME); // milliSec
  gSystem->Exec("echo W >>tmp");  // Start continuous writing
  gSystem->Sleep(_samplingTime); // milliSec
  gSystem->Exec("echo s >>tmp");  // Stop acquisitio
  gSystem->Exec("echo q >>tmp");  // Quit
  th->Kill();
  th->Delete();th = NULL;

  cout << "[-] DGTZ - Read over" << endl;
  return 0;
}
TString CheckDGTZ(){
  gSystem->Exec("echo q >tmp");
  TString model =
    gSystem->GetFromPipe("/usr/local/bin/wavedump <tmp | sed -n 's/.*Model\\ \\(.*\\)/\\1/p'");
  // CHECK
  if(model.Length() < 1){
    cout << "[X] CHECK - DGTZ Not Connected!" << endl;
    return "NULL";
  }
  else
    cout << "[-] CHECK - DGTZ Model : " << model << endl;

  return model;
}

/** 
 * GUI Actions
 */
const double VSET_MAX = 63.1;
const double VSTEP_MIN = 0.01;
bool CheckUICurveParams(double _vStart, double _vStop, double _vStep)
{
  return (
    (_vStart < _vStop) && (_vStop < VSET_MAX) && (_vStep >= VSTEP_MIN)
  );
}
#include "TMultiGraph.h"
#include "TGraph.h"
TMultiGraph* mg = NULL;
int TestUICurve()
{
  double _vStart = fgNumUIVstart->GetNumber();
  double _vStop = fgNumUIVstop->GetNumber();
  double _vStep = fgNumUIVstep->GetNumber();
  cout << "[-] Test - Processing UI curve test - setup=(" 
    << _vStart << "," << _vStop << "," << _vStep << ")"
    << endl;
  if(!CheckUICurveParams(_vStart,_vStop,_vStep)){
    cout << "[-] ERROR - UI Curve - Invalid input params." << endl;
    return -1;
  }

  const int N_VOLTAGE_PTS = (_vStop - _vStart) / _vStep + 1;
  double vset[N_VOLTAGE_PTS];
  double imon[N_SIPM][N_VOLTAGE_PTS];
  
  // Open FEE LinkUSB Interface
  if (linkusb_open(&linkusb, 0))
    return -1; // error messages in linkusb_open
  EPD_connect_FEE(&linkusb, owaddr, swaddr); // connect to FEE at switch address 0
  for(int i = 0; i < N_VOLTAGE_PTS; i++)
  {
    vset[i]= _vStart + i * _vStep;
    for(int ch = 0 ; ch < N_SIPM ; ch++)
      EPD_set_voltage(&linkusb, owaddr, ch, vset[i]);
    for(int ch = 0 ; ch < N_SIPM ; ch++){
      imon[ch][i] = EPD_get_imon(&linkusb, owaddr, ch);
      cout << "[-] Test - UI Curve - Channel " << ch << " current = " << imon[ch][i] << endl;
    }
  }
  // Close FEE connect
  EPD_disconnect_FEE(&linkusb, owaddr);
  linkusb_close(&linkusb);
  if(mg){
    delete mg;
    mg = NULL;
  }
  mg = new TMultiGraph("ui","UI Curve of SiPM");
  TGraph *ui[N_SIPM];
  for(int ch = 0 ; ch < N_SIPM ; ch++)
  {
    ui[ch] = new TGraph(N_VOLTAGE_PTS, vset, imon[ch]);
    mg->Add(ui[ch]);
  }
  return 0;
}
void DoFEESet()
{
  double vset = fgNumVset->GetNumber();
  if( (vset < 0) || (vset > VSET_MAX)){
    cout << "[-] ERROR - FEE - Invalid bias voltage" << endl;
    return;
  }
  SetFEE(vset);
  return;
}
char dir[256];
char cmd[256];
void DoCheck()
{
  char FEENo[256];
  sprintf(FEENo,"0x%016llx",CheckFEE());
  fgTextFEENo->SetText(FEENo);

  fgTextDGTZInfo->SetText(CheckDGTZ());

  sprintf(dir,"%s/B%d",fgTextPath->GetText(),int(fgNumTestID->GetNumber()));
  sprintf(cmd,"mkdir -p %s",dir);
  cout << "[-] EXEC - " << cmd << endl;
  gSystem->Exec(cmd);
}
#include "Process/Control_Class_numbers.cpp"
void DoStart()
{
  if(strlen(dir) == 0){
    cout << "[-] ERROR - Please 'Check' first" << endl;
    return;
  }
  char path[256];
  const char* cmd_head = "mkdir -p ";
  int dac[3] = {-127,127,0};
  // TODO : REPLACE with GUI entry
  double vset_noise = 46.5;
  double vset_signal = 60.;
  
  // Test DAC
  cout << "[-] Test - Processing DAC test" << endl;
  SetVoltage(vset_noise);
  for(int i = 0 ; i < 3 ; i++){
    sprintf(path,"%s/DAC_%d_%dV",dir,dac[i],int(vset_noise));
    sprintf(cmd,"%s%s",cmd_head,path);
    gSystem->Exec(cmd);
    cout << "[-] EXEC - " << cmd << endl;

    SetDAC(dac[i]);
    ReadDGTZ(path,fgNumDGTZTime->GetNumber()*1000);
  }

  // Test Signal
  cout << "[-] Test - Processing Signal test" << endl;
  sprintf(path,"%s/%dV",dir,int(vset_signal));
  sprintf(cmd,"%s%s",cmd_head,path);
  gSystem->Exec(cmd);
  cout << "[-] EXEC - " << cmd << endl;

  SetVoltage(vset_signal);
  ReadDGTZ(path,fgNumDGTZTime->GetNumber()*1000);
  cout << "[-] Test - Signal test completed." << endl;
  
  // Analyzer
  sprintf(cmd, "rm -rf %s/46V; mv -f %s/DAC_0_46V %s/46V", dir, dir, dir);
  gSystem -> Exec(cmd);
  cout << "[-] EXEC - " << cmd << endl;

  Board_Control* bdc = new Board_Control(fgTextPath->GetText(),int(fgNumTestID->GetNumber()));
  bdc -> Start();
  if(mg)
    bdc -> Write_Other_Object(mg);
}
void DoSave()
{
  char path[256];
  sprintf(path,"%s/B%d/%s",fgTextPath->GetText(),int(fgNumTestID->GetNumber()),"UICurve.root");
  if(mg)
    mg->SaveAs(path);
  else
    cout << "[X] WARNNING - No data." << endl;
}
// @see script/DrawUICurve.C
int DoProcessUICurve(){
  cout << "[-] Analyzer - Process UI curve - START " << endl;

  if(!mg){
    string fileName = string(dir) + string("/UICurve.root");
    TFile* file = new TFile(fileName.c_str());
    if(file->IsOpen())
      mg = (TMultiGraph*)(file->Get("ui"));
  }
  if(!mg){
    cout << "[-] ERROR - Analyzer - UI curve dosen't exist. " << endl;
    return -1;
  }
  mg->Draw("ALP");

  TLegend* lgd = new TLegend(0.16,0.45,0.53,0.84);
  lgd->SetNColumns(2);
  lgd->SetName("lgd");
  lgd->SetShadowColor(kWhite);
  const char* label_prefix = "CH_";

  TList* grs = (TList*)(mg->GetListOfGraphs());
  for(int i = 0 ; i < grs->GetSize(); i++){
    TGraph* gr = (TGraph*)(grs->At(i));
    gr->SetLineColor(kOrange + i * 5);
    string label = label_prefix + to_string(i);
    gr->SetName(label.c_str());
    
    string fcnName = "fit" + to_string(i);
    const char* formula = "pol1";
    TF1* fcn = new TF1(fcnName.c_str(), formula, 53., 63.);
    gr->Fit(fcnName.c_str(),"Q","",59,63);
    fcn->SetRange(53.,63.);
    fcn->Draw("same");
    cout << "\t[-] Analyzer - Vbr~" << setprecision(1) << fixed << fcn->GetX(0.) << "V - fit with " << formula << endl;

    lgd->AddEntry(gr,label.c_str());
  }
  lgd->Draw("same");
  cout << "[-] Analyzer - Process UI curve - OVER" << endl;
  
  return 0;  
}

int main(int argc, char* argv[])
{
  MonitorBuilder();
  CheckFEE();
  SetFEE();
  CheckDGTZ();
  return 0;
}
