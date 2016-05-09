#ifndef __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_PARSER_HPP__
#define __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_PARSER_HPP__

#include "libmidi/spec_v_1_1/internal_midi_types.hpp"
#include "libmidi/spec_v_1_1/file.hpp"
#include "libtraits/traits/parser.hpp"

namespace libtraits { namespace traits {

#if 0
template<>
struct parser<libmidi::spec_v_1_1::head> {
    using head = libmidi::spec_v_1_1::head;
    using chunk_type = libmidi::spec_v_1_1::chunk_type;
    using chunk_length = libmidi::spec_v_1_1::chunk_length;
    using midi_format = libmidi::spec_v_1_1::midi_format;
    using track_count = libmidi::spec_v_1_1::track_count;
    using division = libmidi::spec_v_1_1::division;

    template<typename IT>
    static std::unique_ptr<head> parse(IT& it) {
	std::unique_ptr<head> head_ptr(new head);

	unpacker<chunk_type>::unpack(it, static_cast<chunk_type&>(*head_ptr));
	unpacker<chunk_length>::unpack(it, static_cast<chunk_length>(*head_ptr));
	unpacker<midi_format>::unpack(it, static_cast<midi_format>(*head_ptr));
	unpacker<track_count>::unpack(it, static_cast<track_count>(*head_ptr));
	unpacker<division>::unpack(it, static_cast<division>(*head_ptr));
    }
};
#endif

template<>
struct parser<libmidi::spec_v_1_1::file> {
    using file = libmidi::spec_v_1_1::file;
    using head = libmidi::spec_v_1_1::head;
    using track = libmidi::spec_v_1_1::track;
    using track_list = libmidi::spec_v_1_1::track_list;

    template<typename IT>
    static std::unique_ptr<file> parse(IT& it) {
	std::unique_ptr<file> file_ptr(new file);

	head& head_ = static_cast<head&>(*file_ptr);
	unpacker<head>::unpack(it, head_);
	int track_count_ = libtemplate::static_cast_reference<file, head, track_count>(*file_ptr).value();
	assert(track_count_ > 0);

	track track_;
	track_list& track_list_ = static_cast<track_list&>(*file_ptr);
	while (track_count_--) {
	    std::unique_ptr<track> track_ptr = parser<track>::parse(it);
	    track_list_.push_back(std::move(*track_ptr));
	    track_ptr.release();
	}
	return file_ptr;
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_PARSER_HPP__ */
