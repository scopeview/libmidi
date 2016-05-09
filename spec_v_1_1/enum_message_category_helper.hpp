#ifndef __LIBMIDI_SPEC_V_1_1_ENUM_MESSAGE_CATEGORY_HELPER_HPP__
#define __LIBMIDI_SPEC_V_1_1_ENUM_MESSAGE_CATEGORY_HELPER_HPP__

#include "libmidi/spec_v_1_1/enum_message_type.hpp"
#include "libmidi/spec_v_1_1/enum_message_category.hpp"

namespace libmidi { namespace spec_v_1_1 {

enum_message_category to_enum_message_category(enum_message_type type);

template<enum_message_category C>
bool is_enum_message_category(enum_message_type type) {
    return C == to_enum_message_category(type);
}

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_ENUM_MESSAGE_CATEGORY_HELPER_HPP__ */
