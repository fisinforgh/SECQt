/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// Notice OF COPYRIGHT                                                     //
//                                                                         //
// Copyright (C) 2024                                                      //
//                                                                         //
// Authors:								   //
//   [1] Sandra Milena Agudelo-González*	       			   //
//   [2] Julián Salamanca*               				   //
//                                                                         //
//   [1] smagudelog@udistrital.edu.co (Estudiante Universidad Distrital)   //
//   [2] jasalamanca@udistrital.edu.co (profesor Universidad Distrital)    //
//									   //
//  *Grupo de Física e Informática (FISINFOR)                              //
//   Universidad Distrital Francisco José de Caldas                        //
//                                                                         //
// Web page:								   //
//  https://github.com/fisinforgh/SECQt.git                                //
//                                                                         //
// This program is free software; you can redistribute it and/or modify    //
// it under the terms of the GNU General Public License as published by    //
// the Free Software Foundation; either version 2 of the License, or       //
// (at your option) any later version.                                     //
//                                                                         //
// This program is distributed in the hope that it will be useful,         //
// but WITHOUT ANY WARRANTY; without even the implied warranty of          //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           //
// GNU General Public License for more details:                            //
//                                                                         //
//               http://www.gnu.org/copyleft/gpl.html                      //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include "TGDockableFrame.h"
#include "TGMdiDecorFrame.h"
#include "TG3DLine.h"
#include "TGMdiFrame.h"
#include "TGMdiMainFrame.h"
#include "TGMdiMenu.h"
#include "TGListBox.h"
#include "TGNumberEntry.h"
#include "TGScrollBar.h"
#include "TGComboBox.h"
#include "TGuiBldHintsEditor.h"
#include "TRootBrowser.h"
#include "TGuiBldNameFrame.h"
#include "TGFrame.h"
#include "TGMenu.h"
#include "TGFileDialog.h"
#include "TGShutter.h"
#include "TGButtonGroup.h"
#include "TGCommandPlugin.h"
#include "TGCanvas.h"
#include "TGFSContainer.h"
#include "TGuiBldEditor.h"
#include "TGColorSelect.h"
#include "TGTextEdit.h"
#include "TGButton.h"
#include "TRootContextMenu.h"
#include "TGFSComboBox.h"
#include "TGLabel.h"
#include "TGView.h"
#include "TGMsgBox.h"
#include "TRootGuiBuilder.h"
#include "TGFileBrowser.h"
#include "TGTab.h"
#include "TGListView.h"
#include "TGSplitter.h"
#include "TGTextEditor.h"
#include "TRootCanvas.h"
#include "TGStatusBar.h"
#include "TGListTree.h"
#include "TGuiBldGeometryFrame.h"
#include "TGToolTip.h"
#include "TGToolBar.h"
#include "TRootEmbeddedCanvas.h"
#include "TCanvas.h"
#include "TGuiBldDragManager.h"
#include "TGHtmlBrowser.h"
#include "Riostream.h"
#include "TTimer.h"
#include "TROOT.h"
#include "TEnv.h"
#include "TPolyLine.h"
#include "TLatex.h"
#include "TSystem.h"
#include "TArrow.h"
#include "TMath.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TStyle.h"
#include "TH1.h"
#include "TPaveText.h"
#include "TF1.h"
#include <complex>

#include <TApplication.h>
#include <TGClient.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TRandom.h>
#include <TGButton.h>
#include <TRootEmbeddedCanvas.h>
#include "QT_SE.h"

using std::complex;

/////////////////////////////////////////////////////// GUI DESING /////////////////////////////////////////////////////////////

MyMainFrame::MyMainFrame(const TGWindow *p,UInt_t w,UInt_t h) {
  TGFont              *ufont;         // will reflect user font changes
  TGGC                *uGC;           // will reflect user GC changes
  ULong_t              ucolor; 
  
  //MAIN FRAME
  Main = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
  // fMainFrame1709->SetLayoutBroken(kTRUE); 
  gClient->GetColorByName("#ffffff",ucolor);
  
  //----------------------------------------------------- FRAMES -------------------------------------------------------------//
  
  // HORIZONTAL FRAME --- Aquí está el Canvas Embebido y los botones verticales de la izquierda
  HFramePrincipal = new TGHorizontalFrame(Main,800,500,kHorizontalFrame | kRaisedFrame,ucolor);
  HFramePrincipal->SetName("HFramePrincipal");
  
  gClient->GetColorByName("#ffffff",ucolor);
  
  // VERTICAL FRAME --- Frame de los botones verticales de la izquierda
  VerticalFrameButton = new TGVerticalFrame(HFramePrincipal,128,698, kVerticalFrame,ucolor);
  VerticalFrameButton->SetName("VerticalFrameButton");
  // VerticalFrameButton->SetLayoutBroken(kTRUE);

  ufont = gClient->GetFont("-*-arial-bold-r-narrow--15-*-*-*-*-*-iso8859-1");
  GCValues_t valpFrame1425;
  valpFrame1425.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",valpFrame1425.fForeground);
  gClient->GetColorByName("#e8e8e8",valpFrame1425.fBackground);
  valpFrame1425.fFillStyle = kFillSolid;
  valpFrame1425.fFont = ufont->GetFontHandle();
  valpFrame1425.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&valpFrame1425, kTRUE);
  gClient->GetColorByName("#ffffff",ucolor);
  
  // "F.T.I.R" group frame
  GroupFrameFTIR = new TGGroupFrame(VerticalFrameButton,"F.T.I.R",kVerticalFrame | kRaisedFrame,uGC->GetGC(),ufont->GetFontStruct(),ucolor);
  GroupFrameFTIR->SetLayoutBroken(kTRUE);
  gClient->GetColorByName("#ffd2d1",ucolor);
  
  // VERTICAL FRAME ---- Aquí está el primer bloque de botones: n_{1} y n_{2}
  VFrameRefractiveIndex = new TGVerticalFrame(GroupFrameFTIR,104,144,kVerticalFrame,ucolor);
  VFrameRefractiveIndex->SetLayoutBroken(kTRUE);

  ufont = gClient->GetFont("-*-arial-medium-r-narrow--15-*-*-*-*-*-iso8859-1");
  GCValues_t vall1427;
  vall1427.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",vall1427.fForeground);
  gClient->GetColorByName("#e8e8e8",vall1427.fBackground);
  vall1427.fFillStyle = kFillSolid;
  vall1427.fFont = ufont->GetFontHandle();
  vall1427.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&vall1427, kTRUE);
  
  //Label n_{1}
  Label1 = new TGLabel(VFrameRefractiveIndex,"    1st and 3rd \nRefractive Index",uGC->GetGC(),ufont->GetFontStruct(),kChildFrame,ucolor);
  Label1->SetTextJustify(36);
  Label1->SetMargins(0,0,0,0);
  Label1->SetWrapLength(-1);
  
  VFrameRefractiveIndex->AddFrame(Label1, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsExpandX,2,2,2,2));
  Label1->MoveResize(6,6,143,30);
  gClient->GetColorByName("#ffffff",ucolor);
  
  // Boton desplegable n_{1}
  ComboBoxN1 = new TGComboBox(VFrameRefractiveIndex,-1,kHorizontalFrame | kSunkenFrame | kOwnBackground);
  ComboBoxN1->AddEntry("Quartz (1.46)", 0);
  ComboBoxN1->AddEntry("Flint Glass (1.69) ", 1);
  ComboBoxN1->AddEntry("Diamond (2.42) ", 2);
  ComboBoxN1->Resize(100,20);
  ComboBoxN1->Select(0);
  
  VFrameRefractiveIndex->AddFrame(ComboBoxN1, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,2,2,2,2));
  ComboBoxN1->MoveResize(5,40,143,25);
  gClient->GetColorByName("#ffd2d1",ucolor);
  
  //LINE 1
  Line1 = new TGHorizontal3DLine(VFrameRefractiveIndex,100,8,kChildFrame,ucolor);
  VFrameRefractiveIndex->AddFrame(Line1, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandX,2,2,2,2));
  Line1->MoveResize(2,74,100,8);

  ufont = gClient->GetFont("-*-arial-medium-r-narrow--15-*-*-*-*-*-iso8859-1");
  GCValues_t vall1447;
  vall1447.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",vall1447.fForeground);
  gClient->GetColorByName("#ffd2d1",vall1447.fBackground);
  vall1447.fFillStyle = kFillSolid;
  vall1447.fFont = ufont->GetFontHandle();
  vall1447.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&vall1447, kTRUE);
  
  //Label n_{2}
  Label2 = new TGLabel(VFrameRefractiveIndex,"2nd Refractive index",uGC->GetGC(),ufont->GetFontStruct(),kChildFrame,ucolor);
  Label2->SetTextJustify(36);
  Label2->SetMargins(0,0,0,0);
  Label2->SetWrapLength(-1);

  VFrameRefractiveIndex->AddFrame(Label2, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsExpandX,2,2,2,2));
  Label2->MoveResize(8,80,143,27);
  gClient->GetColorByName("#ffffff",ucolor);
  
  // Boton desplegable n_{2}
  ComboBoxN2 = new TGComboBox(VFrameRefractiveIndex,-1,kHorizontalFrame | kSunkenFrame | kOwnBackground);
  ComboBoxN2->AddEntry("Vacuum (1.00)", 0);
  ComboBoxN2->AddEntry("Water (1.33) ", 1);
  ComboBoxN2->AddEntry("Ethanol (1.36) ", 2);
  ComboBoxN2->Select(0);

  VFrameRefractiveIndex->AddFrame(ComboBoxN2, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,2,2,2,2));
  ComboBoxN2->MoveResize(5,103,143,25);
  GroupFrameFTIR->AddFrame(VFrameRefractiveIndex, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  VFrameRefractiveIndex->MoveResize(8,25,152,138);
  gClient->GetColorByName("#bedafa",ucolor);
  
  // VERTICAL FRAME --- Espesor del medio n_{2}
  VFrameThicknessN2 = new TGVerticalFrame(GroupFrameFTIR,104,102,kVerticalFrame,ucolor);
  VFrameThicknessN2->SetLayoutBroken(kTRUE);

  ufont = gClient->GetFont("-*-arial-medium-r-narrow--15-*-*-*-*-*-iso8859-1");
  GCValues_t vall1467;
  vall1467.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",vall1467.fForeground);
  gClient->GetColorByName("#e8e8e8",vall1467.fBackground);
  vall1467.fFillStyle = kFillSolid;
  vall1467.fFont = ufont->GetFontHandle();
  vall1467.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&vall1467, kTRUE);
  
  // Label Thickness medium n_{2}
  TEnv *gEnv = new TEnv();
  gEnv->SetValue("Root.TGString.Encoder", "utf8");
  Label3 = new TGLabel(VFrameThicknessN2,"    2nd Medium \nThickness (\xB5m)",uGC->GetGC(),ufont->GetFontStruct(),kChildFrame,ucolor);
  Label3->SetTextJustify(36);
  Label3->SetMargins(0,0,0,0);
  Label3->SetWrapLength(-1);

  VFrameThicknessN2->AddFrame(Label3, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandX,2,2,2,2));
  Label3->MoveResize(2,4,143,32);
  
  // Value Boton valor Thickness medium n_{2} 
  ValueThicknessN2 = new TGNumberEntry(VFrameThicknessN2, (Double_t) 0,12,-1,(TGNumberFormat::EStyle) 5);

  VFrameThicknessN2->AddFrame(ValueThicknessN2, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,2,2,2,2));
  ValueThicknessN2->MoveResize(5,38,143,25);
  //// VALOR 
  ValueThicknessN2->SetNumber(1.55);
  ValueThicknessN2->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.01, 1.55);
  
  GroupFrameFTIR->AddFrame(VFrameThicknessN2, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  VFrameThicknessN2->MoveResize(8,173,152,72);
  GroupFrameFTIR->SetLayoutManager(new TGVerticalLayout(GroupFrameFTIR));
  VerticalFrameButton->AddFrame(GroupFrameFTIR, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsCenterY ,2,2,2,2));
  GroupFrameFTIR->MoveResize(2,2,170,270);

  ufont = gClient->GetFont("-*-arial-bold-r-narrow--15-*-*-*-*-*-iso8859-1");
  GCValues_t valpFrame1472;
  valpFrame1472.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",valpFrame1472.fForeground);
  gClient->GetColorByName("#e8e8e8",valpFrame1472.fBackground);
  valpFrame1472.fFillStyle = kFillSolid;
  valpFrame1472.fFont = ufont->GetFontHandle();
  valpFrame1472.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&valpFrame1472, kTRUE);
  gClient->GetColorByName("#ffffff",ucolor);
  
  // "Q. T." group frame
  GroupFrameQT = new TGGroupFrame(VerticalFrameButton,"Q. T.",kVerticalFrame,uGC->GetGC(),ufont->GetFontStruct(),ucolor);
  GroupFrameQT->SetLayoutBroken(kTRUE);
  gClient->GetColorByName("#ffd2d1",ucolor);
  
  // VERTICAL FRAME ------ Potential Difference
  VFramePotentialDifference = new TGVerticalFrame(GroupFrameQT,104,80,kVerticalFrame,ucolor);
  VFramePotentialDifference->SetLayoutBroken(kTRUE);
  ufont = gClient->GetFont("-*-arial-medium-r-narrow--15-*-*-*-*-*-iso8859-1");
  GCValues_t vall1474;
  vall1474.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",vall1474.fForeground);
  gClient->GetColorByName("#e8e8e8",vall1474.fBackground);
  vall1474.fFillStyle = kFillSolid;
  vall1474.fFont = ufont->GetFontHandle();
  vall1474.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&vall1474, kTRUE);
  
  //Label Potential Difference
  Label4 = new TGLabel(VFramePotentialDifference,"    Potential \nDifference (eV)",uGC->GetGC(),ufont->GetFontStruct(),kChildFrame,ucolor);
  Label4->SetTextJustify(36);
  Label4->SetMargins(0,0,0,0);
  Label4->SetWrapLength(-1);
  VFramePotentialDifference->AddFrame(Label4, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandX,2,2,2,2));
  Label4->MoveResize(8,1,143,37);
  
  // Number Entry ---- Valor diferencia de potencial
  ValuePotentialDifference = new TGNumberEntry(VFramePotentialDifference, (Double_t) 0,12,-1,(TGNumberFormat::EStyle) 5);
  VFramePotentialDifference->AddFrame(ValuePotentialDifference, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,2,2,2,2));
  ValuePotentialDifference->MoveResize(5,40,143,25);

  //// VALOR DIFERENCIA DE POTENCIAL
  ValuePotentialDifference->SetNumber(5.5);
  ValuePotentialDifference->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.1, 14.9);
  double E  = ValuePotentialDifference->GetNumber();
  
  GroupFrameQT->AddFrame(VFramePotentialDifference, new TGLayoutHints(kLHintsExpandX,2,2,2,2));
  VFramePotentialDifference->MoveResize(8,27,152,80);
  gClient->GetColorByName("#bedafa",ucolor);
  
  // vertical frame ---- Barrier Width
  VFrameBarrierWidth = new TGVerticalFrame(GroupFrameQT,104,80,kVerticalFrame,ucolor);
  VFrameBarrierWidth->SetLayoutBroken(kTRUE);

  ufont = gClient->GetFont("-*-arial-medium-r-narrow--15-*-*-*-*-*-iso8859-1");	
  GCValues_t vall1480;
  vall1480.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",vall1480.fForeground);
  gClient->GetColorByName("#e8e8e8",vall1480.fBackground);
  vall1480.fFillStyle = kFillSolid;
  vall1480.fFont = ufont->GetFontHandle();
  vall1480.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&vall1480, kTRUE);
  
  //Label Barrier Width
  Label5 = new TGLabel(VFrameBarrierWidth,"Barrier Width (\305)",uGC->GetGC(),ufont->GetFontStruct(),kChildFrame,ucolor);
  Label5->SetTextJustify(36);
  Label5->SetMargins(0,0,0,0);
  Label5->SetWrapLength(-1);
  VFrameBarrierWidth->AddFrame(Label5, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandX,2,2,2,2));
  Label5->MoveResize(2,4,143,37);
  
  // Value Barrier Width
  ValueBarrierWidth = new TGNumberEntry(VFrameBarrierWidth, (Double_t) 0,12,-1,(TGNumberFormat::EStyle) 5);
  VFrameBarrierWidth->AddFrame(ValueBarrierWidth, new TGLayoutHints(kLHintsExpandX,2,2,2,2));
  ValueBarrierWidth->MoveResize(5,40,143,25);

  // --- Valor ancho de la barreraL
  ValueBarrierWidth->SetNumber(2.5);
  ValueBarrierWidth->SetLimits(TGNumberFormat::kNELLimitMinMax, 0.10, 2.5);
  
  GroupFrameQT->AddFrame(VFrameBarrierWidth, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
  VFrameBarrierWidth->MoveResize(8,115,152,80);
  
  GroupFrameQT->SetLayoutManager(new TGVerticalLayout(GroupFrameQT));
  GroupFrameQT->Resize(124,229);
  VerticalFrameButton->AddFrame(GroupFrameQT, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsCenterY,2,2,2,2));
  GroupFrameQT->MoveResize(2,323,170,220);
  gClient->GetColorByName("#ffffff",ucolor);
  
  // vertical frame --- LOGO APP
  VFrameLOGO1 = new TGVerticalFrame(VerticalFrameButton,124,117,kVerticalFrame,ucolor);
  VFrameLOGO1->SetName("VFrameLOGO1");
  VFrameLOGO1->SetLayoutBroken(kTRUE);

  //---------------------------------------------------------  ICONS  --------------------------------------------------------------//
  TString spathHIDEN_FILE(gSystem->HomeDirectory());
  spathHIDEN_FILE.Append("/.pathDIR_QFTSoftEdu.txt");

  std::ifstream inHidenFile;
  inHidenFile.open(spathHIDEN_FILE);
  
  std::string spathICONS;
  getline(inHidenFile,spathICONS);
  pathDIR_ICONS.Append(spathICONS);
  pathDIR_ICONS.Append("/Icons/");
  //---------------------------------------------------------  ICONS  --------------------------------------------------------------//

  //LOGO APP
  LogoAPP = new TGIcon(VFrameLOGO1, pathDIR_ICONS + "APP.png");	
  //LogoAPP = new TGIcon(VFrameLOGO1,"/home/snoopy/tg/software/Icons/APP.png");
  LogoAPP->SetName("LogoAPP");
  VFrameLOGO1->AddFrame(LogoAPP, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY,2,2,2,2));
  LogoAPP->MoveResize(0,0,170,81); 
  
  VerticalFrameButton->AddFrame(VFrameLOGO1, new TGLayoutHints(kLHintsExpandX,2,2,2,2));
  VFrameLOGO1->MoveResize(2,0,170,82);
  HFramePrincipal->AddFrame(VerticalFrameButton, new TGLayoutHints(kLHintsLeft,2,2,2,2));
  gClient->GetColorByName("#ffffff",ucolor);
  
  // embedded canvas
  ECanvas = new TRootEmbeddedCanvas(0,HFramePrincipal,800,400,kSunkenFrame,ucolor);
  ECanvas->SetName("ECanvas");
  
  HFramePrincipal->AddFrame(ECanvas, new TGLayoutHints( kLHintsExpandX | kLHintsExpandY,2,2,2,2));
  
  Main->AddFrame(HFramePrincipal, new TGLayoutHints( kLHintsExpandX  | kLHintsExpandY,2,2,2,2));
  HFramePrincipal->MoveResize(2,2,1459,704);
  gClient->GetColorByName("#ffffff",ucolor);
  
  // HORIZONTAL FRAME --- Botones panel inferior
  HFrameButtons = new TGHorizontalFrame(Main,1050,96,kHorizontalFrame,ucolor);
  HFrameButtons->SetName("HFrameButtons");
  // HFrameButtons->SetLayoutBroken(kTRUE);
  gClient->GetColorByName("#ffffff",ucolor);
  
  // VERTICAL FRAME --- Este Frame contiene dos frame horizontales donde se encuentran los botones
  VFrameButtons = new TGVerticalFrame(HFrameButtons,1092,92,kVerticalFrame,ucolor);
  VFrameButtons->SetName("VFrameButtons");
  //VFrameButtons->SetLayoutBroken(kTRUE);
  gClient->GetColorByName("#ffffff",ucolor);
  
  // HORIZONTAL FRAME -- Contiene la primera línea de botones
  HFrameButtons1 = new TGHorizontalFrame(VFrameButtons,1088,42,kHorizontalFrame,ucolor);
  HFrameButtons1->SetName("HFrameButtons1");
  // HFrameButtons1->SetLayoutBroken(kTRUE);
  ufont = gClient->GetFont("-*-arial-bold-r-narrow--16-*-*-*-*-*-iso8859-1");
  GCValues_t valButton1502;
  valButton1502.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",valButton1502.fForeground);
  gClient->GetColorByName("#e8e8e8",valButton1502.fBackground);
  valButton1502.fFillStyle = kFillSolid;
  valButton1502.fFont = ufont->GetFontHandle();
  valButton1502.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&valButton1502, kTRUE);
  gClient->GetColorByName("#fde56b",ucolor);
  
  //Button Quantum Tunnelling
  ButtonQT = new TGTextButton(HFrameButtons1,"Quantum Tunneling",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
  ButtonQT->SetTextJustify(36);
  ButtonQT->SetMargins(0,0,0,0);
  ButtonQT->SetWrapLength(-1);
  ButtonQT->ChangeBackground(ucolor);
  ButtonQT->Connect("Clicked()","MyMainFrame",this,"DoQT()"); ///////////////////
 
  HFrameButtons1->AddFrame(ButtonQT, new TGLayoutHints( kLHintsExpandX | kLHintsExpandY,2,2,2,2));
  ButtonQT->MoveResize(2,2,260,50);

  ufont = gClient->GetFont("-*-arial-bold-r-narrow--16-*-*-*-*-*-iso8859-1");
  GCValues_t valButton1503;
  valButton1503.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",valButton1503.fForeground);
  gClient->GetColorByName("#e8e8e8",valButton1503.fBackground);
  valButton1503.fFillStyle = kFillSolid;
  valButton1503.fFont = ufont->GetFontHandle();
  valButton1503.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&valButton1503, kTRUE);
  gClient->GetColorByName("#79b8f8",ucolor);
	
  //Button Frustrated Total Internal Reflection
  ButtonFTIR = new TGTextButton(HFrameButtons1,"Frustrated Total Internal Reflection",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
  ButtonFTIR->SetTextJustify(36);
  ButtonFTIR->SetMargins(0,0,0,0);
  ButtonFTIR->SetWrapLength(-1);
  ButtonFTIR->ChangeBackground(ucolor);
  ButtonFTIR->Connect("Clicked()","MyMainFrame",this,"DoFTIR()"); ////////
  
  HFrameButtons1->AddFrame(ButtonFTIR, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
  ButtonFTIR->MoveResize(262,2,332,50);

  ufont = gClient->GetFont("-*-arial-bold-r-narrow--16-*-*-*-*-*-iso8859-1");
  GCValues_t valButton1504;
  valButton1504.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",valButton1504.fForeground);
  gClient->GetColorByName("#e8e8e8",valButton1504.fBackground);
  valButton1504.fFillStyle = kFillSolid;
  valButton1504.fFont = ufont->GetFontHandle();
  valButton1504.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&valButton1504, kTRUE);
  gClient->GetColorByName("#ff6565",ucolor);
  
  //Button Analogy
  ButtonAnalogy = new TGTextButton(HFrameButtons1,"Analogy",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
  ButtonAnalogy->SetTextJustify(36);
  ButtonAnalogy->SetMargins(0,0,0,0);
  ButtonAnalogy->SetWrapLength(-1);
  ButtonAnalogy->ChangeBackground(ucolor);

  ButtonAnalogy->Connect("Clicked()","MyMainFrame",this,"DoAnalogy()"); ////////
  
  HFrameButtons1->AddFrame(ButtonAnalogy, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
  ButtonAnalogy->MoveResize(600,2,408,38);
  VFrameButtons->AddFrame(HFrameButtons1, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
  HFrameButtons1->MoveResize(2,2,1188,52);
  gClient->GetColorByName("#ffffff",ucolor);
  
  // HORIZONTAL FRAME ---- Segundo bloque de botones
  HFrameButtons2 = new TGHorizontalFrame(VFrameButtons,1088,42,kHorizontalFrame,ucolor);
  HFrameButtons2->SetName("HFrameButtons2");
  //HFrameButtons2->SetLayoutBroken(kTRUE);

  ufont = gClient->GetFont("-*-arial-bold-r-narrow--16-*-*-*-*-*-iso8859-1");
  GCValues_t valButton1506;
  valButton1506.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",valButton1506.fForeground);
  gClient->GetColorByName("#e8e8e8",valButton1506.fBackground);
  valButton1506.fFillStyle = kFillSolid;
  valButton1506.fFont = ufont->GetFontHandle();
  valButton1506.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&valButton1506, kTRUE);
  gClient->GetColorByName("#999999",ucolor);
	
  // Button Help
  ButtonHelp = new TGTextButton(HFrameButtons2,"Help",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
  ButtonHelp->SetTextJustify(36);
  ButtonHelp->SetMargins(0,0,0,0);
  ButtonHelp->SetWrapLength(-1);  
  ButtonHelp->ChangeBackground(ucolor);
  ButtonHelp->Connect("Clicked()","MyMainFrame",this,"DoWelcome()"); /////////
  
  HFrameButtons2->AddFrame(ButtonHelp, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
  ButtonHelp->MoveResize(2,2,590,38);

  ufont = gClient->GetFont("-*-arial-bold-r-narrow--16-*-*-*-*-*-iso8859-1");
  GCValues_t valButton1507;
  valButton1507.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
  gClient->GetColorByName("#000000",valButton1507.fForeground);
  gClient->GetColorByName("#e8e8e8",valButton1507.fBackground);
  valButton1507.fFillStyle = kFillSolid;
  valButton1507.fFont = ufont->GetFontHandle();
  valButton1507.fGraphicsExposures = kFALSE;
  uGC = gClient->GetGC(&valButton1507, kTRUE);

  // Button Clear
  ButtonClear = new TGTextButton(HFrameButtons2,"Clear",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
  ButtonClear->SetTextJustify(36);
  ButtonClear->SetMargins(0,0,0,0);
  ButtonClear->SetWrapLength(-1);  
  ButtonClear->ChangeBackground(ucolor);
  ButtonClear->Connect("Clicked()","MyMainFrame",this,"DoClear()"); 
 
  HFrameButtons2->AddFrame(ButtonClear, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
  ButtonClear->MoveResize(2,2,590,38);
  
  // Button Exit
  TGTextButton *ButtonExit = new TGTextButton(HFrameButtons2,"Exit",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
  ButtonExit->SetCommand("gApplication->Terminate(0)");
  ButtonExit->SetTextJustify(36);
  ButtonExit->SetMargins(0,0,0,0);
  ButtonExit->SetWrapLength(-1);
  ButtonExit->ChangeBackground(ucolor);
  HFrameButtons2->AddFrame(ButtonExit, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
  ButtonExit->MoveResize(596,2,590,38);

  VFrameButtons->AddFrame(HFrameButtons2, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
  HFrameButtons2->MoveResize(2,56,1188,52);
  HFrameButtons->AddFrame(VFrameButtons, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
  VFrameButtons->MoveResize(2,2,1192,110);
  gClient->GetColorByName("#ffffff",ucolor);
  
  // VERTICAL FRAME --- Para el logo de la Universidad
  VFrameLOGO2 = new TGVerticalFrame(HFrameButtons,120,92,kVerticalFrame,ucolor);
  VFrameLOGO2->SetName("VFrameLOGO2");
  //VFrameLOGO2->SetLayoutBroken(kTRUE);

  //--------------------------------- ICONS -----------------------------------------------
  TString spathHIDEN_FILE(gSystem->HomeDirectory());
  spathHIDEN_FILE.Append("/.pathDIR_CQtSoftEdu.txt");

  std::ifstream inHidenFile;
  inHidenFile.open(spathHIDEN_FILE);
  
  std::string spathICONS;
  getline(inHidenFile,spathICONS);
  pathDIR_ICONS.Append(spathICONS);
  pathDIR_ICONS.Append("/Icons/");
  //--------------------------------- ICONS -----------------------------------------------

  //----------LOGO UNIVERSIDAD
  LogoUD = new TGIcon(VFrameLOGO2,pathDIR_ICONS + "logoUd.png");
  //LogoUD = new TGIcon(VFrameLOGO2,"/home/snoopy/tg/software/Icons/logoUd.jpg");
  LogoUD->SetName("LogoUD");
  VFrameLOGO2->AddFrame(LogoUD, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY,2,2,2,2));
  LogoUD->MoveResize(10,0,100,88);
  HFrameButtons->AddFrame(VFrameLOGO2, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsCenterY | kLHintsExpandY,5,5,5,5));
  VFrameLOGO2->MoveResize(1202,0,120,92);
  gClient->GetColorByName("#ffffff",ucolor);
  
  // VERTICAL FRAME --- Para el logo de FISINFOR
  VFrameLOGO3 = new TGVerticalFrame(HFrameButtons,120,92,kVerticalFrame,ucolor);
  VFrameLOGO3->SetName("VFrameLOGO3");
  //VFrameLOGO3->SetLayoutBroken(kTRUE);
  
  //LOGO FISINFOR
  LogoFISINFOR = new TGIcon(VFrameLOGO3, pathDIR_ICONS + "logoFisinfor.png");
  //LogoFISINFOR = new TGIcon(VFrameLOGO3,"/home/snoopy/tg/Logos/logoFisinfor.png");
  LogoFISINFOR->SetName("LogoFISINFOR");
  VFrameLOGO3->AddFrame(LogoFISINFOR, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY,5,5,5,5));
  LogoFISINFOR->MoveResize(10,6,100,80);
  HFrameButtons->AddFrame(VFrameLOGO3, new TGLayoutHints(kLHintsLeft | kLHintsTop |  kLHintsExpandY,2,2,2,2));
  VFrameLOGO3->MoveResize(1328,0,120,92);
  Main->AddFrame(HFrameButtons, new TGLayoutHints(kLHintsBottom | kLHintsExpandX ,2,2,2,2));
  HFrameButtons->MoveResize(2,710,1456,96);
  
  Main->SetMWMHints(kMWMDecorAll,
		    kMWMFuncAll,
		    kMWMInputModeless);
  Main->MapSubwindows();
  
  Main->Resize(Main->GetDefaultSize());
  // Set a name to the main frame
  Main->SetWindowName("Classical Quantum Tunneling Software Education");
  Main->MapWindow();
  Main->Resize(1100,700);
  
  // Llamamos al método DoWelcome al construir la instancia
  DoWelcome();

  ButtonClear->SetState(kButtonDisabled, kTRUE);
}

/////////////////////////////////////// CLEAR ////////////////////////////////////////
void MyMainFrame::DoClear(){
  
  ButtonHelp->TGTextButton::SetState(kButtonUp, kTRUE);
  ButtonAnalogy->TGTextButton::SetState(kButtonUp, kTRUE);
  ButtonFTIR->TGTextButton::SetState(kButtonUp, kTRUE);
  ButtonQT->TGTextButton::SetState(kButtonUp, kTRUE);
  
  ButtonClear->TGTextButton::SetState(kButtonDisabled, kTRUE);
  
  TCanvas *canvas = ECanvas->GetCanvas();
  canvas->Clear();
  if (canvas) {
    canvas->SetFillColor(kWhite);
    canvas->Modified();
    canvas->Update();
  }
}

////////////////////////////// FTIR FUNCTIONS /////////////////////////////////////////

// Constantes globales
const double n1 = 1.5; // Índice de refracción del primer medio
const double n2 = 1.0; // Índice de refracción del segundo medio
const double n3 = n1;  // Índice de refracción del tercer medio

Double_t t = 0.165;
Double_t es = 0.5; //Espesor primer medio
Int_t v = 0;
TTimer *timer;
TCanvas *c1;
TPad *pad1 = nullptr;

void MyMainFrame::DoSimulationFTIR(TPad *pad){

  pad1->cd();
  pad1->Range(-0.125, -0.125, 1.125, 1.125);

  //t  = ValueThicknessN2->GetNumber()/100;
  t  = ValueThicknessN2->GetNumber()/10;
  //t  = ValueThicknessN2->GetNumber();
  
  // FIRST MEDIUM
  Double_t *s = 0;
  // Espesor primer medio
  TPolyLine *m1 = new TPolyLine(5, s, s);
  m1->SetPoint(0, 0.0, 0.0);
  m1->SetPoint(1, es, 0.0);
  m1->SetPoint(2, es, 1.0);
  m1->SetPoint(3, 0.0, 1.0);
  m1->SetPoint(4, 0.0, 0.0);
  
  m1->SetFillColor(kCyan - 9);
  m1->SetLineColor(0);
  m1->SetLineWidth(0);
  m1->Draw("f");
  m1->Draw();
  
  // SECOND MEDIUM
  TPolyLine *m2 = new TPolyLine(5, s, s);
  m2->SetPoint(0, es, 0.0);
  m2->SetPoint(1, es, 1.0);
  m2->SetPoint(2, es + t, 1.0);
  m2->SetPoint(3, es + t, 0.0);
  m2->SetPoint(4, es, 0.0);
  
  m2->SetFillColor(kWhite);
  m2->SetLineColor(0);
  m2->SetLineWidth(0);
  m2->Draw("f");
  m2->Draw();
  
  // THIRD MEDIUM
  TPolyLine *m3 = new TPolyLine(5, s, s);
  m3->SetPoint(0, es + t, 0.0);
  m3->SetPoint(1, es + t, 1.0);
  m3->SetPoint(2, 1.0, 1.0);
  m3->SetPoint(3, 1.0, 0.0);
  m3->SetPoint(4, es + t, 0.0);
  
  m3->SetFillColor(kCyan - 9);
  m3->SetLineColor(0);
  m3->SetLineWidth(0);
  m3->Draw("f");
  m3->Draw();
  
  // Etiquetas
  TPad *pad1_label = new TPad("pad1_label", "This is pad1_label", 0.25, 0.12, 0.4, 0.18);
  pad1_label->SetFillColor(kCyan - 9);
  pad1_label->Draw();
  pad1_label->cd();
  TLatex *t1 = new TLatex(0.5, 0.8, "1st Medium");
  t1->SetTextAlign(23);
  t1->SetTextSize(0.8);
  t1->Draw();
  pad1->cd();
  
  TPad *pad2_label = new TPad("pad2_label", "This is pad2_label", 0.75, 0.12, 0.9, 0.18);
  pad2_label->SetFillColor(kCyan - 9);
  pad2_label->Draw();
  pad2_label->cd();
  TLatex *t2 = new TLatex(0.5, 0.8, "3rd Medium");
  t2->SetTextAlign(23);
  t2->SetTextSize(0.8);
  t2->Draw();
  pad1->cd();

  int selectedIndex = ComboBoxN1->GetSelected();
  if (selectedIndex == 0) {
    m1->SetFillColor(kAzure-9);
    m3->SetFillColor(kAzure-9);
    pad1_label->SetFillColor(kAzure-9);
    pad2_label->SetFillColor(kAzure-9);
  }
  if (selectedIndex == 1){
    m1->SetFillColor(kCyan-10);
    m3->SetFillColor(kCyan-10);
    pad1_label->SetFillColor(kCyan-10);
    pad2_label->SetFillColor(kCyan-10);
  }
  
  if (selectedIndex == 2){
    m1->SetFillColor(kGreen-10);
    m3->SetFillColor(kGreen-10);
    pad1_label->SetFillColor(kGreen-10);
    pad2_label->SetFillColor(kGreen-10);
  }

  pad1->Update();
  gSystem->Sleep(500);
  TArrow *v1 = new TArrow(0.0, 0.0, 0.5, 0.5, 0.025, "->-");
  v1->SetAngle(45);
  v1->SetLineWidth(2);
  v1->SetLineColor(kRed + 1);
  v1->Draw();

  pad1->Update();
  gSystem->Sleep(500);
  TArrow *v2 = new TArrow(0.5, 0.5, 0.0, 1.0, 0.025, "->-");
  v2->SetAngle(45);
  v2->SetLineWidth(2);
  v2->SetLineColor(kRed + 1);
  v2->SetLineStyle(kDashed);
  v2->Draw();


  if (t <= 0.01) { //0.01
    pad1->Update();
    gSystem->Sleep(500);
    TArrow *v3 = new TArrow(0.5, 0.5, 1.0, 1.0, 0.025, "->-");
    v3->SetAngle(45);
    v3->SetLineWidth(2);
    v3->SetLineColor(kRed + 1);
    v3->Draw();
  } else if (t > 0.01 && t < 0.074) {
    // Dibujar la primera parte
    TArrow *vd = new TArrow(es, 0.1, es+t, 0.1, 0.01,"<|>");
    vd->SetAngle(40);
    vd->SetLineWidth(2);
    vd->SetLineColor(kBlack);
    vd->Draw();
    
    //NORMAL
    TLine *l = new TLine(0.4, 0.5, 0.6, 0.5);
    l->SetLineWidth(1);
    l->SetLineColor(1);
    l->SetLineStyle(2);
    l->Draw();
    
    Double_t Sin2 = (n1/n2)*sin(45);

    pad1->Update();
    gSystem->Sleep(500);
    TArrow *v3 = new TArrow(es, 0.5, es+t, 1/((n1/n2)*sin(45)), 0.02,"->-");
    v3->SetAngle(40);
    v3->SetLineWidth(2);
    v3->SetLineColor(kRed+1);
    v3->Draw();
            
    // 2nd NORMAL
    TLine *l1 = new TLine( 0.65, 1/((n1/n2)*sin(45)), es+t-0.04,  1/((n1/n2)*sin(45)));
    l1->SetLineWidth(1);
    l1->SetLineColor(1);
    l1->SetLineStyle(2);
    l1->Draw();
      
    Double_t Sin3 = (n1/n2)*sin(45)*(n2/n3);

    pad1->Update();
    gSystem->Sleep(500); // Wait for 500 milliseconds
    TArrow *v4 = new TArrow( es+t, 1/((n1/n2)*sin(45)), es+(0.007/t), sin(45), 0.02,"->-");
    v4->SetAngle(40);
    v4->SetLineWidth(2);
    v4->SetLineColor(kRed+1);
    v4->Draw();
    
  } else {
    //NORMAL
    TLine *l = new TLine(0.4, 0.5, 0.6, 0.5);
    l->SetLineWidth(1);
    l->SetLineColor(1);
    l->SetLineStyle(2);
    l->Draw();

    // Dibujar la primera parte
    TArrow *vd = new TArrow(es, 0.1, es+t, 0.1, 0.01,"<|>");
    vd->SetAngle(40);
    vd->SetLineWidth(2);
    vd->SetLineColor(kBlack);
    vd->Draw();
    
    pad1->Update();
    gSystem->Sleep(500); // Wait for 500 milliseconds
    TArrow *v3 = new TArrow(es, 0.5, (es+t)-(t/8), 1/((n1/n2)*sin(45))+0.05,  0.025,"->-");
    v3->SetAngle(45);
    v3->SetLineWidth(2);
    v3->SetLineColor(kRed+1);
    v3->Draw();
  }
}

double fy(double lambda, double n1, double n2, double n3, double dsep, double ang) {
  Double_t n12 = n1 * n1;
  Double_t n22 = n2 * n2;
  Double_t st1c = TMath::Sin(ang) * TMath::Sin(ang);
  return TMath::Sqrt(n12 * st1c - n22) * (2 * TMath::Pi() * dsep) / lambda;
}

double nn1 = 1.46;
double nn2 = 1.0;
double nn3 = nn1;
const double lamb = 450.0*1e-9; // Wavelenght const
const double ang = 45 * TMath::Pi() / 180; // Incident angle const

/////////////////////// Transmittance S Polarization //////////////////////////
void MyMainFrame::DoGraphFTIRSP(TPad *pad){
  
  if (pad) {

    int selectedIndex = ComboBoxN1->GetSelected();
    if (selectedIndex == 0) {
      double nn1 = 1.46;
    }
    if (selectedIndex == 1){
      double nn1 = 1.66;
    }

    if (selectedIndex == 2){
      double nn1 = 2.42;
    }
    
    // S polarization Graph
    TGraph *g2 = new TGraph();
    
    for (double ds = 0.0; ds <= ( ValueThicknessN2->GetNumber())*1e-6; ds += 5e-8) { // Ajusta el paso según tus necesidades
      double y = fy(lamb, nn1, nn2, nn3, ds, ang);
      double st1c = TMath::Sin(ang) * TMath::Sin(ang);
      double N = nn1 / nn2;
      double n = nn3 / nn1;
      double ct1 = TMath::Cos(ang);
      double_t a = ((N * N) - 1) * ((n * n * N * N) - 1) / (4 * N * N * ct1 * ((N * N * st1c) - 1) * TMath::Sqrt(n * n - st1c));
      double_t b = (TMath::Sqrt(n * n - st1c) + ct1) * (TMath::Sqrt(n * n - st1c) + ct1) / (4 * ct1 * TMath::Sqrt(n * n - st1c));
      double t = 1 / (a * TMath::SinH(y) + b);
      
      g2->SetPoint(g2->GetN(), ds, t);
    }
    
    g2->SetTitle("Transmittance of the wave with S polarization; Distance (\xB5m); Transmittance");
       
    g2->GetXaxis()->SetTitle("Distance (\xB5m)");
    g2->GetYaxis()->SetTitle("Transmittance");
    
    g2->SetMarkerStyle(20); // Estilo de los puntos
    g2->SetMarkerColor(4);
    g2->SetMarkerSize(1);  // Tamaño de los puntos
    g2->SetLineColor(kBlue); // Color de la línea
    
    // Cambiar el tamaño de la fuente del eje Y
    TAxis *axisY = static_cast<TAxis*>(g2->GetYaxis());
    axisY->SetLabelSize(0.05);
    axisY->SetTitleSize(0.05);

    // Cambiar el tamaño de la fuente del eje X
    TAxis *axisX = static_cast<TAxis*>(g2->GetXaxis());
    axisX->SetLabelSize(0.05);
    axisX->SetTitleSize(0.05);

    g2->Draw("APL"); // Dibujar el gráfico con puntos y líneas
    pad->SetGrid();
    
  }
}
/////////////////////// Transmittance P Polarization //////////////////////////
void MyMainFrame::DoGraphFTIRPP(TPad *pad){
  
  if (pad) {

    int selectedIndex = ComboBoxN1->GetSelected();
    if (selectedIndex == 0) {
      double nn1 = 1.46;
    }
    if (selectedIndex == 1){
      double nn1 = 1.66;
    }

    if (selectedIndex == 2){
      double nn1 = 2.42;
    }

    // P polarization Graph
    TGraph *g1 = new TGraph();
    for (double ds = 0.0;  ds <= ( ValueThicknessN2->GetNumber())*1e-6; ds += 5e-8) {
      double n12 = nn1 * nn1;
      double n22 = nn2 * nn2;
      double st1c = TMath::Sin(ang) * TMath::Sin(ang);
      double y = TMath::Sqrt(n12 * st1c - n22) * (2 * TMath::Pi() * ds) / lamb;
      double N = nn1 / nn2;
      double n = nn3 / nn1;
      double ct1 = TMath::Cos(ang);
      double a = ((N * N) - 1) * ((n * n * N * N) - 1) / (4 * N * N * ct1 * ((N * N * st1c) - 1) * TMath::Sqrt(n * n - st1c));
      double ap = ((N * N + 1) * st1c - n * n) * (((n * n * N * N) + 1) * st1c - n * n) * (a / (n * n));
      double b = (TMath::Sqrt(n * n - st1c) + (n * n * ct1)) * (TMath::Sqrt(n * n - st1c) + (n * n * ct1)) / (4 * n * n * ct1 * TMath::Sqrt(n * n - st1c));
      double t = 1 / (ap * TMath::SinH(y) + b);
      
      g1->SetPoint(g1->GetN(), ds, t);
    }
  
    // Set graph title and axis labels
    g1->SetTitle("Transmittance of the wave with P polarization; Distance (\xB5m); Transmittance");
       
    g1->GetXaxis()->SetTitle("Distance (\xB5m)");
    g1->GetYaxis()->SetTitle("Transmittance");
    
    g1->SetMarkerStyle(20); // Estilo de los puntos
    g1->SetMarkerColor(4);
    g1->SetMarkerSize(1);  // Tamaño de los puntos
    g1->SetLineColor(kBlue); // Color de la línea
    
    // Cambiar el tamaño de la fuente del eje Y
    TAxis *axisY = static_cast<TAxis*>(g1->GetYaxis());
    axisY->SetLabelSize(0.05);
    axisY->SetTitleSize(0.05);

    // Cambiar el tamaño de la fuente del eje X
    TAxis *axisX = static_cast<TAxis*>(g1->GetXaxis());
    axisX->SetLabelSize(0.05);
    axisX->SetTitleSize(0.05);

    g1->Draw("APL"); // Dibujar el gráfico con puntos y líneas
    pad->SetGrid();
  }
}

////////////////////////////////// QT FUNCTION ////////////////////////////////////
double ft(double vo, double e, double hbar, double a, double me, double Eq) {
    double k = TMath::Sqrt(2 * me * (vo - e) * Eq) / hbar;
    double term1 = 4*(e/vo)*(1-(e/vo));
    double term2 = TMath::SinH(k * a);
    return 1.0 / (1.0 + (term2 * term2 / term1));
}

const double Vo = 15.0;
double E = 5.5;

void MyMainFrame::DoGraphQT(TPad *pad){

  if (pad) {
    double E  = ValuePotentialDifference->GetNumber();

    const double Hbar = 1.05457182E-34; // Constante de Planck reducida en J*s
    const double Me = 9.1e-31;    // Masa del electrón en kg
    const double EqEvJ = 1.6022E-019; //Equivalencia eV a Jules
      
    TGraph *g1 = new TGraph();
    
    //for (double ds = 0.0; ds <= 2.5e-10; ds += 1e-11) {
    for (double ds = 0.0; ds <= ValueBarrierWidth->GetNumber()*1e-10; ds += 0.5e-11) {
      double E  = ValuePotentialDifference->GetNumber();
      double t = ft(Vo, E, Hbar, ds, Me, EqEvJ);
      g1->SetPoint(g1->GetN(), ds, t);
    }
    
    g1->SetTitle("Transmittance coefficent of an electron; Width of the potential barrier (nm); Transmittance");

    g1->GetXaxis()->SetTitle("Width of the potential barrier (nm)");
    g1->GetYaxis()->SetTitle("Transmittance");
    g1->GetYaxis()->SetRangeUser(0, 1);
    
    g1->SetMarkerStyle(20);
    g1->SetMarkerColor(8);
    g1->SetMarkerSize(1);
    g1->SetLineColor(kGreen+3);

    // Cambiar el tamaño de la fuente del eje Y
    TAxis *axisY = static_cast<TAxis*>(g1->GetYaxis());
    axisY->SetLabelSize(0.05);
    axisY->SetTitleSize(0.05);

    // Cambiar el tamaño de la fuente del eje X
    TAxis *axisX = static_cast<TAxis*>(g1->GetXaxis());
    axisX->SetLabelSize(0.05);
    axisX->SetTitleSize(0.05);
    
    pad->SetGrid();
    g1->Draw("APL");
  }
}

//////////////////////////////////// QT SIMULATION //////////////////////////////

double waveFunction(double *x, double *params) {
  double X = x[0];
  double a = params[0];  // Ancho del potencial
  double A = params[1];  // Amplitud onda incidente
  double E = params[2];  // Energía
  double Vo = params[3]; // Energía del potencial
  
  double k = sqrt(E);
  double q = sqrt(Vo - E);

  std::complex<double> F = (2.0 * std::complex<double>(0.0, 1.0) * k * q * exp(-std::complex<double>(0.0, 1.0) * k * a) * A) / (2.0 * std::complex<double>(0.0, 1.0) * k * q * cosh(q * a) - (q * q - k * k) * sinh(q * a));

  std::complex<double> C = (1.0 + std::complex<double>(0.0, 1.0) * k / q) * F * exp(std::complex<double>(0.0, 1.0) * k * a) * exp(-q * a) / 2.0;

  std::complex<double> D = (1.0 - std::complex<double>(0.0, 1.0) * k / q) * F * exp(std::complex<double>(0.0, 1.0) * k * a) * exp(q * a) / 2.0;

  std::complex<double> B = ((1.0 - std::complex<double>(0.0, 1.0) * k / q) * F * exp(std::complex<double>(0.0, 1.0) * k * a) * exp(q * a) - (1.0 - std::complex<double>(0.0, 1.0) * k / q) * A) / (1.0 + std::complex<double>(0.0, 1.0) * k / q);
  
  // complex<double> F = (2.0 * 1i * k * q * exp(-1i * k * a) * A) / (2.0 * 1i * k * q * cosh(q * a) - (q * q - k * k) * sinh(q * a));
  //complex<double> C = (1.0 + 1i * k / q) * F * exp(1i * k * a) * exp(-q * a) / 2.0;
  // complex<double> D = (1.0 - 1i * k / q) * F * exp(1i * k * a) * exp(q * a) / 2.0;

  // complex<double> B = ((1.0 - 1i * k / q) * F * exp(1i * k * a) * exp(q * a) - (1.0 - 1i * k / q) * A) / (1.0 + 1i * k / q);
  
  if (X < 0) {
    //return real(A * exp(1i * k * X) + B * exp(-1i * k * X));
    double real_part = std::real(A * std::exp(std::complex<double>(0.0, 1.0) * k * X) + B * std::exp(-std::complex<double>(0.0, 1.0) * k * X));
    return real_part;
  } else if (X >= 0 && X <= a) {
    return real(D * exp(-q * X) + C * exp(q * X));
  } else {
    //return real(F * exp(1i * k * X));
    double real_part = std::real(F * std::exp(std::complex<double>(0.0, 1.0) * k * X));
    return real_part;
  }
}

void MyMainFrame::DoSimulationQT(TPad *pad){
  
  if (pad) {
    
    Double_t a = ValueBarrierWidth->GetNumber(); // Obtener el ancho del potencial
    Double_t A = 1.0; // Amplitud onda incidente
    Double_t E  = ValuePotentialDifference->GetNumber();
    Double_t j = (10.0 -  ValueBarrierWidth->GetNumber()) / 2;
    Double_t k = sqrt(E);
    Double_t q = sqrt(Vo - E);
    
    TF1 *wave = new TF1("wave", waveFunction, -10, 10, 4);
    wave->SetParameters(a, A, E, Vo); 
    wave->SetNpx(1000);
    wave->SetLineColor(kWhite);
    wave->SetTitle("");
    wave->Draw();
    
    // Configurar nombres de los ejes utilizando la clase TH1 asociada al gráfico
    TH1 *histogram = (TH1*)wave->GetHistogram();
    if (histogram) {
      histogram->GetXaxis()->SetTitle("Position (\305)");
      histogram->GetXaxis()->SetTitleSize(0.05);
      histogram->GetXaxis()->SetLabelSize(0.05);
      
      histogram->GetYaxis()->SetTitle("Wave Function");
      histogram->GetYaxis()->SetTitleSize(0.05);
      histogram->GetYaxis()->SetLabelSize(0.05);
      histogram->GetYaxis()->SetRangeUser(-1.6, 2.0); // Establecer el rango del eje y
    }
   
    if(a == 0){
      // No hay ancho de potencial
      //--------------------  Lineas izquierda
      TLine *L = new TLine(-10.0, 0.0, 10.0, 0.0);
      L->SetLineWidth(3);
      L->SetLineColor(kBlack);
      L->Draw();
    }
    else{
      //--------------------  Lineas izquierda
      TLine *L = new TLine(-10.0, 0.0, 0.0, 0.0);
      L->SetLineWidth(3);
      L->SetLineColor(kBlack);
      L->Draw("SAME");
      
      TLine *L1 = new TLine(0.0, 0.0, 0.0, 1.5);
      L1->SetLineWidth(3);
      L1->SetLineColor(kBlack);
      L1->Draw("SAME");
      
      // -------------------- Ancho del pozo 
      TLine *L2 = new TLine(0.0, 1.5, a, 1.5);
      L2->SetLineWidth(3);
      L2->SetLineColor(kBlack);
      L2->Draw();
      
      //--------------------- Ancho del pozo (flecha)
      TArrow *ar = new TArrow(0.0, 1.6, a, 1.6, 0.01,"<>");
      ar->SetAngle(45);
      ar->SetLineWidth(2);
      ar->SetLineColor(kBlue+1);
      ar->Draw();
      
      // --------------------- Lineas derecha
      TLine *L3 = new TLine(a,0.0,a, 1.5);
      L3->SetLineWidth(3);
      L3->SetLineColor(kBlack);
      L3->Draw();
      
      TLine *L4 = new TLine(a, 0.0, 10.0, 0.0);
      L4->SetLineWidth(3);
      L4->SetLineColor(kBlack);
      L4->Draw();
      
      TPad *pad = new TPad("pad","This is pad1", 0.45, 0.82, 0.65, 0.88);
      pad->SetFillColor(0);
      pad->Draw();
      pad->cd();
      TLatex *t1 = new TLatex(0.5, 0.8,"Barrier Width (\305)");
      t1->SetTextAlign(23);
      t1->SetTextSize(0.75);
      t1->Draw();
    }

    // Parte izquierda
    pad->cd();
    TF1 *wave_left = new TF1("wave_left", waveFunction, -10, 0, 4);
    wave_left->SetParameters(a, A, E, Vo);
    wave_left->SetNpx(1000);
    wave_left->SetLineColor(kRed);

    // Parte central
    TF1 *wave_center = new TF1("wave_center", waveFunction, 0, a, 4);
    wave_center->SetParameters(a, A, E, Vo);
    wave_center->SetNpx(1000);
    wave_center->SetLineColor(kRed);

    // Parte derecha
    TF1 *wave_right = new TF1("wave_right", waveFunction, a, 10, 4);
    wave_right->SetParameters(a, A, E, Vo);
    wave_right->SetNpx(1000);
    wave_right->SetLineColor(kRed);

    wave_left->Draw("SAME");
    pad->Update();

    gSystem->Sleep(500); // Wait for 500 milliseconds
    wave_center->Draw("SAME");
    pad->Update();

    gSystem->Sleep(500); // Wait for 500 milliseconds
    wave_right->Draw("SAME");
    pad->Update();

  }
}

////////////////////////////// WELCOME - HELP
void MyMainFrame::DoWelcome() {
  
  ButtonClear->TGTextButton::SetState(kButtonDisabled, kTRUE);

  TCanvas *c1 = ECanvas->GetCanvas();
  c1->SetFillColor(0);
  c1->Clear();
  c1->Update();

  TPad *pad1 = new TPad("pad1","This is pad1",0.01, 0.8, 0.99, 0.97);
  
  TPad *pad3 = new TPad("pad3","This is pad3", 0.01, 0.02, 0.74, 0.79);
  TPad *pad4 = new TPad("pad3","This is pad4", 0.74, 0.31, 1.0, 0.79);
  
  pad1->SetFillColor(0);
  pad3->SetFillColor(0);
  pad4->SetFillColor(0);

  pad1->Draw();
  pad3->Draw();
  pad4->Draw();
  
  pad1->cd();
  TLatex *t1 = new TLatex(0.5, 0.75,"CQT #color[2]{Soft}#color[4]{Edu}");
  TLatex *t2 = new TLatex(0.5, 0.45,"*Classical Quantum Tunneling #color[2]{Software }#color[4]{Education}");
  TLatex *t3 = new TLatex(0.5, 0.15,"Credits: UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS");
  t1->SetTextAlign(22);
  t1->SetTextSize(0.3);
  t2->SetTextAlign(21);
  t2->SetTextSize(0.2);
  t3->SetTextAlign(22);
  t3->SetTextSize(0.2);
  t1->Draw();
  t2->Draw();
  t3->Draw();

  TPaveText *pave = new TPaveText(0.0,0.05,0.49, 0.97);
  pave->SetTextAlign(10);
  pave->SetTextFont(42);
  pave->SetTextSize(0.032);
  pave->SetFillColor(kCyan-10);

  pave->AddText(" ");
  pave->AddText("#font[62]{Time-independent Schr#ddot{o}dinger eq:}");
  pave->AddText("\n");
  pave->AddText("#frac{-#hbar}{2m} #frac{#partial^{2}}{#partialx^{2}} #psi (x) + V(x)#psi (x) = E#psi (x)");
  pave->AddText("#font[62]{Quantum Tunneling:}");

  pave->AddText("Transmission coefficient: T =  #[]{ 1 + #frac{sinh^{2}(k_{d}a)}{4#eta(1-#eta)}} ");
  pave->AddText("\n");
  pave->AddText(" k_{d} = #frac{#sqrt{2m(V_{0}-E)}}{#hbar}   ;   #eta = #frac{E}{V_{0}}");

  pave->AddText("#font[62]{--------------------------------------------------------------}");
  pave->AddText("If you need more information about ");
  pave->AddText("Quantum Tunneling phenomena, you can go to ");
  pave->AddText("Eisberg, R. and Resnick, R. (1985)");
  pave->AddText(" Quantum Physics of Atoms, Molecules,");
  pave->AddText("Solids, Nuclei, and Particles. 2nd Edition,");
  pave->AddText("John Wiley & Sons, New York.");
 
  TPaveText *pavegui = new TPaveText(0.51, 0.05,0.99,0.97);
  pavegui->SetTextAlign(10);
  pavegui->SetTextFont(42);
  pavegui->SetTextColor(0);
  pavegui->SetTextSize(0.03);
  pavegui->SetFillColor(kRed-6);

  pavegui->AddText(" ");
  pavegui->AddText("You have the option to select the simulation that "); 
  pavegui->AddText("meets your requirements and proceed by clicking ");
  pavegui->AddText("the corresponding button.");
  pavegui->AddText("Options include  #font[62]{QUANTUM TUNNELING}, ");
  pavegui->AddText("#font[62]{FRUSTRATED TOTAL INTERNAL REFLECTION},");
  pavegui->AddText("or the #font[62]{ANALOGY} between these phenomena.");  
  pavegui->AddText("To pop up this GUI 'help' press #font[62]{HELP} ");
  pavegui->AddText(" ");
  pavegui->AddText("Please, keep in mind the QT software is intended "); 
  pavegui->AddText("for educational proposes only. It is suggested to "); 
  pavegui->AddText("run simulations by thinking of a decent step and ");
  pavegui->AddText("number of steps (it would cost an slowdown in cpu ");
  pavegui->AddText("performance).");
  pavegui->AddText(" ");
  pavegui->AddText("Without further ado, #scale[1.2]{#font[62]{let's hands ON !!}}");
  pavegui->AddText("Check your buttons and let's go to the... ");
  pavegui->AddText("                                ... #font[62]{QUANTUM TUNNELING!!}");
   

  TPaveText *pavecred = new TPaveText(0.03, 0.05, 0.95, 0.95);
  pavecred->SetTextAlign(10);
  pavecred->SetTextFont(42);
  pavecred->SetTextColor(0);
  pavecred->SetTextSize(0.055);
  pavecred->SetFillColor(kBlue-6);

  pavecred->AddText(" ");
  pavecred->AddText(" Autores: ");
  pavecred->AddText(" #font[62]{S Milena Agudelo G}, BS ");
  pavecred->AddText(" #font[62]{Julian A Salamanca B}, PHD ");
  pavecred->AddText(" ----------------------------------------");
  pavecred->AddText(" Bachelor's Degree in Physics");
  pavecred->AddText(" Research Group FISINFOR");
  pavecred->AddText(" Faculty of Science and Education");
  pavecred->AddText(" #font[72]{UNIVERSIDAD DISTRITAL}");
  pavecred->AddText(" #font[72]{FRANCISCO JOSE DE CALDAS}");
  
  pad3->cd();
  pave->Draw();
  pavegui->Draw();
  
  pad4->cd();
  pavecred->Draw();
  c1->Update();
}

////////////////////////////////////////////////// FRUSTRATED TOTAL INTERNAL REFLECTION ///////////////////////////////////////

void MyMainFrame::DoFTIR() {

  ButtonHelp->TGTextButton::SetState(kButtonDisabled, kTRUE);
  ButtonAnalogy->TGTextButton::SetState(kButtonDisabled, kTRUE);
  ButtonFTIR->TGTextButton::SetState(kButtonDisabled, kTRUE);
  ButtonQT->TGTextButton::SetState(kButtonDisabled, kTRUE);
  
  ButtonClear->TGTextButton::SetState(kButtonUp, kTRUE);

  TCanvas *c2 = ECanvas->GetCanvas();
  c2->SetFillColor(0);
  c2->Clear();
  c2->Update();
 
  TPad *PadEq = new TPad("","This is pad3", 0.01, 0.01, 0.33, 0.99);
  TPad *PadGr1 = new TPad("","This is pad6", 0.34, 0.44, 0.65, 0.99);
  TPad *PadGr2 = new TPad("","This is pad6", 0.66, 0.44, 0.99, 0.99);
  TPad *PadEx = new TPad("","This is pad4", 0.4, 0.01, 0.922, 0.42);

  PadEq->SetFillColor(0);
  PadEx->SetFillColor(0);
  PadGr1->SetFillColor(0);
  PadGr2->SetFillColor(0);
    
  PadEq->Draw();
  PadEx->Draw();
  PadGr1->Draw();
  PadGr2->Draw();
  
  PadEq->cd();

  TPaveText *pEQ = new TPaveText(0.01,0.01,0.99, 0.97);
  pEQ->SetTextAlign(10);
  pEQ->SetTextFont(42);
  pEQ->SetTextSize(0.035);
  pEQ->SetFillColor(kMagenta-10);

  pEQ->AddText(" ");
  pEQ->AddText("#font[62]{Frustrated Total Internal Reflection:}");
  pEQ->AddText("#font[62]{Transmission coefficient:}  #frac{1}{T} = #alpha sinh^{2}(y) + #beta ");

  pEQ->AddText("y=(#frac{2 #pi a}{#lambda})#left[n_{1}^{2} sin^{2}#left(#theta_{1}#right) - n_{2}^{2}#right]^{1 / 2}    ;    n = #frac{n_{3}}{n_{1}}    ;    N = #frac{n_{1}}{n_{2}} " );
  
  pEQ->AddText("#font[62]{----------------------------------------------------------------------}");
  pEQ->AddText("#font[62]{S polarization: }");
  pEQ->AddText("#alpha_{#perp}  =  #frac{#left(N^{2}-1#right)#left(n^{2} N^{2}-1#right)}{4 N^{2} cos #left(#theta_{1}#right)#left(N^{2} sen^{2}#left(#theta_{1}#right)-1#right)#left(n^{2} - sen^{2}#left(#theta_{1}#right)#right)^{1 / 2}}");

  pEQ->AddText("\n");
  pEQ->AddText("#beta_{#perp} = #frac{#left[#left(n^{2} - sen^{2}#left(#theta_{1}#right)#right)^{1 / 2} + cos #left(#theta_{1}#right)#right]^{2}}{4 cos #left(#theta_{1}#right)#left[n^{2} - sen^{2}#left(#theta_{1}#right)#right]^{1 / 2}}");
  
  pEQ->AddText("#font[62]{----------------------------------------------------------------------}");
  pEQ->AddText("#font[62]{P polarization: }");
  pEQ->AddText("#alpha_{#parallel} = #left(#frac{#alpha_{#perp}}{n^{2}}#right)#left[#left(N^{2}+1#right) sen^{2}#left(#theta_{1}#right)-n^{2}#right]#left[#left(n^{2} N^{2}+1#right) sen^{2}#left(#theta_{1}#right)-n^{2}#right]");

  pEQ->AddText("\n");
  pEQ->AddText("#beta_{#parallel} = #frac{#left[#left(n^{2} - sen^{2}#left(#theta_{1}#right)#right)^{1 / 2}+n^{2} cos #left(#theta_{1}#right)#right]^{2}}{4 n^{2} cos #left(#theta_{1}#right)#left[n^{2} - sen^{2}#left(#theta_{1}#right)#right]^{1 / 2}}");
    
  PadEq->cd();
  pEQ->Draw();
  
  PadEx->cd();
  PadEx->Range(-0.125, -0.125, 1.125, 1.125);
  pad1 = PadEx;
  DoSimulationFTIR(PadEx);

  c2->Update();
  
  // -------GRAFICAS
  PadGr1->cd();
  PadGr1->SetTopMargin(0.1); // Margen superior
  PadGr1->SetBottomMargin(0.15); // Margen inferior
  PadGr1->SetLeftMargin(0.15); // Margen izquierdo
  PadGr1->SetRightMargin(0.15); // Margen derecho
  DoGraphFTIRSP(PadGr1);

  c2->Update();
  gSystem->Sleep(500); // Wait for 500 milliseconds
  PadGr2->cd();
  PadGr2->SetTopMargin(0.1); // Margen superior
  PadGr2->SetBottomMargin(0.15); // Margen inferior
  PadGr2->SetLeftMargin(0.15); // Margen izquierdo
  PadGr2->SetRightMargin(0.15); // Margen derecho
  DoGraphFTIRPP(PadGr2);

  c2->Update(); 
}

//////////////////////////////////////////////////////// QUANTUM TUNNELING //////////////////////////////////////////////////////////

void MyMainFrame::DoQT(){

  ButtonHelp->TGTextButton::SetState(kButtonDisabled, kTRUE);
  ButtonAnalogy->TGTextButton::SetState(kButtonDisabled, kTRUE);
  ButtonFTIR->TGTextButton::SetState(kButtonDisabled, kTRUE);
  ButtonQT->TGTextButton::SetState(kButtonDisabled, kTRUE);
  
  ButtonClear->TGTextButton::SetState(kButtonUp, kTRUE);
  
  TCanvas *c3 = ECanvas->GetCanvas();
  c3->SetFillColor(0);
  c3->Clear();
  c3->Update();
  
  TPad *PadEq = new TPad("","This is pad3", 0.01, 0.01, 0.33, 0.99);
  TPad *PadEx = new TPad("","This is pad4", 0.332, 0.5, 1.0, 0.99);
  TPad *PadGr = new TPad("","This is pad5", 0.332, 0.01, 1.0, 0.5);

  PadEq->SetFillColor(0);
  PadEx->SetFillColor(0);
  PadGr->SetFillColor(0);
    
  PadEq->Draw();
  PadEx->Draw();
  PadGr->Draw();

  PadEq->cd();

  TPaveText *pEQ = new TPaveText(0.06,0.99,0.89, 0.6);
  pEQ->SetTextAlign(10);
  pEQ->SetTextFont(42);
  pEQ->SetTextSize(0.035);
  pEQ->SetFillColor(kGreen-10);

  pEQ->AddText(" ");
  pEQ->AddText("#font[62]{Time-independent Schr#ddot{o}dinger eq:}");
  pEQ->AddText("\n");
  pEQ->AddText("#frac{-#hbar}{2m} #frac{#partial^{2}}{#partialx^{2}} #psi (x) + V(x)#psi (x) = E#psi (x)");
  pEQ->AddText("#font[62]{Quantum Tunneling:}");
   
  pEQ->AddText("Transmission coefficient: T =  #[]{ 1 + #frac{sinh^{2}(k_{d}a)}{4#eta(1-#eta)}} ");
  pEQ->AddText("\n");
  pEQ->AddText(" k_{d} = #frac{#sqrt{2m(V_{0}-E)}}{#hbar}   ;   #eta = #frac{E}{V_{0}}");

  pEQ->Draw();

  TPad *F1 = new TPad("", "", 0.01, 0.01, 1.0, 0.55);
  F1->SetFillColor(0);
  F1->Range(-0.125,-0.125,1.125,1.125);
  F1->Draw();
  F1->cd();
  // -----------------------------   Ejes
  TArrow *y = new TArrow(0.0, 1.0, 0.0, 0.2, 0.04,"<|");
  y->SetAngle(45);
  y->SetLineWidth(2);
  y->SetLineColor(kGray+2);
  y->SetFillColor(kGray+2);
  y->Draw();
  
  TPad *pY = new TPad("padY","This is pad Y", 0.0, 0.9, 0.2, 0.95);
  pY->SetFillColor(0);
  pY->Draw();
  pY->cd();
  TLatex *tY = new TLatex(0.5, 0.75,"V");
  tY->SetTextAlign(23);
  tY->SetTextSize(0.8);
  tY->Draw();
  
  F1->cd();

  TPad *pP = new TPad("padY","This is pad E", 0.03, 0.63, 0.08, 0.68);
  pP->SetFillColor(0);
  pP->Draw();
  pP->cd();
  TLatex *tP = new TLatex(0.5, 0.75,"E");
  tP->SetTextAlign(23);
  tP->SetTextSize(0.8);
  tP->Draw();

  F1->cd();
  TPad *pV0 = new TPad("padY","This is pad V_{0}", 0.30, 0.7, 0.35, 0.75);
  pV0->SetFillColor(0);
  pV0->Draw();
  pV0->cd();
  TLatex *tV0 = new TLatex(0.5, 0.75,"V_{0}");
  tV0->SetTextAlign(23);
  tV0->SetTextSize(0.8);
  tV0->Draw();

  ////---------------  REGIONS LABELS
  // --- REGION I 
  F1->cd();
  TPaveText *p1 = new TPaveText(0.0, 0.22, 0.32, 0.65);
  p1->SetTextAlign(10);
  p1->SetTextFont(42);
  p1->SetTextSize(0.032);
  p1->SetFillColor(0); // Establecer el color de fondo a transparente
  p1->SetFillStyle(0); // Desactivar el relleno
  p1->SetBorderSize(0); // Desactivar el borde
  
  p1->AddText(" ");
  p1->AddText("#font[62]{Region I}");
  p1->AddText("#font[62]{X < 0:}");
  p1->AddText("\n");
  p1->AddText("#psi_{1}(x) = A exp(ikx)+ ...");
  p1->AddText ("... + B exp(-ikx)");
  p1->AddText("\n");
  p1->AddText("k^{2} = #frac{2mE}{#hbar^{2}}");
  p1->Draw();
  
  // --- REGION II
  F1->cd();
  TPaveText *p2 = new TPaveText(0.34, 0.22, 0.66, 0.7);
  p2->SetTextAlign(10);
  p2->SetTextFont(42);
  p2->SetTextSize(0.032);
  p2->SetFillColor(0); // Establecer el color de fondo a transparente
  p2->SetFillStyle(0); // Desactivar el relleno
  p2->SetBorderSize(0); // Desactivar el borde
  
  p2->AddText(" ");
  p2->AddText("#font[62]{Region II , 0 < X < a:}");
  p2->AddText("\n");
  p2->AddText("#psi_{2}(x) = C exp(qx) + ...");
  p2->AddText("... + D exp(-qx)");
  p2->AddText("\n");
  p2->AddText("q^{2} = #frac{2m(V_{0}-E)}{#hbar^{2}}");
  p2->Draw();
  
  // --- REGION III
  F1->cd();
  TPaveText *p3 = new TPaveText(0.69, 0.22, 0.95, 0.7);
  p3->SetTextAlign(10);
  p3->SetTextFont(42);
  p3->SetTextSize(0.032);
  p3->SetFillColor(0); // Establecer el color de fondo a transparente
  p3->SetFillStyle(0); // Desactivar el relleno
  p3->SetBorderSize(0); // Desactivar el borde
  
  p3->AddText(" ");
  p3->AddText("#font[62]{Region III , X > a:}");
  p3->AddText("\n");
  p3->AddText("#psi_{3}(x) = F exp(ikx)");
  p3->Draw();

  F1->cd();
    
  TArrow *x = new TArrow(0.0, 0.2, 1.08, 0.2, 0.04,"|>");
  x->SetAngle(45);
  x->SetLineWidth(2);
  x->SetLineColor(kGray+2);
  x->SetFillColor(kGray+2);
  x->Draw();

  TPad *pX = new TPad("padX","This is pad X", 0.92, 0.3, 0.97, 0.35);
  pX->SetFillColor(0);
  pX->Draw();
  pX->cd();
  TLatex *tX = new TLatex(0.5, 0.75,"X");
  tX->SetTextAlign(23);
  tX->SetTextSize(0.8);
  tX->Draw();

  F1->cd();

  ///////////////////////////////////////////////////////////
  
  // --------------------- Label ancho
  Double_t an = 0.32; // Valor del ancho  
  Double_t i = (1.0-an)/2; // Valor lateral

    //--------------------  Lineas izquierda
  TLine *L = new TLine(0.0, 0.2, i, 0.2);
  L->SetLineWidth(3);
  L->SetLineColor(kBlack);
  L->Draw();

  TLine *L1 = new TLine(i, 0.8, i, 0.2);
  L1->SetLineWidth(3);
  L1->SetLineColor(kBlack);
  L1->Draw();

  // -------------------- Ancho del pozo 
  TLine *L2 = new TLine(i, 0.8, i+an, 0.8);
  L2->SetLineWidth(3);
  L2->SetLineColor(kBlack);
  L2->Draw();

  //--------------------- Ancho del pozo (flecha)
  TArrow *ar = new TArrow(i, 0.1, i+an, 0.1, 0.01,"<>");
  ar->SetAngle(45);
  ar->SetLineWidth(2);
  ar->SetLineColor(kBlue+1);
  ar->Draw();
  
  // --------------------- Lineas derecha
  TLine *L3 = new TLine(i+an, 0.2, i+an, 0.8);
  L3->SetLineWidth(3);
  L3->SetLineColor(kBlack);
  L3->Draw();

  TLine *L4 = new TLine(i+an, 0.2, 2*i+an, 0.2);
  L4->SetLineWidth(3);
  L4->SetLineColor(kBlack);
  L4->Draw();

  TLine *LE = new TLine(0.0, 0.7, 0.98, 0.7);
  LE->SetLineWidth(3);
  LE->SetLineColor(kBlack);
  LE->SetLineStyle(2);
  LE->Draw();
 
  F1->cd();

  ////////////////////////////////////////////////////////////////
  
  TPad *pad = new TPad("pad","This is pad1", 0.25, 0.02, 0.75, 0.15);
  pad->SetFillColor(0);
  pad->Draw();
  pad->cd();

  TLatex *t1 = new TLatex(0.5, 0.75,"Barrier Width");
  t1->SetTextAlign(22);
  t1->SetTextSize(0.3);        
  t1->Draw();
  F1->Update();

  /////////////////////////// SIMULATION QT
  PadEx->cd();
  DoSimulationQT(PadEx);

  /////////////////////// Grafica
  PadGr->cd();
  DoGraphQT(PadGr);
  c3->Update();
  
}

/////////////////////////////////////////// ANALOGY /////////////////////////////////
void MyMainFrame::DoAnalogy(){
  
  ButtonHelp->TGTextButton::SetState(kButtonDisabled, kTRUE);
  ButtonAnalogy->TGTextButton::SetState(kButtonDisabled, kTRUE);
  ButtonFTIR->TGTextButton::SetState(kButtonDisabled, kTRUE);
  ButtonQT->TGTextButton::SetState(kButtonDisabled, kTRUE);
  
  ButtonClear->TGTextButton::SetState(kButtonUp, kTRUE);
  
  TCanvas *c4 = ECanvas->GetCanvas();
  c4->SetFillColor(0);
  c4->Clear();
  c4->Update();

  TPad *PadFTIRT = new TPad("","This is FTIR Title pad", 0.0, 0.95, 1.0, 1.0);
  TPad *PadFTIR = new TPad("","This is FTIR pad", 0.01, 0.5, 0.49, 0.95);

  TPad *PadQTT = new TPad("","This is QT Title pad", 0.0, 0.45, 1.0, 0.5);
  TPad *PadQT = new TPad("","This is QT pad", 0.0, 0.0, 0.5, 0.45);

  TPad *PadGrQT = new TPad("","This is Graph QT pad", 0.5, 0.0, 1.0, 0.45);

  TPad *PadGrFTIR1 = new TPad("","This is Graph FTIR pad", 0.5, 0.5, 0.75, 0.95);
  TPad *PadGrFTIR2 = new TPad("","This is Graph FTIR pad", 0.75, 0.5, 1.0, 0.95);

  PadQTT->SetFillColor(0);
  PadQT->SetFillColor(0);
  
  PadFTIRT->SetFillColor(0);
  PadFTIR->SetFillColor(0);
  
  PadGrQT->SetFillColor(0);
  PadGrFTIR1->SetFillColor(0);
  PadGrFTIR2->SetFillColor(0);
   
  PadQTT->Draw();
  PadQT->Draw();
  PadFTIRT->Draw();
  PadFTIR->Draw();
  PadGrQT->Draw();
  PadGrFTIR1->Draw();
  PadGrFTIR2->Draw();

  PadQTT->cd();
  TLatex *t1 = new TLatex(0.5, 0.7,"Quantum Tunelling");
  TLatex *t2 = new TLatex(0.5, 0.3,"*Transmittance coefficient analysis");
  
  t1->SetTextAlign(22);
  t1->SetTextSize(0.6);
  t2->SetTextAlign(22);
  t2->SetTextSize(0.3);
  t1->Draw();
  t2->Draw();

  PadFTIRT->cd();
  TLatex *t3 = new TLatex(0.5, 0.7,"Frustrated Total Internal Reflection");
  TLatex *t4 = new TLatex(0.5, 0.3,"*Transmittance coefficient analysis");
  
  t3->SetTextAlign(22);
  t3->SetTextSize(0.6);
  t4->SetTextAlign(22);
  t4->SetTextSize(0.3);
  t3->Draw();
  t4->Draw();

  PadFTIR->cd();
  PadFTIR->Range(-0.125, -0.125, 1.125, 1.125);
  pad1 = PadFTIR;
  DoSimulationFTIR(PadFTIR);

  c4->Update();
  gSystem->Sleep(500); // Wait for 500 milliseconds
  PadGrFTIR1->cd();

  PadGrFTIR1->SetTopMargin(0.1); // Margen superior
  PadGrFTIR1->SetBottomMargin(0.15); // Margen inferior
  PadGrFTIR1->SetLeftMargin(0.15); // Margen izquierdo
  PadGrFTIR1->SetRightMargin(0.15); // Margen derecho
  DoGraphFTIRSP(PadGrFTIR1);

  c4->Update();
  gSystem->Sleep(500); // Wait for 500 milliseconds
  PadGrFTIR2->cd();
  
  PadGrFTIR2->SetTopMargin(0.1); // Margen superior
  PadGrFTIR2->SetBottomMargin(0.15); // Margen inferior
  PadGrFTIR2->SetLeftMargin(0.15); // Margen izquierdo
  PadGrFTIR2->SetRightMargin(0.15); // Margen derecho
  DoGraphFTIRPP(PadGrFTIR2);

  c4->Update();
  gSystem->Sleep(500); // Wait for 500 milliseconds
  PadQT->cd();
  DoSimulationQT(PadQT);

  c4->Update();
  gSystem->Sleep(500); // Wait for 500 milliseconds
  PadGrQT->cd();
  DoGraphQT(PadGrQT);

   
  c4->Update();
}

///////////////////////////////////////////////////  DESTRUCTOR ////////////////////////////////////////////////////////////////////
MyMainFrame::~MyMainFrame() {
  Main->Cleanup();
  delete Main;
}

///////////////////////////////////////////////////  MAIN ///////////////////////////////////////////////////////////////////////////
void QT_SE() {
  // Popup the GUI...
  new MyMainFrame(gClient->GetRoot(),1100,700);
}

int main(int argc, char **argv) {
  TApplication theApp("App",&argc,argv);
  QT_SE();
  theApp.Run();
  return 0;
}
