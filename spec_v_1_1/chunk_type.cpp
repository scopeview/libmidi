#include "libmidi/spec_v_1_1/chunk_type.hpp"

namespace libmidi { namespace spec_v_1_1 {

static void init_chunk_type_head(char* array) {
    array[0] = 'M';
    array[1] = 'T';
    array[2] = 'h';
    array[3] = 'd';
}

static void init_chunk_type_track(char* array) {
    array[0] = 'M';
    array[1] = 'T';
    array[2] = 'r';
    array[3] = 'k';
}

chunk_type::chunk_type() : m_type_array() {
    *((int*)m_type_array) = 0;
}

chunk_type::chunk_type(type t) {
    switch (t) {
    case HEAD:
	init_chunk_type_head(m_type_array);
	break;
    case TRACK:
	init_chunk_type_track(m_type_array);
	break;
    }
}

////////////////////////////////////////////////////////////////
std::array<char, 4> chunk_type::value() const
{
    return std::array<char, 4>({m_type_array[0], m_type_array[1], m_type_array[2], m_type_array[3]});

}

void chunk_type::set_value(const std::array<char, 4>& a)
{
    m_type_array[0] = a[0];
    m_type_array[1] = a[1];
    m_type_array[2] = a[2];
    m_type_array[3] = a[3];
}

}}
