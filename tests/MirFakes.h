/*  SPDX-License-Identifier: GPL-2.0-or-later */
/*!********************************************************************

  Audacity: A Digital Audio Editor

  MirFakes.h

  Matthieu Hodgkinson

**********************************************************************/
#pragma once

#include "MirTypes.h"

namespace MIR
{

class EmptyMirAudioReader : public MirAudioReader
{
   double GetSampleRate() const override
   {
      return 0;
   }
   long long GetNumSamples() const override
   {
      return 0;
   }
   void
   ReadFloats(float* buffer, long long start, size_t numFrames) const override
   {
   }
};

class SquareWaveMirAudioReader : public MirAudioReader
{
   const int period = 8;

   double GetSampleRate() const override
   {
      return 10;
   }
   long long GetNumSamples() const override
   {
      return period * 10;
   }
   void
   ReadFloats(float* buffer, long long where, size_t numFrames) const override
   {
      for (size_t i = 0; i < numFrames; ++i)
         buffer[i] = (where + i) % period < period / 2 ? 1.f : -1.f;
   }
};

} // namespace MIR
