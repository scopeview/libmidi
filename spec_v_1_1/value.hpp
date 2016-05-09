#ifndef __LIBMIDI_SPEC_V_1_1_VALUE_HPP__
#define __LIBMIDI_SPEC_V_1_1_VALUE_HPP__

#include <iostream>

namespace libmidi { namespace spec_v_1_1 {

class value {
    static uint8_t s_value_max;
    uint8_t m_value;

public:
    value();
    value(uint8_t);

    uint8_t get_value() const;
    void set_value(uint8_t);

    friend std::ostream& operator<<(std::ostream& os, const value& o) {
	return os << o.m_value;
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_VALUE_HPP__ */
