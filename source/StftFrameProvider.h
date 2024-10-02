/*  SPDX-License-Identifier: GPL-2.0-or-later */
/*!********************************************************************

  Audacity: A Digital Audio Editor

  StftFrameProvider.h

  Matthieu Hodgkinson

**********************************************************************/
/*

 This file was copied from Audacity 3.5.1,
 https://github.com/audacity/audacity/releases/tag/Audacity-3.5.1.

 Modifications might have been made to remove dependencies on Audacity code and
 when renaming files. The algorithm remains the same.

 */
#pragma once

#include "PowerSpectrumGetter.h"
#include <vector>


namespace LTE
{
class MirAudioReader;

/*!
 * Utility class to provide time-domain frames ready for FFT. The returned
 * frames have power-of-two size and are already windowed with a Hann window,
 * scaled such that it sums to unity. Also, `GetNumFrames()` is the closest
 * power of two that satifsies a hop size of 10ms. This property facilitates the
 * FFT analysis of transformation of the STFT frames to some scalar, e.g. the
 * novelty values of an onset detection function.
 */
class StftFrameProvider
{
public:
   StftFrameProvider(const MirAudioReader& source);
   bool GetNextFrame(PffftFloatVector& frame);
   int GetNumFrames() const;
   int GetSampleRate() const;
   double GetFrameRate() const;
   int GetFftSize() const;

private:
   const MirAudioReader& mAudio;
   const int mFftSize;
   const double mHopSize;
   const std::vector<float> mWindow;
   const int mNumFrames;
   const long long mNumSamples;
   int mNumFramesProvided = 0;
};
} // namespace LTE