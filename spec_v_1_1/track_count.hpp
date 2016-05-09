#ifndef __LIBMIDI_SPEC_V_1_1_TRACK_COUNT_HPP__
#define __LIBMIDI_SPEC_V_1_1_TRACK_COUNT_HPP__

#include <cstdint>

namespace libmidi { namespace spec_v_1_1 {

class track_count {
    // TODO
    // 16 channels? not tracks
    static uint16_t s_max_count;

    uint16_t m_track_count;

public:
    // TODO
    // assert if head_format is 0, count must be 1
    // assert at least 1 track
    track_count();
    track_count(uint16_t);

    uint16_t value() const;
    void set_value(uint16_t);
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_TRACK_COUNT_HPP__ */
