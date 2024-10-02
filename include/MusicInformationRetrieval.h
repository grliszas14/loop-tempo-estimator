/*  SPDX-License-Identifier: GPL-2.0-or-later */
/*!********************************************************************

  Audacity: A Digital Audio Editor

  MusicInformationRetrieval.h

  Matthieu Hodgkinson

**********************************************************************/
#pragma once

#include "MirTypes.h"

#include <functional>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace MIR
{
class MirAudioReader;

struct LoopClassifierSettings
{
   /*!
    * False positive rate allowed for the classifier.
    */
   const double allowedFalsePositiveRate;

   /*!
    * Classifier score threshold above which the analyzed audio file can be
    */
   const double threshold;
};

/*!
 * Tolerance-dependent thresholds, used internally by
 * `GetMusicalMeterFromSignal` to decide whether to return a null or valid
 * `MusicalMeter`. The value compared against these are scores which get higher
 * as the signal is more likely to contain music content. They are obtained by
 * running the `TatumQuantizationFitBenchmarking` test case. More information
 * there.
 */
static const std::unordered_map<FalsePositiveTolerance, LoopClassifierSettings>
   loopClassifierSettings {
      { FalsePositiveTolerance::Strict, { .04, 0.8679721717368254 } },
      { FalsePositiveTolerance::Lenient, { .1, 0.7129778875046098 } },
   };

std::optional<MusicalMeter> GetMusicalMeterFromSignal(
   const MirAudioReader& source, FalsePositiveTolerance tolerance,
   const std::function<void(double)>& progressCallback,
   QuantizationFitDebugOutput* debugOutput = nullptr);
} // namespace MIR
