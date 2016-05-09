#ifndef __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_UPDATER_HPP__
#define __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_UPDATER_HPP__

#include "libtraits/setter.hpp"
#include "libtraits/packer_sizer.hpp"
#include "libtraits/traits/updater.hpp"
#include "libtraits/traits/packer_sizer.hpp"
#include "libmidi/spec_v_1_1/internal_midi_types.hpp"
#include "libmidi/spec_v_1_1/file.hpp"

namespace libtraits { namespace traits {

using namespace libmidi::spec_v_1_1;

template<>
struct updater<track> {
    static void update(track& track_) {
	// update chunk_length
	int sz = packer_size(static_cast<event_base::pointer_list&>(track_));
	libtraits::set(track_, chunk_length(sz));
    }
};

template<>
struct updater<head> {
    static void update(head& head_) {
	int sz = packer_size(static_cast<const midi_format&>(head_),
			     static_cast<const track_count&>(head_),
			     static_cast<const division&>(head_));
	libtraits::set(head_, chunk_length(sz));
    }
};

template<>
struct updater<file> {
    static void update(file& file_) {
	head& head_ = file_;
	track_list& track_list_ = file_;

	// set head
	// - track_count
	// - midi_format validation
	libtraits::set(head_, track_count(track_list_.size()));
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_UPDATER_HPP__ */
