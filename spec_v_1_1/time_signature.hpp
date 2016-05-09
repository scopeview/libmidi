#ifndef __LIBMIDI_SPEC_V_1_1_TIME_SIGNATURE_HPP__
#define __LIBMIDI_SPEC_V_1_1_TIME_SIGNATURE_HPP__

namespace libmidi { namespace spec_v_1_1 {

struct time_signature {
    uint8_t numerator;
    uint8_t denominator;
    uint8_t clocks;
    uint8_t number_of_notated_32nd_notes_in_a_midi_quarter_note;
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_TIME_SIGNATURE_HPP__ */
