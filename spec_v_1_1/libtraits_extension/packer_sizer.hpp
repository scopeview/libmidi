#ifndef __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_PACKER_SIZER_HPP__
#define __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_PACKER_SIZER_HPP__

#include <algorithm>
#include "libmidi/spec_v_1_1/internal_midi_types.hpp"
#include "libmidi/spec_v_1_1/file.hpp"
#include "libtraits/traits/packer_sizer.hpp"
#include "libtraits/getter.hpp"
#include "libmidi/spec_v_1_1/libtraits_extension/_.hpp"

namespace libtraits { namespace traits {

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
#define DEFINE_PACKER_SIZER(TYPE, SIZE) \
template<> \
struct packer_sizer<TYPE> { \
    static size_t size(const TYPE& t) { \
	return SIZE; \
    } \
} \
/***/

DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::value, 1);
DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::channel, 1);
DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::key, 1);
DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::velocity, 1);
DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::tempo, 3);
DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::chunk_type, 4);
DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::midi_format, 2);
DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::track_count, 2);
DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::division, 2);

// DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::controller_number, );
// DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::event, );
// DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::instrument, );
// DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::key_signature, );
// DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::percussion, );
// DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::smpte_offset, );
// DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::tick, );
// DEFINE_PACKER_SIZER(libmidi::spec_v_1_1::time_signature, );


////////////////////////////////////////////////////////////////
// others
////////////////////////////////////////////////////////////////
template<>
struct packer_sizer<libmidi::spec_v_1_1::variable_length_quantity> {
    using variable_length_quantity = libmidi::spec_v_1_1::variable_length_quantity;

    static size_t size(const variable_length_quantity& length) {
	int size = 0;
	std::array<uint8_t, 4> t(length.get_as_variable());
	for (int i = 0; i < 4; ++i) {
	    if (t[i]) {
		++size;
	    }
	}
	if (!size) {
	    size = 1;
	}
	return size;
    }
};

template<>
struct packer_sizer<libmidi::spec_v_1_1::delta_time> {
    using delta_time = libmidi::spec_v_1_1::delta_time;
    using variable_length_quantity = libmidi::spec_v_1_1::variable_length_quantity;

    static size_t size(const delta_time& t) {
	return packer_sizer<variable_length_quantity>::size(
	    variable_length_quantity(t.value()));
    }
};

template<>
struct packer_sizer<std::string> {
    static size_t size(const std::string& s) {
	return s.size();
    }
};

template<>
struct packer_sizer<libmidi::spec_v_1_1::chunk_length> {
    using chunk_length = libmidi::spec_v_1_1::chunk_length;

    static size_t size(const chunk_length& chunk_length_) {
	return 4;
	// return packer_sizer<variable_length_quantity>::size(variable_length_quantity(chunk_length_.value()));
    }
};

template<>
struct packer_sizer<libmidi::spec_v_1_1::message_type> {
    using message_type = libmidi::spec_v_1_1::message_type;

    static size_t size(const message_type& message_type_) {
	int sz = 1;
	uint16_t data = message_type_.get_composed_value();
	if (libtemplate::integral_eq<uint16_t>(data & 0xFF00, 0xFF00)) {
	    sz = 2;
	}
	return sz;
    }
};

template<>
struct packer_sizer<libmidi::spec_v_1_1::head> {
    using chunk_type = libmidi::spec_v_1_1::chunk_type;
    using chunk_length = libmidi::spec_v_1_1::chunk_length;
    using midi_format = libmidi::spec_v_1_1::midi_format;
    using track_count = libmidi::spec_v_1_1::track_count;
    using division = libmidi::spec_v_1_1::division;

    static size_t size(const libmidi::spec_v_1_1::head& head_) {
	int sz = 0;
	sz += packer_sizer<chunk_type>::size(static_cast<const chunk_type&>(head_));
	sz += packer_sizer<chunk_length>::size(static_cast<const chunk_length&>(head_));
	sz += packer_sizer<midi_format>::size(static_cast<const midi_format&>(head_));
	sz += packer_sizer<track_count>::size(static_cast<const track_count&>(head_));
	sz += packer_sizer<division>::size(static_cast<const division&>(head_));
	return sz;
    }
};

////////////////////////////////////////////////////////////////
namespace helper {

template<libmidi::spec_v_1_1::enum_message_type enum_message_type_,
	 libmidi::spec_v_1_1::enum_message_category C = libtraits::traits::constexpr_mapper<enum_message_type,
											    enum_message_type_,
											    enum_message_category>::map()>
struct event_packer_sizer {
    using enum_message_type = libmidi::spec_v_1_1::enum_message_type;
    typedef event<enum_message_type_> event_type;
    typedef typename event_type::tuple_type tuple_type;

    static size_t size(const event<enum_message_type_>& event_) {
	const event_base& event_base_ = event_;
	size_t sz = 0;
	sz += packer_sizer<delta_time>::size(static_cast<const delta_time&>(event_base_));
	sz += packer_sizer<message_type>::size(message_type(event_base_.get_enum<enum_message_type>()));
	sz += packer_sizer<tuple_type>::size(static_cast<const tuple_type&>(event_));
	return sz;
    }
};

template<libmidi::spec_v_1_1::enum_message_type enum_message_type_>
struct event_packer_sizer<enum_message_type_, libmidi::spec_v_1_1::enum_message_category::meta_message_type> {
    using enum_message_type = libmidi::spec_v_1_1::enum_message_type;
    typedef event<enum_message_type_> event_type;
    typedef typename event_type::tuple_type tuple_type;

    static size_t size(const event<enum_message_type_>& event_) {
	const event_base& event_base_ = event_;
	size_t sz = 0;
	sz += packer_sizer<delta_time>::size(static_cast<const delta_time&>(event_base_));
	sz += packer_sizer<message_type>::size(message_type(event_base_.get_enum<enum_message_type>()));
	
	int tuple_sz = 0;
	tuple_sz += packer_sizer<tuple_type>::size(static_cast<const tuple_type&>(event_));
	tuple_sz += packer_sizer<variable_length_quantity>::size(variable_length_quantity(tuple_sz));

	return sz + tuple_sz;
    }
};

template<libmidi::spec_v_1_1::enum_message_type enum_message_type_>
struct event_packer_sizer<enum_message_type_, libmidi::spec_v_1_1::enum_message_category::channel_voice_message_type> {
    using enum_message_type = libmidi::spec_v_1_1::enum_message_type;
    typedef event<enum_message_type_> event_type;
    typedef typename event_type::tuple_type tuple_type;

    static size_t size(const event<enum_message_type_>& event_) {
	const event_base& event_base_ = event_;
	const tuple_type& tuple_ = static_cast<const tuple_type&>(event_);

	size_t sz = 0;
	sz += packer_sizer<delta_time>::size(static_cast<const delta_time&>(event_base_));
	sz += packer_sizer<message_type>::size(message_type(event_base_.get_enum<enum_message_type>(), std::get<0>(tuple_)));

	int tuple_sz = 0;
	tuple_sz += packer_sizer<tuple_type>::size(tuple_);
	tuple_sz -= packer_sizer<channel>::size(std::get<0>(tuple_));
	return sz + tuple_sz;
    }
};

}

template<libmidi::spec_v_1_1::enum_message_type enum_message_type_>
struct packer_sizer<libmidi::spec_v_1_1::event<enum_message_type_>> {
    using enum_message_type = libmidi::spec_v_1_1::enum_message_type;

    static size_t size(const event<enum_message_type_>& event_) {
	return helper::event_packer_sizer<enum_message_type_>::size(event_);
    }
};

#define PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type)	\
    case enum_message_type:						\
    sz = packer_sizer<event<enum_message_type>>::size(static_cast<const event<enum_message_type>&>(event_base_)); \
    break;								\
/***/

template<>
struct packer_sizer<libmidi::spec_v_1_1::event_base> {
    using enum_message_type = libmidi::spec_v_1_1::enum_message_type;
    using event_base = libmidi::spec_v_1_1::event_base;

    static size_t size(const event_base& event_base_) {
	int sz = 0;
	enum_message_type enum_message_type_ = event_base_.get_enum<enum_message_type>();
	switch (enum_message_type_) {
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_sequence_number);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_text);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_text_copyright_notice);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_text_sequence_track_name);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_text_instrument_name);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_text_lyric);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_text_marker);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_text_cue_point);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_midi_channel_prefix);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_end_of_track);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_tempo);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_smpte_offset);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_time_signature);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_key_signature);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::meta_sequencer_specific_meta_event);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::note_off);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::note_on);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::polyphonic_key_pressure);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::control_change);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::program_change);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::channel_pressure);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::pitch_wheel_change);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::system_exclusive);
	    // PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::undefined_B11110001);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::song_position_pointer);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::song_select);
	    // PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::undefined_B11110100);
	    // PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::undefined_B11110101);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::tune_request);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::end_of_exclusive);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::timing_clock);
	    // PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::undefined_B11111001);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::start);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::continue_);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::stop);
	    // PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::undefined_B11111101);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::active_sensing);
	    PACKER_SIZER__EVENT_SWITCH_CASE(enum_message_type::reset);
	default:
	    assert(0);
	    break;
	}
	return sz;
    }
};

template<>
struct packer_sizer<libmidi::spec_v_1_1::event_base::pointer_list> {
    using event_base_list = libmidi::spec_v_1_1::event_base::pointer_list;

    static size_t size(const event_base_list& event_base_list_) {
	int sz = 0;
	std::for_each(event_base_list_.begin(), event_base_list_.end(), [&](const event_base::pointer& eptr) {
		sz += packer_sizer<event_base>::size(*eptr);
	    });
	sz += 4;		// end of track (00ff 2f00)

	return sz;
    }
};

template<>
struct packer_sizer<libmidi::spec_v_1_1::track> {
    using track = libmidi::spec_v_1_1::track;
    using chunk_type = libmidi::spec_v_1_1::chunk_type;
    using event_base_list = libmidi::spec_v_1_1::event_base::pointer_list;
    using chunk_length = libmidi::spec_v_1_1::chunk_length;

    static size_t size(const track& track_) {
	int sz = 0;
	sz += packer_sizer<chunk_type>::size(static_cast<const chunk_type&>(track_));
	sz += packer_sizer<event_base_list>::size(static_cast<const event_base_list&>(track_));
	sz += packer_sizer<chunk_length>::size(chunk_length(sz)); // chunk_length

	return sz;
    }
};

template<>
struct packer_sizer<libmidi::spec_v_1_1::file> {
    using file = libmidi::spec_v_1_1::file;
    using head = libmidi::spec_v_1_1::head;
    using track = libmidi::spec_v_1_1::track;
    using track_list = libmidi::spec_v_1_1::track_list;

    static size_t size(const file& file_) {
	const head& head_ = get<head>(file_);
	const track_list& track_list_ = get<track_list>(file_);

	assert(track_list_.size() > 0);

	int sz = 0;
	sz += packer_sizer<head>::size(head_);
	std::for_each(track_list_.begin(), track_list_.end(), [&](const track& t) {
		sz += packer_sizer<track>::size(t);
	    });
	return sz;
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_PACKER_SIZER_HPP__ */
