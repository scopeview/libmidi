#ifndef __LIBMIDI_SPEC_V_1_1_CHANNEL_HPP__
#define __LIBMIDI_SPEC_V_1_1_CHANNEL_HPP__

#include <iostream>

namespace libmidi { namespace spec_v_1_1 {

class channel {
    static uint16_t s_channel_max;
    uint16_t m_channel;

public:
    channel();
    channel(uint16_t);

    uint16_t value() const;
    void set_value(uint16_t);

    friend std::ostream& operator<<(std::ostream& os, const channel& o) {
	return os << o.m_channel;
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_CHANNEL_HPP__ */
