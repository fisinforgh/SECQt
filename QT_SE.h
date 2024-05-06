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
//   https://github.com/fisinforgh/ FALTA                                  //
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

#include <TQObject.h>
#include <RQ_OBJECT.h>
#include "TPad.h"

class TGWindow;
class TGMainFrame;
class TGHorizontalFrame;
class TGVerticalFrame;
class TRootEmbeddedCanvas;
class TCanvas;
class TGIcon;
class TGGroupFrame;
class TGTextButton;
class TGLabel;
class TGHorizontal3DLine;

class TGComboBox;
class TGNumberEntry;
class TPad;

class MyMainFrame {
  RQ_OBJECT("MyMainFrame")
  
  private:

  //--------------------------Desing-------------------------
  TGMainFrame         *Main;
  
  TGHorizontalFrame   *HFramePrincipal;
  TGHorizontalFrame   *HFrameButtons;
  TGHorizontalFrame   *HFrameButtons1;
  TGHorizontalFrame   *HFrameButtons2;

  TGVerticalFrame     *VerticalFrameButton;
  TGVerticalFrame     *VFrameRefractiveIndex;
  TGVerticalFrame     *VFrameThicknessN2;
  TGVerticalFrame     *VFramePotentialDifference;
  TGVerticalFrame     *VFrameBarrierWidth;
  TGVerticalFrame     *VFrameLOGO1;
  TGVerticalFrame     *VFrameButtons;
  TGVerticalFrame     *VFrameLOGO2;
  TGVerticalFrame     *VFrameLOGO3;
  
  TRootEmbeddedCanvas *ECanvas;
  TCanvas             *fCanvas;

  TGIcon              *LogoAPP;
  TGIcon              *LogoUD;
  TGIcon              *LogoFISINFOR;

  TGGroupFrame        *GroupFrameFTIR;
  TGGroupFrame        *GroupFrameQT;

  TGTextButton        *ButtonQT;
  TGTextButton        *ButtonFTIR;
  TGTextButton        *ButtonAnalogy; 
  TGTextButton        *ButtonHelp;
  TGTextButton        *ButtonDraw;
  TGTextButton        *ButtonClear;
  TGTextButton        *ButtonExit;

  TGLabel             *Label1;
  TGLabel             *Label2;
  TGLabel             *Label3;
  TGLabel             *Label4;
  TGLabel             *Label5;

  TGHorizontal3DLine  *Line1;
  
public:
  TGComboBox          *ComboBoxN1;
  TGComboBox          *ComboBoxN2;
  
  TGNumberEntry       *ValueThicknessN2; 
  TGNumberEntry       *ValuePotentialDifference; 
  TGNumberEntry       *ValueBarrierWidth;
  
  MyMainFrame(const TGWindow *p,UInt_t w,UInt_t h);
  virtual ~MyMainFrame();
  
  //FUNCIONES PRINCIPALES
  void DoHelp();
  void DoWelcome();
  void DoExit();
  void DoClear();
  
  //FUNCIONES QT
  void DoQT();
  void DoFTIR();
  void DoAnalogy();

  //-- SIMULATIONS AND GRAPHS
  void DoSimulationQT(TPad *pad);
  void DoGraphQT(TPad *pad);
 
  void DoSimulationFTIR(TPad *pad);
  void DrawNextVector();
  
  void DoGraphFTIRSP(TPad *pad);
  void DoGraphFTIRPP(TPad *pad);

};
