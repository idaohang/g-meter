/*
Copyright_License {

  G-Meter INU.
  Copyright (C) 2013-2014 Peter F Bradshaw
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#include "Native/com_exadios_g_meter_Timer.h"
#include "Executive/Android/Timer.hpp"

/*
 * Class:     com_exadios_g_meter_Timer
 * Method:    run
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_exadios_g_1meter_Timer_run
  (JNIEnv *env, jobject obj, jlong t)
  {
  Timer::Instance().Tick(env, obj, t);
  }
