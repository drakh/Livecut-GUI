/*
 This file is part of Livecut
 Copyright 2003 by Remy Muller.
 
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

#ifndef LIVECUT_CONTROL_H
#define LIVECUT_CONTROL_H

#include "../JuceLibraryCode/JuceHeader.h"

class Control : public AudioProcessorListener, AsyncUpdater
{
public:
  Control(AudioProcessor &effect, int paramId);
  virtual ~Control();
  
  virtual void refresh() = 0;
  
  virtual void setParameter(const float val);
  virtual float getParameter();
  
private:
  virtual void audioProcessorParameterChanged (AudioProcessor* processor,
                                               int parameterIndex,
                                               float newValue);
  virtual void audioProcessorChanged (AudioProcessor* processor, const ChangeDetails &details);
  virtual void handleAsyncUpdate();
  
protected:
  AudioProcessor &mEffect;
  int mParamId;
};

#endif
