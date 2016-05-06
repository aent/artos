/**
 * Copyright (c) 2016, Alexander Entinger
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of artos nor the names of its
 *  contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DRIVERS_DRV2605_DRV2605REGACCESS_H_
#define DRIVERS_DRV2605_DRV2605REGACCESS_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "../I2CInterface.h"

namespace artos
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

typedef enum
{
   STATUS       = 0x00,
   MODE         = 0x01,
   RTPIN        = 0x02,
   LIBRARY      = 0x03,
   WAVESEQ1     = 0x04,
   WAVESEQ2     = 0x05,
   WAVESEQ3     = 0x06,
   WAVESEQ4     = 0x07,
   WAVESEQ5     = 0x08,
   WAVESEQ6     = 0x09,
   WAVESEQ7     = 0x0A,
   WAVESEQ8     = 0x0B,
   GO           = 0x0C,
   OVERDRIVE    = 0x0D,
   SUSTAINPOS   = 0x0E,
   SUSTAINNEG   = 0x0F,
   BREAK        = 0x10,
   AUDIOCTRL    = 0x11,
   AUDIOLVL     = 0x12,
   AUDIOMAX     = 0x13,
   RATEDV       = 0x16,
   CLAMPV       = 0x17,
   AUTOCALCOMP  = 0x18,
   AUTOCALEMP   = 0x19,
   FEEDBACK     = 0x1A,
   CONTROL1     = 0x1B,
   CONTROL2     = 0x1C,
   CONTROL3     = 0x1D,
   CONTROL4     = 0x1E,
   VBAT         = 0x21,
   LRARESON     = 0x22
} EDRV2605RegAddr;

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class DRV2605RegAccessor
{

public:

private:

  /* No public construction/destructionn */

  DRV2605RegAccessor() { }
  ~DRV2605RegAccessor() { }

};

} // namespace artos

#endif /* DRIVERS_DRV2605_DRV2605REGACCESS_H_ */
