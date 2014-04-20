/*
 * G-Meter INU.
 * Copyright (C) 2009-2014 Max Kellermann <max@duempel.org> and 
 * Peter F Bradshaw
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DEVICEINPUTBUFFER_HPP
#define DEVICEINPUTBUFFER_HPP

#include "PosixMutex.hpp"

/**
 * Base class for clocked input data.
 */
class DeviceInputBuffer
  {
  /**
   * Ctor.
   */
  DeviceInputBuffer();

  /**
   * Dtor.
   */
  virtual ~DeviceInputBuffer();

  /**
   * Clock the buffering. Call this when we need the latest data.
   */
  void Clock();

  /**
   * Check whether new data is avaliable.
   * @return If avaliable then true.
   */
  bool Dirty();

protected:

  PosixMutex locker;
  int  b;                // Input index;
  int  b_bar;            // Output index;
  bool dirty;            // If true then new data is avaliable;
  };

#endif  // DEVICEINPUTBUFFER_HPP