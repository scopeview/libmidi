#ifndef __LIBMIDI_SPEC_V_1_1_CHUNK_TYPE_HPP__
#define __LIBMIDI_SPEC_V_1_1_CHUNK_TYPE_HPP__

#include <array>

namespace libmidi { namespace spec_v_1_1 {

class chunk_type {
    char m_type_array[4];

public:
    enum type {
	HEAD,
	TRACK,
    };

    chunk_type();
    chunk_type(type);

    std::array<char, 4> value() const;
    void set_value(const std::array<char, 4>&);
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_CHUNK_TYPE_HPP__ */
