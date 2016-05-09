#ifndef __LIBMIDI_SPEC_V_1_1_MESSAGE_TYPE_HPP__
#define __LIBMIDI_SPEC_V_1_1_MESSAGE_TYPE_HPP__

#include <cassert>
#include "libmidi/spec_v_1_1/enum_message_type.hpp"
#include "libmidi/spec_v_1_1/enum_message_category.hpp"
#include "libmidi/spec_v_1_1/enum_message_category_helper.hpp"
#include "libmidi/spec_v_1_1/channel.hpp"
#include "libtemplate/_.hpp"

namespace libmidi { namespace spec_v_1_1 {

class message_type : public channel {
    enum_message_type m_enum_message_type;

public:
    message_type() {}

    message_type(enum_message_type enum_message_type_, const channel& c)
	: channel(c), m_enum_message_type(enum_message_type_) {
	assert(is_enum_message_category<enum_message_category::channel_voice_message_type>(enum_message_type_));
    }

    message_type(enum_message_type enum_message_type_)
	: m_enum_message_type(enum_message_type_) {
	assert(!is_enum_message_category<enum_message_category::channel_voice_message_type>(enum_message_type_));
    }

    enum_message_type get_enum_message_type() const {
	return m_enum_message_type;
    }

    uint16_t get_composed_value() const {
	uint16_t composed_value = static_cast<std::underlying_type<enum_message_type>::type>(m_enum_message_type);
	if (is_enum_message_category<enum_message_category::channel_voice_message_type>(m_enum_message_type)) {
	    composed_value |= (char)static_cast<const channel&>(*this).value();
	}

	return composed_value;
    }

    void set_value(uint16_t v16) {
	if (libtemplate::integral_eq<uint16_t>(v16 & 0xFF00, 0xFF00)) {
	    m_enum_message_type = static_cast<enum_message_type>(v16);
	} else {
	    uint8_t v = v16;

	    // uncompose type and channel
	    enum_message_type enum_message_type_ = static_cast<enum_message_type>(v & 0xF0);
	    if (to_enum_message_category(enum_message_type_) == enum_message_category::channel_voice_message_type) {
		m_enum_message_type = enum_message_type_;
		static_cast<channel&>(*this) = channel(v & 0x0F);
	    }
	} 
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_MESSAGE_TYPE_HPP__ */
