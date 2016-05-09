#ifndef __LIBMIDI_SPEC_V_1_1_MIDI_FORMAT_HPP__
#define __LIBMIDI_SPEC_V_1_1_MIDI_FORMAT_HPP__

#include <cinttypes>
#include <utility>

namespace libmidi { namespace spec_v_1_1 {

enum class enum_midi_format : unsigned short {
    single_multi_channel = 0,
	multiple_simultanious_track = 1,
	multiple_sequenctially_independent_single_track_patterns = 2
};

class midi_format {
    enum_midi_format m_midi_format;

public:
    midi_format();
    midi_format(enum_midi_format);

    enum_midi_format value() const;
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_MIDI_FORMAT_HPP__ */
