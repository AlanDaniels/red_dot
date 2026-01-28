#ifndef LINEAR_LERP_H
#define LINEAR_LERP_H

class LinearLerp {
public:
    LinearLerp(long begin_time_msecs, long duration_msecs, float begin_val, float end_val);
    float get(long current_time) const;

    // Disable the default ctor, copying and moving.
    LinearLerp() = delete;
    LinearLerp(const LinearLerp &that) = delete;
    LinearLerp(const LinearLerp &&that) = delete;
    LinearLerp& operator=(LinearLerp const &that) = delete;
    LinearLerp&& operator=(LinearLerp const &&that) = delete;

private:
    long m_begin_time_msecs;
    long m_duration_msecs;
    float m_begin_val;
    float m_end_val;
};

#endif
