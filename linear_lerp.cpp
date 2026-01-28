#include <stdio.h>
#include "linear_lerp.hpp"


// The only allowed constructor. Specifying all the parameters so the class is general purpose.
LinearLerp::LinearLerp(long begin_time_msecs, long duration_msecs, float begin_val, float end_val)
{
    m_begin_time_msecs = begin_time_msecs;
    m_duration_msecs = duration_msecs;

    m_begin_val = begin_val;
    m_end_val = end_val;

    m_is_paused = false;
    m_paused_time = begin_time_msecs;
    m_paused_value = get(begin_time_msecs);
}


// Get the current value, based on the timestamp.
float LinearLerp::get(long current_time) const
{
    long end_time = m_begin_time_msecs + m_duration_msecs;

    if (m_is_paused) {
        return m_paused_value;
    }
    else if (current_time <= m_begin_time_msecs) {
        return m_begin_val;
    }
    else if (current_time >= end_time) {
        return m_end_val;
    }
    else {
        long elapsed_msecs = current_time - m_begin_time_msecs;
        float diff = static_cast<float>(elapsed_msecs) / static_cast<float>(m_duration_msecs);
        float result = m_begin_val + (diff * (m_end_val - m_begin_val));
        printf("Result = %.2f\n", result);
        fflush(stdout);
        return result;
    }
}


// Pause the linear lerp.
void LinearLerp::pause(long current_time)
{
    m_paused_value = get(current_time);
    m_paused_time = current_time;
    m_is_paused = true;
}


// Resume the linear lerp.
void LinearLerp::resume(long current_time)
{
    long how_long_paused = current_time - m_paused_time;
    m_begin_time_msecs += how_long_paused;
    m_is_paused = false;
}