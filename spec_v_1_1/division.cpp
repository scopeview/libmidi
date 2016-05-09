#include <cassert>
#include "libmidi/spec_v_1_1/division.hpp"

namespace libmidi { namespace spec_v_1_1 {

division::division() {}
division::division(type type_, short ticks_per_quarter_note)
{
    assert(type_ == division::metrical_time);
    m_division.metrical_time_t.m_division_type = 0;
    m_division.metrical_time_t.m_ticks_per_quarter_note = ticks_per_quarter_note;
}

division::division(type type_, uint8_t negative_smpte_format, uint8_t ticks_per_frame)
{
    assert(type_ == time_code_based_time);
    m_division.time_code_based_time_t.m_division_type = 1;
    m_division.time_code_based_time_t.m_negative_smpte_format = negative_smpte_format;
    m_division.time_code_based_time_t.m_ticks_per_frame = ticks_per_frame;
}

////////////////////////////////////////////////////////////////

uint16_t division::value() const
{
    return m_division.uint16_data;
}

void division::set_value(uint16_t data)
{
    m_division.uint16_data = data;
}

}}

