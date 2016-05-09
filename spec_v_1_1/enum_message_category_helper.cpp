#include "libmidi/spec_v_1_1/enum_message_category_helper.hpp"
#include "libtraits/_.hpp"
#include "libmidi/spec_v_1_1/libtraits_extension/mapper.hpp"

namespace libmidi { namespace spec_v_1_1 {

#define DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(from)			\
    case from:								\
    result = libtraits::traits::constexpr_mapper<enum_message_type, from, enum_message_category>::map(); \
    break								\
/***/

enum_message_category to_enum_message_category(enum_message_type type)
{
    enum_message_category result;
    switch (type) {
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_sequence_number);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_text);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_text_copyright_notice);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_text_sequence_track_name);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_text_instrument_name);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_text_lyric);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_text_marker);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_text_cue_point);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_midi_channel_prefix);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_end_of_track);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_tempo);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_smpte_offset);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_time_signature);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_key_signature);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::meta_sequencer_specific_meta_event);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::note_off);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::note_on);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::polyphonic_key_pressure);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::control_change);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::program_change);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::channel_pressure);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::pitch_wheel_change);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::system_exclusive);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::undefined_B11110001);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::song_position_pointer);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::song_select);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::undefined_B11110100);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::undefined_B11110101);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::tune_request);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::end_of_exclusive);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::timing_clock);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::undefined_B11111001);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::start);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::continue_);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::stop);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::undefined_B11111101);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::active_sensing);
	DEFINE_TO_ENUM_MESSAGE_CATEGORY_CASE(enum_message_type::reset);
    default:
	result = enum_message_category::not_spec_v_1_1_type;
    }

    return result;
}

}}
