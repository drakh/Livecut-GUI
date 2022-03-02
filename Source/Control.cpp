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

#include "Control.h"

Control::Control(AudioProcessor &effect, int paramId)
: mEffect(effect)
, mParamId(paramId)
{
  mEffect.addListener(this);
  triggerAsyncUpdate();
}

Control::~Control() 
{
  mEffect.removeListener(this);
}

void Control::setParameter(const float val)
{
  mEffect.setParameterNotifyingHost(mParamId, val);
}

float Control::getParameter()
{
  return mEffect.getParameter(mParamId);
}

void Control::audioProcessorParameterChanged (AudioProcessor* processor,
                                              int parameterIndex,
                                              float newValue)
{
  triggerAsyncUpdate();
}

void Control::audioProcessorChanged (AudioProcessor* processor, const ChangeDetails &details)
{
  triggerAsyncUpdate();
}

void Control::handleAsyncUpdate()
{
  refresh();
}
