#include "userosc.h"

typedef struct State {
  float phase; // [0, 1.0].
  float w0;
  float fm;
  float vol;
} State;

static State state;

void OSC_INIT(uint32_t platform, uint32_t api)
{
  state.phase = 0.f;
  state.w0 = 0.f;
  state.fm = 1.f;
  state.vol = 1.f;
}

void OSC_CYCLE(const user_osc_param_t * const params,
               int32_t *yn,
               const uint32_t frames)
{
  q31_t * __restrict y = (q31_t *)yn;
  const q31_t * y_e = y + frames;
  float phase = state.phase;
  float w0 = state.w0;
  float fm = state.fm;
  float vol = state.vol;

  for (; y != y_e; ) {
    const float sig = osc_sinf(phase);
    *(y++) = f32_to_q31(sig * vol * vol);

    fm *= 0.9993f;
    vol *= 0.9999f;
    w0 = clipmaxf(w0 * (1.f + fm / 5000.f), osc_w0f_for_note(151, 0));
    // inclement wave phase
    phase += w0;
    // if phase > 1, minus 1
    phase -= (uint32_t)phase;
  }

  state.phase = phase;
  state.w0 = w0;
  state.fm = fm;
  state.vol = vol;
}

void OSC_NOTEON(const user_osc_param_t * const params)
{
  // According to inc/userosc.h, params->pitch is "high byte: note number, low byte: fine (0-255)"
  state.w0 = osc_w0f_for_note(((params->pitch)>>8) - 12, 0);
  state.fm = 1.f;
  state.vol = 1.f;
}

void OSC_NOTEOFF(const user_osc_param_t * const params)
{
  // note off
}

void OSC_PARAM(uint16_t index, uint16_t value)
{

}

