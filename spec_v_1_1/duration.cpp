#include "libmidi/spec_v_1_1/duration.hpp"

namespace libmidi { namespace spec_v_1_1 {

duration::duration(int n) : m_duration(n)
{}

int duration::value() const
{
    return m_duration;
}

}}
