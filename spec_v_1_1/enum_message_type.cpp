#include "libmidi/spec_v_1_1/enum_message_type.hpp"

namespace libmidi { namespace spec_v_1_1 {

constexpr std::pair<enum_message_type, const char*> string_of_enum_message_type[] = {
    {enum_message_type::meta_sequence_number, "meta_sequence_number"},
    {enum_message_type::meta_text, "meta_text"},
    {enum_message_type::meta_text_copyright_notice, "meta_text_copyright_notice"},
    {enum_message_type::meta_text_sequence_track_name, "meta_text_sequence_track_name"},
    {enum_message_type::meta_text_instrument_name, "meta_text_instrument_name"},
    {enum_message_type::meta_text_lyric, "meta_text_lyric"},
    {enum_message_type::meta_text_marker, "meta_text_marker"},
    {enum_message_type::meta_text_cue_point, "meta_text_cue_point"},
    {enum_message_type::meta_midi_channel_prefix, "meta_midi_channel_prefix"},
    {enum_message_type::meta_end_of_track, "meta_end_of_track"},
    {enum_message_type::meta_tempo, "meta_tempo"},
    {enum_message_type::meta_smpte_offset, "meta_smpte_offset"},
    {enum_message_type::meta_time_signature, "meta_time_signature"},
    {enum_message_type::meta_key_signature, "meta_key_signature"},
    {enum_message_type::meta_sequencer_specific_meta_event, "meta_sequencer_specific_meta_event"},
    {enum_message_type::note_off, "note_off"},
    {enum_message_type::note_on, "note_on"},
    {enum_message_type::polyphonic_key_pressure, "polyphonic_key_pressure"},
    {enum_message_type::control_change, "control_change"},
    {enum_message_type::program_change, "program_change"},
    {enum_message_type::channel_pressure, "channel_pressure"},
    {enum_message_type::pitch_wheel_change, "pitch_wheel_change"},
    {enum_message_type::system_exclusive, "system_exclusive"},
    {enum_message_type::undefined_B11110001, "undefined_B11110001"},
    {enum_message_type::song_position_pointer, "song_position_pointer"},
    {enum_message_type::song_select, "song_select"},
    {enum_message_type::undefined_B11110100, "undefined_B11110100"},
    {enum_message_type::undefined_B11110101, "undefined_B11110101"},
    {enum_message_type::tune_request, "tune_request"},
    {enum_message_type::end_of_exclusive, "end_of_exclusive"},
    {enum_message_type::timing_clock, "timing_clock"},
    {enum_message_type::undefined_B11111001, "undefined_B11111001"},
    {enum_message_type::start, "start"},
    {enum_message_type::continue_, "continue"},
    {enum_message_type::stop, "stop"},
    {enum_message_type::undefined_B11111101, "undefined_B11111101"},
    {enum_message_type::active_sensing, "active_sensing"},
    {enum_message_type::reset, "reset"}
};

std::ostream& operator<<(std::ostream& os, enum_message_type o) {
    size_t i = 0;
    for (;i < sizeof(string_of_enum_message_type); ++i) {
	if (string_of_enum_message_type[i].first == o)
	    break;
    }
    return os << "enum_message_type::" << string_of_enum_message_type[i].second;
}

}}
