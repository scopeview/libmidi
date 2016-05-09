#ifndef __LIBMIDI_SPEC_V_1_1_CONTROLLER_NUMBER_HPP__
#define __LIBMIDI_SPEC_V_1_1_CONTROLLER_NUMBER_HPP__

#include "libmidi/spec_v_1_1/value.hpp"

namespace libmidi { namespace spec_v_1_1 {

class controller_number : public value {
public:
    controller_number();
    controller_number(uint8_t);

    friend std::ostream& operator<<(std::ostream& os, const controller_number& o) {
	return os << (value&)o;
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_CONTROLLER_NUMBER_HPP__ */
