#include <cassert>
#include "libmidi/spec_v_1_1/channel.hpp"

namespace libmidi { namespace spec_v_1_1 {

uint16_t channel::s_channel_max = 16;

channel::channel() : m_channel(0) {}
channel::channel(uint16_t n) : m_channel(n) {
    assert(m_channel <= channel::s_channel_max);
}

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
uint16_t channel::value() const
{
    return m_channel;
}

void channel::set_value(uint16_t data)
{
    assert(data <= channel::s_channel_max);
    m_channel = data;
}

}}
