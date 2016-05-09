#include "libmidi/spec_v_1_1/smpte_offset.hpp"

namespace libmidi { namespace spec_v_1_1 {

smpte_offset::smpte_offset()
    : m_hour(0), m_minute(0), m_second(0), m_frame(0), m_ff(0)
{}

smpte_offset::smpte_offset(uint8_t hour, uint8_t minute, uint8_t second, uint8_t frame, uint8_t ff)
    : m_hour(hour), m_minute(minute), m_second(second), m_frame(frame), m_ff(ff)
{}

}}
