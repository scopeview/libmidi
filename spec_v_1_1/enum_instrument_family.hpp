#ifndef __LIBMIDI_SPEC_V_1_1_ENUM_INSTRUMENT_FAMILY_HPP__
#define __LIBMIDI_SPEC_V_1_1_ENUM_INSTRUMENT_FAMILY_HPP__

#include <utility>
#include <iostream>

namespace libmidi { namespace spec_v_1_1 {

enum class enum_instrument_family {
    Piano = 0,
	Chromatic_Percussion = 1,
	Organ = 2,
	Guitar = 3,
	Bass = 4,
	Strings = 5,
	Ensemble = 6,
	Brass = 7,
	Reed = 8,
	Pipe = 9,
	Synth_Lead = 10,
	Synth_Pad = 11,
	Synth_Effects = 12,
	Ethnic = 13,
	Percussive = 14,
	Sound_Effects = 15
	};

std::ostream& operator<<(std::ostream&, enum_instrument_family);

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_ENUM_INSTRUMENT_FAMILY_HPP__ */
