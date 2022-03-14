/*
 This file is part of Livecut
 Copyright 2004 by Remy Muller.
 
 Livecut can be redistributed and/or modified under the terms of the
 GNU General Public License, as published by the Free Software Foundation;
 either version 2 of the License, or (at your option) any later version.
 
 Livecut is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Livecut; if not, visit www.gnu.org/licenses or write to the
 Free Software Foundation, Inc., 59 Temple Place, Suite 330, 
 Boston, MA 02111-1307 USA
 */

#include "LivecutProcessor.h"
#include "LivecutEditor.h"
#include "ParamButton.h"
#include "ParamSlider.h"
#include "ParamLabel.h"
#include "LivecutLookAndFeel.h"

static const int toolbarHeight = 30;
static const int buttonWidth = 60;
static const int buttonHeight = 20;
static const int margin = 5;

enum 
{
  kParamSlider=0,
  kParamKnob,
  kParamName,
  kParamValue,
  kParamButton
};

LivecutAudioProcessorEditor::LivecutAudioProcessorEditor (LivecutAudioProcessor* ownerFilter)
: AudioProcessorEditor (ownerFilter)
{
  if(&LookAndFeel::getDefaultLookAndFeel() != &LivecutLookAndFeel::getInstance())
  {
    LookAndFeel::setDefaultLookAndFeel(&LivecutLookAndFeel::getInstance());
  }
  
  setSize (790+10, 480+10);
   
 /*
  {
    ParamButton *pParamButton = new ParamButton(*ownerFilter, 23);
    pParamButton->setBounds(385, 195, buttonWidth, buttonHeight);
    addAndMakeVisible(pParamButton);
  }
  {
    ParamButton *pParamButton = new ParamButton(*ownerFilter, 28);
    pParamButton->setBounds(385, 345, buttonWidth, buttonHeight);
    addAndMakeVisible(pParamButton);
  }
  
  for(int i=2; i<20; ++i)
  {
    ParamSlider *pParamSlider = new ParamSlider(*ownerFilter, i);
    pParamSlider->setBounds(margin, toolbarHeight+(2+i)*margin+(1+i)*buttonHeight, buttonWidth, buttonHeight);
    addAndMakeVisible(pParamSlider);

    {
      ParamLabel *pParamLabel = new ParamLabel(*ownerFilter, i, ParamLabel::showParameterValue);
      pParamLabel->setBounds(margin+buttonWidth+margin, toolbarHeight+(2+i)*margin+(1+i)*buttonHeight, buttonWidth, buttonHeight);
      addAndMakeVisible(pParamLabel);
    }
    {
      ParamLabel *pParamLabel = new ParamLabel(*ownerFilter, i, ParamLabel::showParameterName);
      pParamLabel->setBounds(margin+(buttonWidth+margin)*2, toolbarHeight+(2+i)*margin+(1+i)*buttonHeight, buttonWidth, buttonHeight);
      addAndMakeVisible(pParamLabel);
    }
  }
   */
}

LivecutAudioProcessorEditor::~LivecutAudioProcessorEditor()
{
  deleteAllChildren();
}

void LivecutAudioProcessorEditor::addSlider(int paramId, 
                                            int row, 
                                            int col)
{
  addControl(kParamName, paramId, row, col, 1, 3);
  addControl(kParamSlider, paramId, row, col+2, 1, 4);
  addControl(kParamValue, paramId, row, col+6, 1, 3);
}

void LivecutAudioProcessorEditor::addButton(int paramId, 
                                            int row, 
                                            int col)
{
    addControl(kParamButton, paramId, row, col, 1, 2);
}

void LivecutAudioProcessorEditor::addKnob(int paramId, 
                                            int row, 
                                            int col)
{
  AudioProcessor &processor = *getAudioProcessor();
  
  int colSpan = 2;
  int rowSpan = 2;
  int x = 10+30*col;
  int y = 10+30*row;
  int width = 20 + 30*(colSpan-1);
  int height = 20 + 30*(rowSpan-1);
  
  ParamLabel *pParamLabel = new ParamLabel(processor, paramId, ParamLabel::showParameterName); 
  pParamLabel->setColour(Label::textColourId, Colours::black);
  pParamLabel->setBounds(x, y, width, 20);
  pParamLabel->setJustificationType(Justification::centred);
  addAndMakeVisible(pParamLabel);
  
  ParamSlider *pSlider = new ParamSlider(processor, paramId); 
  pSlider->setSliderStyle(Slider::RotaryVerticalDrag);
  pSlider->setBounds(x, y+20, width, height-20);
  addAndMakeVisible(pSlider);
}

void LivecutAudioProcessorEditor::addIncDec(int paramId, 
                                            int row, 
                                            int col,
                                            int incDecNumberOfValues)

{
  AudioProcessor &processor = *getAudioProcessor();
  
  int buttonsColSpan = 4;
  int buttonsRowSpan = 1;
  int buttonsX = 10+30*(col+2);
  int buttonsY = 10+30*row;
  int buttonsWidth = 20 + 30*(buttonsColSpan-1);
  int buttonsHeight = 20 + 30*(buttonsRowSpan-1);
  double interval = 1.0 / (incDecNumberOfValues - 1);
  
  addControl(kParamName, paramId, row, col, 1, 3);
  
  ParamSlider *pSlider = new ParamSlider(processor, paramId); 
  pSlider->setSliderStyle(Slider::IncDecButtons);
  pSlider->setRange(0, 1, interval);
  pSlider->setBounds(buttonsX, buttonsY, buttonsWidth, buttonsHeight);
  addAndMakeVisible(pSlider);
  
  addControl(kParamValue, paramId, row, col+6, 1, 3);
  
}

void LivecutAudioProcessorEditor::addControl(int kind, 
                                             int paramId, 
                                             int row, 
                                             int col, 
                                             int rowSpan, 
                                             int colSpan)
{
  AudioProcessor &processor = *getAudioProcessor();
  
  int x = 10+30*col;
  int y = 10+30*row;
  int width = 20 + 30*(colSpan-1);
  int height = 20 + 30*(rowSpan-1);
  
  juce::Component *pControl = NULL;
  switch (kind) 
  {
    case kParamSlider: pControl = new ParamSlider(processor, paramId); break;
    case kParamKnob: 
    {
      ParamSlider *pSlider = new ParamSlider(processor, paramId); 
      pSlider->setSliderStyle(Slider::RotaryVerticalDrag);
      pControl = pSlider;
      break;
    }
    case kParamName: pControl = new ParamLabel(processor, paramId, ParamLabel::showParameterName); break;
    case kParamValue: pControl = new ParamLabel(processor, paramId, ParamLabel::showParameterValue); break;
    case kParamButton: pControl = new ParamButton(processor, paramId); break;
    default:
      break;
  }
  
  if(pControl)
  {
    addAndMakeVisible(pControl);
    pControl->setBounds(x, y, width, height);
  }
}

void LivecutAudioProcessorEditor::paintOverChildren (Graphics& g)
{  
}

//static const char* sectionNames[] = 
//{
//  "Global", "Pitch", "Env", 
//  "CutProc11", "WarpCut", "SQPusher", 
//  "Amplifier", "Crusher", "Comb"
//};

void LivecutAudioProcessorEditor::paint (Graphics& g)
{
  g.fillAll (Colours::white);
  
  /* // grid
  for(uint col=0; col<24; ++col)
  {
    int x = 10+col*(20+10);
    
    g.setColour(Colours::black);
    g.drawText(String(col), Rectangle<int>(x, 0, 20, getHeight()), Justification::topLeft, false);
    
    g.setColour(Colours::red.withAlpha(0.1f));
    g.fillRect(x, 0, 20, getHeight());
  }
  
  for(uint row=0; row<16; ++row)
  {
    int y = 10+row*(20+10);
    
    g.setColour(Colours::black);
    g.drawText(String(row), Rectangle<int>(0, y, getWidth(), 20), Justification::topLeft, false);
    
    g.setColour(Colours::red.withAlpha(0.1f));
    g.fillRect(0, y, getWidth(), 20);
  }
  */  
  
  g.setColour(Colours::darkgrey);
  g.setFont(juce::Font(20.0f, juce::Font::bold));

  g.drawLine(0, 30, getWidth(), 30);
  g.drawFittedText ("Livecut",
                    10, 10, getWidth()-20, 20,
                    Justification::centredLeft, 1);      

  g.setFont(juce::Font(15.0f, juce::Font::bold));
  g.drawFittedText ("Mdsp @ Smartelectronix",
                    10, 10, getWidth()-20, 20,
                    Justification::centredRight, 1);      
  
  g.setColour(Colour(0xffBA7500));
  g.setFont(juce::Font(15.0f, juce::Font::bold));
  g.drawFittedText ("CutProc",
                    10, 50, getWidth()-20, 20,
                    Justification::centredLeft, 1); 
  
  g.drawFittedText ("Global",
                    10, 110, getWidth()-20, 20,
                    Justification::centredLeft, 1); 
                    
  g.drawFittedText ("Pitch",
                    10, 260, getWidth()-20, 20,
                    Justification::centredLeft, 1);
                    
  g.drawFittedText ("Env",
                    10, 350, getWidth()-20, 20,
                    Justification::centredLeft, 1);
                    
  g.drawFittedText ("Amp",
                    280, 50, getWidth()-20, 20,
                    Justification::centredLeft, 1);
                    
  g.drawFittedText ("BitCrusher",
                    280, 200, getWidth()-20, 20,
                    Justification::centredLeft, 1);
                    
  g.drawFittedText ("Comb",
                    280, 350, getWidth()-20, 20,
                    Justification::centredLeft, 1);

  g.drawFittedText ("CutProc11",
                    550, 50, getWidth()-20, 20,
                    Justification::centredLeft, 1);
                    
  g.drawFittedText ("WarpCut",
                    550, 200, getWidth()-20, 20,
                    Justification::centredLeft, 1);
                    
  g.drawFittedText ("SQPusher",
                    550, 350, getWidth()-20, 20,
                    Justification::centredLeft, 1);
  
  g.setColour(Colours::darkgrey);
  g.setFont(juce::Font(14.0f, juce::Font::bold));
  g.drawFittedText ("Original algorithms by Nick Collins\nhttp://www.cus.cam.ac.uk/~nc272/\nin BBCut library for Supercollider",
                    550, 385, 220, 100,
                    Justification::centredLeft, 1);

  g.setFont(juce::Font(18.0f, juce::Font::bold));
  g.drawFittedText ("www.smartelectronix.com",
                    10, 450, 200, 50,
                    Justification::centredLeft, 1);
 
//  for(uint row=0; row<3; ++row)
//  {
//    int y = 40+150*row;
//    int width = 240-10;
//    int height = 150-10;
//    for(uint col=0; col<3; ++col)
//    {
//      int x = 10 + 240*col;
//      g.drawRect(x, y, width, height);
//  
//      String text(sectionNames[row*3+col]);
//      g.drawFittedText (text,
//                        x, y, width, 20,
//                        Justification::centred, 1);      
//    }
//  }
}

