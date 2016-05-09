#include <cassert>
#include "libmidi/spec_v_1_1/value.hpp"

namespace libmidi { namespace spec_v_1_1 {

uint8_t value::s_value_max = 0x7F;

value::value() : m_value(0) {}
value::value(uint8_t n) : m_value(n) {
    assert(n <= s_value_max);
}

////////////////////////////////////////////////////////////////
uint8_t value::get_value() const
{
    return m_value;
}

void value::set_value(uint8_t data)
{
    assert(data <= s_value_max);
    m_value = data;
}

}}

