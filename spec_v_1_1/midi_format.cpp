#include "libmidi/spec_v_1_1/midi_format.hpp"

namespace libmidi { namespace spec_v_1_1 {

midi_format::midi_format() : m_midi_format(enum_midi_format::single_multi_channel) {}
midi_format::midi_format(enum_midi_format f) : m_midi_format(f) {}

////////////////////////////////////////////////////////////////
enum_midi_format midi_format::value() const
{
    return m_midi_format;
}

}}

