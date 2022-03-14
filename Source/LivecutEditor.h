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

#ifndef LIVECUT_EDITOR_H
#define LIVECUT_EDITOR_H

#include "../JuceLibraryCode/JuceHeader.h"
#include "LivecutProcessor.h"

class LivecutAudioProcessorEditor  : public AudioProcessorEditor
{  
public:
  LivecutAudioProcessorEditor (LivecutAudioProcessor* ownerFilter);
  ~LivecutAudioProcessorEditor();

  void addSlider(int paramId, 
                 int row, 
                 int col);

  void addKnob(int paramId, 
               int row, 
               int col);
               
  void addIncDec(int paramId, 
                 int row, 
                 int col,
                 int incDecNumberOfValues);
                 
  void addButton(int paramId, 
                 int row, 
                 int col);
private:
  
  void addControl(int kind, 
                  int paramId, 
                  int row, 
                  int col, 
                  int rowSpan, 
                  int colSpan);
  
private:
  void paint (Graphics& g);
  void paintOverChildren (Graphics& g);
};


#endif  
