#include <cassert>
#include "libmidi/spec_v_1_1/tempo.hpp"

namespace libmidi { namespace spec_v_1_1 {

int tempo::s_tempo_max = 0x7F7F7F;

tempo::tempo() {
    m_tempo[0] = 0;
    m_tempo[1] = 0;
    m_tempo[2] = 0;
}

tempo::tempo(int n) { 
    assert(n <= s_tempo_max);
    m_tempo[0] = n >> 16;
    m_tempo[1] = n >> 8;
    m_tempo[2] = n;
}

////////////////////////////////////////////////////////////////
std::array<uint8_t, 3> tempo::value() const
{
    return std::array<uint8_t, 3>({m_tempo[0], m_tempo[1], m_tempo[2]});
}

void tempo::set_value(std::array<uint8_t, 3>& a)
{
    m_tempo[0] = a[0];
    m_tempo[1] = a[1];
    m_tempo[2] = a[2];
}

}}
