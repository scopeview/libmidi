#ifndef __LIBMIDI_SPEC_V_1_1_DELTA_TIME_HPP__
#define __LIBMIDI_SPEC_V_1_1_DELTA_TIME_HPP__

#include <cstddef>

namespace libmidi { namespace spec_v_1_1 {

class delta_time {
    size_t m_delta_time;

public:
    delta_time();
    delta_time(size_t);

    size_t value() const;
    void set_value(size_t);

    friend delta_time operator+(const delta_time& delta_time_, int count) {
	return delta_time(delta_time_.value() + count);
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_DELTA_TIME_HPP__ */
