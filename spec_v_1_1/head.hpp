#ifndef __LIBMIDI_SPEC_V_1_1_HEAD_HPP__
#define __LIBMIDI_SPEC_V_1_1_HEAD_HPP__

#include "libmidi/spec_v_1_1/chunk_type.hpp"
#include "libmidi/spec_v_1_1/chunk_length.hpp"
#include "libmidi/spec_v_1_1/midi_format.hpp"
#include "libmidi/spec_v_1_1/track_count.hpp"
#include "libmidi/spec_v_1_1/division.hpp"

namespace libmidi { namespace spec_v_1_1 {

// typedef libtraits::type_selector<chunk_type, chunk_length, head_format, head_track_count, head_division> head_type_selector
// class head : public head_type_selector
class head : public chunk_type,
	     public chunk_length,
	     public midi_format,
	     public track_count,
	     public division
	     // shouldn't change the sequence above
{
    // static_assert(all of them are POD)
public:
    head();

};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_HEAD_HPP__ */
