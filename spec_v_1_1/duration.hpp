#ifndef __LIBMIDI_SPEC_V_1_1_DURATION_HPP__
#define __LIBMIDI_SPEC_V_1_1_DURATION_HPP__

namespace libmidi { namespace spec_v_1_1 {

class duration {
    int m_duration;

public:
    duration(int);
    int value() const;
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_DURATION_HPP__ */
