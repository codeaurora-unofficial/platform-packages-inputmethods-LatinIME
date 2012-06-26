/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LATINIME_INCREMENTAL_DECODER_INTERFACE_H
#define LATINIME_INCREMENTAL_DECODER_INTERFACE_H

#include "bigram_dictionary.h"
#include "defines.h"
#include "proximity_info.h"
#include "unigram_dictionary.h"

namespace latinime {

class IncrementalDecoderInterface {

 public:
    virtual int getSuggestions(ProximityInfo *pInfo, int *inputXs, int *inputYs, int *times,
            int *pointerIds, int *codes, int inputSize, int commitPoint, bool isMainDict,
            unsigned short *outWords, int *frequencies, int *outputIndices) = 0;
    virtual void reset() = 0;
    virtual void setDict(const UnigramDictionary *dict, const BigramDictionary *bigram) = 0;
    virtual void setPrevWord(const int32_t *prevWord, int prevWordLength) = 0;
    virtual ~IncrementalDecoderInterface() { };
};
} // namespace latinime

#endif // LATINIME_INCREMENTAL_DECODER_INTERFACE_H
