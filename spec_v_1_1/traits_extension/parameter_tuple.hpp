#ifndef __LIBMIDI_SPEC_V_1_1_TRAITS_EXTENSION_PARAMETER_TUPLE_HPP__
#define __LIBMIDI_SPEC_V_1_1_TRAITS_EXTENSION_PARAMETER_TUPLE_HPP__

#include "libmidi/spec_v_1_1/internal_midi_types.hpp"
#include "libmidi/spec_v_1_1/traits/parameter_tuple.hpp"

namespace libmidi { namespace spec_v_1_1 { namespace traits {

template<>
struct parameter_tuple<enum_message_type::meta_sequence_number> {
    typedef std::tuple<delta_time, std::array<uint8_t, 2>> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_text> {
    typedef std::tuple<delta_time, std::string> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_text_copyright_notice> {
    typedef std::tuple<delta_time, std::string> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_text_sequence_track_name> {
    typedef std::tuple<delta_time, std::string> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_text_instrument_name> {
    typedef std::tuple<delta_time, std::string> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_text_lyric> {
    typedef std::tuple<delta_time, std::string> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_text_marker> {
    typedef std::tuple<delta_time, std::string> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_text_cue_point> {
    typedef std::tuple<delta_time, std::string> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_midi_channel_prefix> {
    typedef std::tuple<delta_time, uint8_t> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_end_of_track> {
    typedef std::tuple<delta_time> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_tempo> {
    typedef std::tuple<delta_time, tempo> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_smpte_offset> {
    typedef std::tuple<delta_time, smpte_offset> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_time_signature> {
    typedef std::tuple<delta_time, time_signature> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_key_signature> {
    typedef std::tuple<delta_time, key_signature> type;
};
template<>
struct parameter_tuple<enum_message_type::meta_sequencer_specific_meta_event> {
    typedef std::tuple<delta_time, variable_message_data> type;
};
template<>
struct parameter_tuple<enum_message_type::note_off> {
    typedef std::tuple<delta_time, channel, key, velocity> type;
};
template<>
struct parameter_tuple<enum_message_type::note_on> {
    typedef std::tuple<delta_time, channel, key, velocity> type;
};
template<>
struct parameter_tuple<enum_message_type::polyphonic_key_pressure> {
    typedef std::tuple<delta_time, channel, key, velocity> type;
};
template<>
struct parameter_tuple<enum_message_type::control_change> {
    typedef std::tuple<delta_time, channel, controller_number, value> type;
};
template<>
struct parameter_tuple<enum_message_type::program_change> {
    typedef std::tuple<delta_time, channel, value> type;
};
template<>
struct parameter_tuple<enum_message_type::channel_pressure> {
    typedef std::tuple<delta_time, channel, value> type;
};
template<>
struct parameter_tuple<enum_message_type::pitch_wheel_change> {
    typedef std::tuple<delta_time, channel, value, value> type;
};

// TODO
// - have problem in parameter_tuple_packer_sizer
//   it calculates rest_size() without arguments
template<>
struct parameter_tuple<enum_message_type::system_exclusive> {
    typedef std::tuple<delta_time, variable_message_data> type;
};

template<>
struct parameter_tuple<enum_message_type::song_position_pointer> {
    typedef std::tuple<delta_time, value, value> type;
};
template<>
struct parameter_tuple<enum_message_type::song_select> {
    typedef std::tuple<delta_time, value> type;
};
template<>
struct parameter_tuple<enum_message_type::tune_request> {
    typedef std::tuple<delta_time> type;
};
template<>
struct parameter_tuple<enum_message_type::end_of_exclusive> {
    typedef std::tuple<delta_time> type;
};
template<>
struct parameter_tuple<enum_message_type::timing_clock> {
    typedef std::tuple<delta_time> type;
};
template<>
struct parameter_tuple<enum_message_type::start> {
    typedef std::tuple<delta_time> type;
};
template<>
struct parameter_tuple<enum_message_type::continue_> {
    typedef std::tuple<delta_time> type;
};
template<>
struct parameter_tuple<enum_message_type::stop> {
    typedef std::tuple<delta_time> type;
};
template<>
struct parameter_tuple<enum_message_type::active_sensing> {
    typedef std::tuple<delta_time> type;
};
template<>
struct parameter_tuple<enum_message_type::reset> {
    typedef std::tuple<delta_time> type;
};

}}}
#endif	/* __LIBMIDI_SPEC_V_1_1_TRAITS_EXTENSION_PARAMETER_TUPLE_HPP__ */
