#ifndef __LIBMIDI_SPEC_V_1_1_TRAITS_GENERATOR_HPP__
#define __LIBMIDI_SPEC_V_1_1_TRAITS_GENERATOR_HPP__

#include <algorithm>
#include "libtraits/_.hpp"
#include "libmidi/spec_v_1_1/libtraits_extension/_.hpp"

namespace libtraits { namespace traits {

template<>
struct generator<libmidi::spec_v_1_1::file> {
    using file = libmidi::spec_v_1_1::file;
    using head = libmidi::spec_v_1_1::head;
    using track = libmidi::spec_v_1_1::track;
    using track_list = libmidi::spec_v_1_1::track_list;

    template<typename IT>
    static void generate(IT& it, file& f) {
	libtraits::update(f);

	// generate
	head& head_ = f;
	track_list& track_list_ = f;
	generator<head>::generate(it, head_);
	std::for_each(track_list_.begin(), track_list_.end(), [&](track& t) {
		generator<track>::generate(it, t);
	    });
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_TRAITS_GENERATOR_HPP__ */
