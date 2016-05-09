#ifndef __LIBMIDI_SPEC_V_1_1_TRAITS_PARAMETER_TUPLE_HPP__
#define __LIBMIDI_SPEC_V_1_1_TRAITS_PARAMETER_TUPLE_HPP__

#include <tuple>
#include "libmidi/spec_v_1_1/message_type.hpp"

namespace libmidi { namespace spec_v_1_1 { namespace traits {

template<enum_message_type>
struct parameter_tuple;

}}}
#endif	/* __LIBMIDI_SPEC_V_1_1_TRAITS_PARAMETER_TUPLE_HPP__ */
