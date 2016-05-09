#ifndef __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_VALIDATOR_HPP__
#define __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_VALIDATOR_HPP__

#include "libmidi/spec_v_1_1/file.hpp"
#include "libtraits/traits/validator.hpp"

namespace libtraits { namespace traits {

template<>
struct validator<libmidi::spec_v_1_1::file> {
    using file = libmidi::spec_v_1_1::file;

    static void validate(file& f) {
	// when midi_format is 0, track_count should be 1
	// needn't, midi_format is determined in file.generate()
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_VALIDATOR_HPP__ */
