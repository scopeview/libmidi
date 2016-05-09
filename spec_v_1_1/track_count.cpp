#include <cassert>
#include "libmidi/spec_v_1_1/track_count.hpp"

namespace libmidi { namespace spec_v_1_1 {

uint16_t track_count::s_max_count = 16;	// 16 channels? not tracks

track_count::track_count() : m_track_count(0) {}
track_count::track_count(uint16_t n) : m_track_count(n) {
    assert(n < s_max_count);
}

////////////////////////////////////////////////////////////////
uint16_t track_count::value() const
{
    return m_track_count;
}

void track_count::set_value(uint16_t data)
{
    assert(data < s_max_count);
    m_track_count = data;
}

}}
