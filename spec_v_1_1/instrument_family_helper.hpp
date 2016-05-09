#ifndef __LIBMIDI_SPEC_V_1_1_INSTRUMENT_FAMILY_HELPER_HPP__
#define __LIBMIDI_SPEC_V_1_1_INSTRUMENT_FAMILY_HELPER_HPP__

#include "libmidi/spec_v_1_1/enum_instrument.hpp"
#include "libmidi/spec_v_1_1/enum_instrument_family.hpp"

namespace libmidi { namespace spec_v_1_1 {

bool is_instrument_family(enum_instrument);
enum_instrument_family to_instrument_family(enum_instrument);

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_INSTRUMENT_FAMILY_HELPER_HPP__ */
