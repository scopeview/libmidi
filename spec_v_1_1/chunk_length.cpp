#include <cassert>
#include "libmidi/spec_v_1_1/chunk_length.hpp"

namespace libmidi { namespace spec_v_1_1 {

uint32_t chunk_length::s_length_max = 0x0FFFFFFF;

chunk_length::chunk_length() : m_chunk_length(0) {}
chunk_length::chunk_length(uint32_t n) : m_chunk_length(n) {
    assert(n <= s_length_max);
}

uint32_t chunk_length::value() const
{
    return m_chunk_length;
}

}}
