#ifndef __LIBMIDI_SPEC_V_1_1_VELOCITY_HPP__
#define __LIBMIDI_SPEC_V_1_1_VELOCITY_HPP__

#include "libmidi/spec_v_1_1/value.hpp"

namespace libmidi { namespace spec_v_1_1 {

class velocity : public value {
public:
    velocity();
    velocity(uint8_t);

    friend std::ostream& operator<<(std::ostream& os, const velocity& o) {
	return os << (value&)o;
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_VELOCITY_HPP__ */
