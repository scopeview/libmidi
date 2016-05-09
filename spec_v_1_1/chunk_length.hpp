#ifndef __LIBMIDI_SPEC_V_1_1_CHUNK_LENGTH_HPP__
#define __LIBMIDI_SPEC_V_1_1_CHUNK_LENGTH_HPP__

#include <cstdint>

namespace libmidi { namespace spec_v_1_1 {

class chunk_length {
    static uint32_t s_length_max;

    uint32_t m_chunk_length;

public:
    chunk_length();
    chunk_length(uint32_t);

    uint32_t value() const;
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_CHUNK_LENGTH_HPP__ */
