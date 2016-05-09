#ifndef __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_MAPPER_HPP__
#define __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_MAPPER_HPP__

#include "libtraits/traits/mapper.hpp"
#include "libmidi/spec_v_1_1/enum_message_type.hpp"
#include "libmidi/spec_v_1_1/enum_message_category.hpp"

namespace libtraits { namespace traits {

#define DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(from)		\
    DEFINE_VALUE_MAPPER(libmidi::spec_v_1_1::enum_message_type, from,	\
			libmidi::spec_v_1_1::enum_message_category,	\
			libmidi::spec_v_1_1::enum_message_category::meta_message_type) \
/***/

#define DEFINE_VALUE_MAPPER_TO_CATEGORY_CHANNEL_VOICE_MESSAGE_TYPE(from) \
    DEFINE_VALUE_MAPPER(libmidi::spec_v_1_1::enum_message_type, from,	\
			libmidi::spec_v_1_1::enum_message_category,	\
			libmidi::spec_v_1_1::enum_message_category::channel_voice_message_type) \
/***/

#define DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_COMMON_MESSAGE_TYPE(from) \
    DEFINE_VALUE_MAPPER(libmidi::spec_v_1_1::enum_message_type, from,	\
			libmidi::spec_v_1_1::enum_message_category,	\
			libmidi::spec_v_1_1::enum_message_category::system_common_message_type) \
/***/

#define DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_REAL_TIME_MESSAGE_TYPE(from) \
    DEFINE_VALUE_MAPPER(libmidi::spec_v_1_1::enum_message_type, from,	\
			libmidi::spec_v_1_1::enum_message_category,	\
			libmidi::spec_v_1_1::enum_message_category::system_real_time_message_type) \
/***/

////////////////////////////////////////////////////////////////
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_sequence_number);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_text);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_text_copyright_notice);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_text_sequence_track_name);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_text_instrument_name);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_text_lyric);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_text_marker);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_text_cue_point);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_midi_channel_prefix);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_end_of_track);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_tempo);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_smpte_offset);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_time_signature);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_key_signature);
DEFINE_VALUE_MAPPER_TO_CATEGORY_META_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::meta_sequencer_specific_meta_event);


DEFINE_VALUE_MAPPER_TO_CATEGORY_CHANNEL_VOICE_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::note_off);
DEFINE_VALUE_MAPPER_TO_CATEGORY_CHANNEL_VOICE_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::note_on);
DEFINE_VALUE_MAPPER_TO_CATEGORY_CHANNEL_VOICE_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::polyphonic_key_pressure);
DEFINE_VALUE_MAPPER_TO_CATEGORY_CHANNEL_VOICE_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::control_change);
DEFINE_VALUE_MAPPER_TO_CATEGORY_CHANNEL_VOICE_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::program_change);
DEFINE_VALUE_MAPPER_TO_CATEGORY_CHANNEL_VOICE_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::channel_pressure);
DEFINE_VALUE_MAPPER_TO_CATEGORY_CHANNEL_VOICE_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::pitch_wheel_change);


DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_COMMON_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::system_exclusive);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_COMMON_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::undefined_B11110001);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_COMMON_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::song_position_pointer);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_COMMON_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::song_select);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_COMMON_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::undefined_B11110100);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_COMMON_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::undefined_B11110101);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_COMMON_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::tune_request);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_COMMON_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::end_of_exclusive);


DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_REAL_TIME_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::timing_clock);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_REAL_TIME_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::undefined_B11111001);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_REAL_TIME_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::start);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_REAL_TIME_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::continue_);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_REAL_TIME_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::stop);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_REAL_TIME_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::undefined_B11111101);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_REAL_TIME_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::active_sensing);
DEFINE_VALUE_MAPPER_TO_CATEGORY_SYSTEM_REAL_TIME_MESSAGE_TYPE(libmidi::spec_v_1_1::enum_message_type::reset);

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_MAPPER_HPP__ */
