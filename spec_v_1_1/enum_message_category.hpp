#ifndef __LIBMIDI_SPEC_V_1_1_ENUM_MESSAGE_CATEGORY_HPP__
#define __LIBMIDI_SPEC_V_1_1_ENUM_MESSAGE_CATEGORY_HPP__

namespace libmidi { namespace spec_v_1_1 {

enum class enum_message_category {
    meta_message_type,
	channel_voice_message_type,
	system_common_message_type,
	system_real_time_message_type,
	not_spec_v_1_1_type
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_ENUM_MESSAGE_CATEGORY_HPP__ */
