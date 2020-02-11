#include "userosc.h"

void OSC_INIT(uint32_t platform, uint32_t api)
{
}

void OSC_CYCLE(const user_osc_param_t * const params,
               int32_t *yn,
               const uint32_t frames)
{
  q31_t * __restrict y = (q31_t *)yn;
  const q31_t * y_e = y + frames;  
  for (; y != y_e; ) {
    *(y++) = f32_to_q31(osc_white());
  }
}

void OSC_NOTEON(const user_osc_param_t * const params)
{
  // note on
}

void OSC_NOTEOFF(const user_osc_param_t * const params)
{
  // note off
}

void OSC_PARAM(uint16_t index, uint16_t value)
{

}

