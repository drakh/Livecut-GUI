# Livecut-GUI

This repository contains modified source code for the Livecut beat-slicer audio plugin, which can be used to build Livecut with JUCE 6.1.5. Livecut code originally from https://github.com/mdsp/Livecut with changes here to allow it to build and provide a fully working GUI. As the original source code didn't include a fully working GUI, some of the legacy code has been recycled to build a GUI with access to all parameters.

Note that with some export formats, such as VST3, plugin parameters may not be saved by plugin hosts. Parameters should save properly with older formats, but they haven't been tested.

An LV2 port can be found at https://github.com/eventual-recluse/Livecut-LV2. Parameters should be saved properly by plugin hosts with the LV2 version.


Livecut
=======

Livecut is based on [BBCut](http://www.cus.cam.ac.uk/~nc272/papers/pdfs/bbcutlib.pdf) the BreakBeat Cutting library written by [Nick Collins](http://www.cus.cam.ac.uk/~nc272/) for [SuperCollider](http://supercollider.sourceforge.net/)

The BBCut Library began out of work on an algorithm to simulate the automatic cutting of breakbeats in the style of early jungle or drum and bass, Nick Collins.

Livecut is only a small subset of what is possible with BBCut, but as it is available as a VST plugin, it is much easier to start experimenting with it.

It is a live beat-slicer but instead of manipulating equal chunks of audio like most beatslicer do, it works on the notion of audio *cuts* whose length and number of repetition depends on the context and the cutting procedure. 
*Cuts* are organized in *blocks* which then form a *phrase*. see Image below. And each phrase can be ended by a *roll* or *fill*.
-------

# Livecut license:

This file is part of Livecut Copyright 2003 by Remy Muller.

Livecut can be redistributed and/or modified under the terms of the GNU General Public License, as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

Livecut is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with AnalogDelay; if not, visit www.gnu.org/licenses or write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

This repository is kept for reference only and won't be updated.
