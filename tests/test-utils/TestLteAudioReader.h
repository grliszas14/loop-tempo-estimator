/*  SPDX-License-Identifier: GPL-2.0-or-later */
/*!********************************************************************

  Audacity: A Digital Audio Editor

  WaveMirAudioReader.h

  Matthieu Hodgkinson

**********************************************************************/
/*

 This file was copied from Audacity 3.5.1,
 https://github.com/audacity/audacity/releases/tag/Audacity-3.5.1.

 Modifications might have been made to remove dependencies on Audacity code and
 when renaming files. The algorithm remains the same.

EDIT: Commit "Simplify and improve algorithm by considering only 4/4" improves
quality of classifier and possibly time performance, too.

 */
#pragma once

#include "LoopTempoEstimator/LteTypes.h"

#include <optional>
#include <string>
#include <vector>

namespace LTE
{
class TestLteAudioReader : public LteAudioReader
{
public:
   TestLteAudioReader(
      const std::string& filename, std::optional<double> timeLimit = {});

   double GetSampleRate() const override;
   long long GetNumSamples() const override;
   void
   ReadFloats(float* buffer, long long start, size_t numFrames) const override;

private:
   const std::vector<float> mSamples;
   const double mSampleRate = 0.;
};
} // namespace LTE
