#ifndef __LIBMIDI_SPEC_V_1_1_TEMPO_HPP__
#define __LIBMIDI_SPEC_V_1_1_TEMPO_HPP__

#include <stdint.h>
#include <array>

namespace libmidi { namespace spec_v_1_1 {

class tempo {
    static int s_tempo_max;

    uint8_t m_tempo[3];

public:
    tempo();
    tempo(int);

    std::array<uint8_t, 3> value() const;
    void set_value(std::array<uint8_t, 3>&);
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_TEMPO_HPP__ */
