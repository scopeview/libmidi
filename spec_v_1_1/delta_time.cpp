#include "libmidi/spec_v_1_1/delta_time.hpp"

namespace libmidi { namespace spec_v_1_1 {

delta_time::delta_time() : m_delta_time(0) {}
delta_time::delta_time(size_t n) : m_delta_time(n) {}

////////////////////////////////////////////////////////////////
size_t delta_time::value() const
{
    return m_delta_time;
}

void delta_time::set_value(size_t sz)
{
    m_delta_time = sz;
}

}}

