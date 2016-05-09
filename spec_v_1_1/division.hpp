#ifndef __LIBMIDI_SPEC_V_1_1_DIVISION_HPP__
#define __LIBMIDI_SPEC_V_1_1_DIVISION_HPP__

#include <cinttypes>
#include <iostream>

namespace libmidi { namespace spec_v_1_1 {

// division define the ticks per quoter note
// 
class division {
public:
    enum type {
	metrical_time = 0,
	time_code_based_time = 1,
    };
    
    union division_u {
	struct {
	    uint16_t m_division_type:1;
	    uint16_t m_ticks_per_quarter_note:15;
	} metrical_time_t;
	struct {
	    uint16_t m_division_type:1;
	    uint16_t m_negative_smpte_format:7;
	    uint16_t m_ticks_per_frame:8;
	} time_code_based_time_t;
	uint16_t uint16_data;
    };
private:
    division_u m_division;

public:
    division();
    division(type, short ticks_per_quarter_note);
    division(type, uint8_t negative_smpte_format, uint8_t ticks_per_frame);

    uint16_t value() const;
    void set_value(uint16_t);

    friend std::ostream& operator<<(std::ostream& os, const division& o) {
	// TODO
	return os << "division";
    }

};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_DIVISION_HPP__ */
