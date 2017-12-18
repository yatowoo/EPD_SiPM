// Mainframe macro generated from application: /mnt/j/cpp/root/root_v6_08_06/bin/root.exe
// By ROOT version 6.08/06 on 2017-12-16 00:27:13

#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGMdiDecorFrame
#include "TGMdiDecorFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGMdiFrame
#include "TGMdiFrame.h"
#endif
#ifndef ROOT_TGMdiMainFrame
#include "TGMdiMainFrame.h"
#endif
#ifndef ROOT_TGMdiMenu
#include "TGMdiMenu.h"
#endif
#ifndef ROOT_TGColorDialog
#include "TGColorDialog.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGuiBldHintsEditor
#include "TGuiBldHintsEditor.h"
#endif
#ifndef ROOT_TGuiBldNameFrame
#include "TGuiBldNameFrame.h"
#endif
#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGShutter
#include "TGShutter.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGFontDialog
#include "TGFontDialog.h"
#endif
#ifndef ROOT_TGuiBldEditor
#include "TGuiBldEditor.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGMsgBox
#include "TGMsgBox.h"
#endif
#ifndef ROOT_TRootGuiBuilder
#include "TRootGuiBuilder.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGuiBldGeometryFrame
#include "TGuiBldGeometryFrame.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TRootEmbeddedCanvas
#include "TRootEmbeddedCanvas.h"
#endif
#ifndef ROOT_TCanvas
#include "TCanvas.h"
#endif
#ifndef ROOT_TGuiBldDragManager
#include "TGuiBldDragManager.h"
#endif

#include "Riostream.h"

void MonitorBuilder()
{

  // main frame
  TGMainFrame *fMainFrame2933 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   fMainFrame2933->SetWindowName("EPD SiPM Test @ USTC");
   fMainFrame2933->SetName("fMainFrame2933");
   fMainFrame2933->SetLayoutBroken(kTRUE);

   // composite frame
   TGCompositeFrame *fMainFrame2028 = new TGCompositeFrame(fMainFrame2933,324,440,kVerticalFrame);
   fMainFrame2028->SetName("fMainFrame2028");
   fMainFrame2028->SetLayoutBroken(kTRUE);

   // composite frame
   TGCompositeFrame *fMainFrame2190 = new TGCompositeFrame(fMainFrame2028,326,445,kVerticalFrame | kSunkenFrame);
   fMainFrame2190->SetName("fMainFrame2190");
   fMainFrame2190->SetLayoutBroken(kTRUE);

   // vertical frame
   TGVerticalFrame *fVerticalFrame560 = new TGVerticalFrame(fMainFrame2190,320,85,kVerticalFrame | kSunkenFrame);
   fVerticalFrame560->SetName("fVerticalFrame560");
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
   TGTextEntry *fTextEntry665 = new TGTextEntry(fVerticalFrame560, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground);
   fTextEntry665->SetMaxLength(4096);
   fTextEntry665->SetAlignment(kTextLeft);
   fTextEntry665->SetText("Set_00");
   fTextEntry665->Resize(100,fTextEntry665->GetDefaultHeight());
   fVerticalFrame560->AddFrame(fTextEntry665, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry665->MoveResize(124,26,100,22);
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
   TGTextEntry *fTextEntry667 = new TGTextEntry(fVerticalFrame560, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground);
   fTextEntry667->SetMaxLength(4096);
   fTextEntry667->SetAlignment(kTextLeft);
   fTextEntry667->SetText("./data");
   fTextEntry667->Resize(100,fTextEntry667->GetDefaultHeight());
   fVerticalFrame560->AddFrame(fTextEntry667, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry667->MoveResize(124,50,100,22);

   fMainFrame2190->AddFrame(fVerticalFrame560, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fVerticalFrame560->MoveResize(1,1,320,85);

   // vertical frame
   TGVerticalFrame *fVerticalFrame1662 = new TGVerticalFrame(fMainFrame2190,320,96,kVerticalFrame | kSunkenFrame);
   fVerticalFrame1662->SetName("fVerticalFrame1662");
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
   TGTextEntry *fTextEntry671 = new TGTextEntry(fVerticalFrame1662, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground,ucolor);
   fTextEntry671->SetMaxLength(4096);
   fTextEntry671->SetAlignment(kTextLeft);
   fTextEntry671->SetText("#0x0");
   fTextEntry671->Resize(99,fTextEntry671->GetDefaultHeight());
   fVerticalFrame1662->AddFrame(fTextEntry671, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry671->MoveResize(100,23,99,22);
   TGLabel *fLabel672 = new TGLabel(fVerticalFrame1662,"Vset");
   fLabel672->SetTextJustify(36);
   fLabel672->SetMargins(0,0,0,0);
   fLabel672->SetWrapLength(-1);
   fVerticalFrame1662->AddFrame(fLabel672, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel672->MoveResize(10,45,62,16);
   TGLabel *fLabel673 = new TGLabel(fVerticalFrame1662,"UI Curve");
   fLabel673->SetTextJustify(36);
   fLabel673->SetMargins(0,0,0,0);
   fLabel673->SetWrapLength(-1);
   fVerticalFrame1662->AddFrame(fLabel673, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel673->MoveResize(10,67,62,16);
   TGNumberEntry *fNumberEntry1049 = new TGNumberEntry(fVerticalFrame1662, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fNumberEntry1049->SetName("fNumberEntry1049");
   fVerticalFrame1662->AddFrame(fNumberEntry1049, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fNumberEntry1049->MoveResize(167,67,64,22);
   
   TGNumberEntry *fNumberEntry1050 = new TGNumberEntry(fVerticalFrame1662, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fNumberEntry1050->SetName("fNumberEntry1050");
   fVerticalFrame1662->AddFrame(fNumberEntry1050, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fNumberEntry1050->MoveResize(167,67,64,22);
   
   TGNumberEntry *fNumberEntry1051 = new TGNumberEntry(fVerticalFrame1662, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fNumberEntry1051->SetName("fNumberEntry1051");
   fVerticalFrame1662->AddFrame(fNumberEntry1051, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fNumberEntry1051->MoveResize(167,67,64,22);
   
   TGNumberEntry *fNumberEntry1052 = new TGNumberEntry(fVerticalFrame1662, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fNumberEntry1052->SetName("fNumberEntry1052");
   fVerticalFrame1662->AddFrame(fNumberEntry1052, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fNumberEntry1052->MoveResize(167,67,64,22);
   
   TGNumberEntry *fNumberEntry1053 = new TGNumberEntry(fVerticalFrame1662, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fNumberEntry1053->SetName("fNumberEntry1053");
   fVerticalFrame1662->AddFrame(fNumberEntry1053, new TGLayoutHints(kLHintsNormal));
   fNumberEntry1053->MoveResize(100,45,64,22);

   fMainFrame2190->AddFrame(fVerticalFrame1662, new TGLayoutHints(kLHintsExpandX));
   fVerticalFrame1662->MoveResize(1,86,320,96);

   // vertical frame
   TGVerticalFrame *fVerticalFrame1682 = new TGVerticalFrame(fMainFrame2190,320,88,kVerticalFrame | kSunkenFrame);
   fVerticalFrame1682->SetName("fVerticalFrame1682");
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
   TGLabel *fLabel692 = new TGLabel(fVerticalFrame1682,"Info");
   fLabel692->SetTextJustify(36);
   fLabel692->SetMargins(0,0,0,0);
   fLabel692->SetWrapLength(-1);
   fVerticalFrame1682->AddFrame(fLabel692, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel692->MoveResize(2,31,20,16);

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

   TGTextEntry *fTextEntry980 = new TGTextEntry(fVerticalFrame1682, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground,ucolor);
   fTextEntry980->SetMaxLength(4096);
   fTextEntry980->SetAlignment(kTextLeft);
   fTextEntry980->SetText("ROC_Version");
   fTextEntry980->Resize(88,fTextEntry980->GetDefaultHeight());
   fVerticalFrame1682->AddFrame(fTextEntry980, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry980->MoveResize(128,31,88,22);
   TGLabel *fLabel989 = new TGLabel(fVerticalFrame1682,"Sampling Time");
   fLabel989->SetTextJustify(36);
   fLabel989->SetMargins(0,0,0,0);
   fLabel989->SetWrapLength(-1);
   fVerticalFrame1682->AddFrame(fLabel989, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel989->MoveResize(2,59,81,16);

   // vertical frame
   TGVerticalFrame *fVerticalFrame1260 = new TGVerticalFrame(fVerticalFrame1682,80,24,kVerticalFrame);
   fVerticalFrame1260->SetName("fVerticalFrame1260");
   TGNumberEntry *fNumberEntry1269 = new TGNumberEntry(fVerticalFrame1260, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fNumberEntry1269->SetName("fNumberEntry1269");
   fVerticalFrame1260->AddFrame(fNumberEntry1269, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   TGLabel *fLabel1279 = new TGLabel(fVerticalFrame1260,"(s)");
   fLabel1279->SetTextJustify(36);
   fLabel1279->SetMargins(0,0,0,0);
   fLabel1279->SetWrapLength(-1);
   fVerticalFrame1260->AddFrame(fLabel1279, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));

   fVerticalFrame1682->AddFrame(fVerticalFrame1260, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fVerticalFrame1260->MoveResize(128,59,80,24);

   fMainFrame2190->AddFrame(fVerticalFrame1682, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fVerticalFrame1682->MoveResize(1,184,320,88);

   // vertical frame
   TGVerticalFrame *fVerticalFrame1410 = new TGVerticalFrame(fMainFrame2190,320,80,kVerticalFrame | kSunkenFrame);
   fVerticalFrame1410->SetName("fVerticalFrame1410");
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
   TGTextButton *fTextButton1677 = new TGTextButton(fVerticalFrame1410,"UI Curve",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1677->SetTextJustify(36);
   fTextButton1677->SetMargins(0,0,0,0);
   fTextButton1677->SetWrapLength(-1);
   fTextButton1677->Resize(80,22);
   fVerticalFrame1410->AddFrame(fTextButton1677, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1677->MoveResize(4,27,80,22);
   TGTextButton *fTextButton1653 = new TGTextButton(fVerticalFrame1410,"Produce",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1653->SetTextJustify(36);
   fTextButton1653->SetMargins(0,0,0,0);
   fTextButton1653->SetWrapLength(-1);
   fTextButton1653->Resize(80,22);
   fVerticalFrame1410->AddFrame(fTextButton1653, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1653->MoveResize(101,27,80,22);
   TGTextButton *fTextButton1703 = new TGTextButton(fVerticalFrame1410,"Noise Slope",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1703->SetTextJustify(36);
   fTextButton1703->SetMargins(0,0,0,0);
   fTextButton1703->SetWrapLength(-1);
   fTextButton1703->Resize(80,22);
   fVerticalFrame1410->AddFrame(fTextButton1703, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1703->MoveResize(200,27,80,22);
   TGTextButton *fTextButton1724 = new TGTextButton(fVerticalFrame1410,"Signal Gain",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1724->SetTextJustify(36);
   fTextButton1724->SetMargins(0,0,0,0);
   fTextButton1724->SetWrapLength(-1);
   fTextButton1724->Resize(80,22);
   fVerticalFrame1410->AddFrame(fTextButton1724, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1724->MoveResize(4,51,80,22);
   TGTextButton *fTextButton1738 = new TGTextButton(fVerticalFrame1410,"V Breakdown",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1738->SetTextJustify(36);
   fTextButton1738->SetMargins(0,0,0,0);
   fTextButton1738->SetWrapLength(-1);
   fTextButton1738->Resize(80,22);
   fVerticalFrame1410->AddFrame(fTextButton1738, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1738->MoveResize(101,51,80,22);

   fMainFrame2190->AddFrame(fVerticalFrame1410, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fVerticalFrame1410->MoveResize(1,276,320,80);

   // vertical frame
   TGVerticalFrame *fVerticalFrame2090 = new TGVerticalFrame(fMainFrame2190,320,82,kVerticalFrame | kSunkenFrame);
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
   TGTextButton *fTextButton2206 = new TGTextButton(fVerticalFrame2090,"Check",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
   fTextButton2206->SetTextJustify(36);
   fTextButton2206->SetMargins(0,0,0,0);
   fTextButton2206->SetWrapLength(-1);
   fTextButton2206->Resize(306,24);

   fTextButton2206->ChangeBackground(ucolor);
   fVerticalFrame2090->AddFrame(fTextButton2206, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsExpandX,2,2,2,2));
   fTextButton2206->MoveResize(2,3,306,24);

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
   TGTextButton *fTextButton2236 = new TGTextButton(fVerticalFrame2090,"START",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
   fTextButton2236->SetTextJustify(36);
   fTextButton2236->SetMargins(0,0,0,0);
   fTextButton2236->SetWrapLength(-1);
   fTextButton2236->Resize(306,22);

   fTextButton2236->ChangeBackground(ucolor);
   fVerticalFrame2090->AddFrame(fTextButton2236, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsExpandX,2,2,2,2));
   fTextButton2236->MoveResize(2,29,306,22);

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
   TGTextButton *fTextButton2277 = new TGTextButton(fVerticalFrame2090,"Save",-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame);
   fTextButton2277->SetTextJustify(36);
   fTextButton2277->SetMargins(0,0,0,0);
   fTextButton2277->SetWrapLength(-1);
   fTextButton2277->Resize(306,22);
   fTextButton2277->SetState(kButtonDown);

   gClient->GetColorByName("#ffffff",ucolor);
   fTextButton2277->ChangeBackground(ucolor);
   fVerticalFrame2090->AddFrame(fTextButton2277, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsExpandX,2,2,2,2));
   fTextButton2277->MoveResize(2,55,306,22);

   fMainFrame2190->AddFrame(fVerticalFrame2090, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fVerticalFrame2090->MoveResize(1,360,320,82);

   fMainFrame2028->AddFrame(fMainFrame2190, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame2190->MoveResize(0,0,326,445);

   fMainFrame2933->AddFrame(fMainFrame2028, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame2028->MoveResize(0,0,324,440);

   fMainFrame2933->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fMainFrame2933->MapSubwindows();

   fMainFrame2933->Resize(fMainFrame2933->GetDefaultSize());
   fMainFrame2933->MapWindow();
   fMainFrame2933->Resize(324,445);
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
int CheckFEE()
{
  if (linkusb_open(&linkusb, 0))
    return -1; // error messages in linkusb_open

  EPD_connect_FEE(&linkusb, owaddr, swaddr); // connect to FEE at switch address 0
  DS28CM00_read(&linkusb, owaddr, &serial);
  printf("FEE %d serial number: 0x%016llx\n", swaddr, serial);

  EPD_disconnect_FEE(&linkusb, owaddr);
  linkusb_close(&linkusb);
  return 0;
}

// FEE initial setup
int SetFEE(double _voltage = 55.0, double _vslope = 0.054, int _pedestal = 0)
{
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

#include "TMultiGraph.h"
#include "TGraph.h"
int TestUiCurve(double _vStart, double _vStop, double _vStep)
{
  const int N_VOLTAGE_PTS = (_vStop - _vStart) / _vStep;
  double vset[N_VOLTAGE_PTS];
  double imon[N_SIPM][N_VOLTAGE_PTS];
  
  // Open FEE LinkUSB Interface
  if (linkusb_open(&linkusb, 0))
    return -1; // error messages in linkusb_open
  EPD_connect_FEE(&linkusb, owaddr, swaddr); // connect to FEE at switch address 0
  for(int i = 0; i <= N_VOLTAGE_PTS; i++)
  {
    vset[i]= _vStart + i * _vStep;
    for(int ch = 0 ; ch < N_SIPM ; ch++)
      EPD_set_voltage(&linkusb, owaddr, ch, vset[i]);
    for(int ch = 0 ; ch < N_SIPM ; ch++)
      imon[ch][i] = EPD_get_imon(&linkusb, owaddr, ch);
  }
  // Close FEE connect
  EPD_disconnect_FEE(&linkusb, owaddr);
  linkusb_close(&linkusb);

  TMultiGraph* mg = new TMultiGraph("ui","UI Curve of SiPM");
  TGraph *ui[N_SIPM];
  for(int ch = 0 ; ch < N_SIPM ; ch++)
  {
    ui[ch] = new TGraph(N_VOLTAGE_PTS, vset, imon[ch]);
    mg->Add(ui[ch]);
  }
  return 0;
}

int SetVoltage(int _vset)
{
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

int TestDAC()
{
  // set pedestal & read DGTZ?
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
  // DEBUG
  cout << log << endl;
  return NULL;
}
int ReadDGTZ(const char* _PATH=".", int _samplingSec = 5000){
  const int BUUFFER_TIME = 2000; // Prepare buffer data for writing
  TThread* th = new TThread("dgtz",OpenDGTZ);
  gSystem->Exec("echo >tmp");
  th->Run((void*)_PATH);
  gSystem->Exec("echo s >>tmp"); // Start acquisition
  gSystem->Sleep(BUUFFER_TIME); // milliSec
  gSystem->Exec("echo W >>tmp");  // Start continuous writing
  gSystem->Sleep(_samplingSec); // milliSec
  gSystem->Exec("echo s >>tmp");  // Stop acquisitio
  gSystem->Exec("echo q >>tmp");  // Quit
  th->Kill();
  th->Delete();th = NULL;
  return 0;
}
int CheckDGTZ(){
  gSystem->Exec("echo q >tmp");
  TString model =
    gSystem->GetFromPipe("/usr/local/bin/wavedump <tmp | sed -n 's/.*Model\\ \\(.*\\)/\\1/p'");
  // STATUS
  if(model.Length() < 1)
    cout << "[X] STATUS - DGTZ Not Connected!" << endl;
  else
    cout << "[-] STATUS - DGTZ Model : " << model << endl;

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
