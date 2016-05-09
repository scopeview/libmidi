#ifndef __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_PACKER_HPP__
#define __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_PACKER_HPP__

#include <algorithm>
#include <tuple>
#include "libtemplate/cast/underlying_value.hpp"
#include "libtraits/traits/packer.hpp"
#include "libtraits/traits/packer_by_getter.hpp"
#include "libmidi/spec_v_1_1/pack_msb.hpp"
#include "libmidi/spec_v_1_1/internal_midi_types.hpp"
#include "libmidi/spec_v_1_1/traits_extension/_.hpp"
#include "libmidi/spec_v_1_1/libtraits_extension/mapper.hpp"

namespace libtraits { namespace traits {

using namespace libmidi::spec_v_1_1;

////////////////////////////////////////////////////////////////
// packer (default)
////////////////////////////////////////////////////////////////
#define DEFINE_PACKER(TYPE)				\
template<>						\
struct packer<TYPE> {					\
    template<typename IT>				\
    static void pack(IT& it, const TYPE& TYPE_) {	\
	pack_msb(it, TYPE_.value());			\
    }							\
};							\
/***/

DEFINE_PACKER(division);
DEFINE_PACKER(channel);
// DEFINE_PACKER(key);
DEFINE_PACKER(track_count);


////////////////////////////////////////////////////////////////
// packer (use base class value)
////////////////////////////////////////////////////////////////
#define DEFINE_PACKER_USE_BASE_CLASS_VALUE(TYPE)	\
template<>						\
struct packer<TYPE> {					\
    template<typename IT>				\
    static void pack(IT& it, const TYPE& TYPE_) {	\
	pack_msb(it, static_cast<const value&>(TYPE_).get_value());	\
    }							\
};							\
/***/

DEFINE_PACKER_USE_BASE_CLASS_VALUE(value);
DEFINE_PACKER_USE_BASE_CLASS_VALUE(velocity);
DEFINE_PACKER_USE_BASE_CLASS_VALUE(controller_number);


////////////////////////////////////////////////////////////////
// packer (primitive)
////////////////////////////////////////////////////////////////
template<>
struct packer<std::string> {
    template<typename IT>
    static void pack(IT& it, const std::string& t) {
	std::for_each(t.begin(), t.end(), [&](char c) {
		*it++ = c;
	    });
    }
};

template<>
struct packer<char> {
    template<typename IT>
    static void pack(IT& it, char c) {
	*it++ = c;
    }

    template<typename IT>
    static void pack(IT& it, const char* ptr) {
	char* tmp = ptr;
	while (*tmp) {
	    *it++ = *tmp++;
	}
    }
};

template<>
struct packer<uint8_t> {
    template<typename IT>
    static void pack(IT& it, uint8_t c) {
	*it++ = c;
    }
};

template<>
struct packer<std::array<uint8_t, 2>> {
    template<typename IT>
	static void pack(IT& it, const std::array<uint8_t, 2>& t) {
	*it++ = t[0];
	*it++ = t[1];
    }
};


////////////////////////////////////////////////////////////////
// packer (variable_length_quantity)
////////////////////////////////////////////////////////////////
template<>
struct packer<variable_length_quantity> {
    template<typename IT>
    static void pack(IT& it, const variable_length_quantity& variable_length_quantity_) {
	std::array<uint8_t, 4> t(variable_length_quantity_.get_as_variable());
	bool is_zero = true;
	for (int i = 1; i < 4; ++i) {
	    if (t[i]) {
		*it++ = t[i];
		is_zero = false;
	    }
	}
	if (is_zero) {
	    *it++ = 0;
	}
    }
};

#define DEFINE_PACKER_AS_VARIABLE_LENGTH_QUANTITY(TYPE)			\
    template<>								\
    struct packer<TYPE> {						\
	template<typename IT>						\
	static void pack(IT& it, const TYPE& TYPE_) {			\
	    packer<variable_length_quantity>::pack(it, variable_length_quantity(TYPE_.value())); \
	}								\
    };									\
/***/

DEFINE_PACKER_AS_VARIABLE_LENGTH_QUANTITY(delta_time);
// DEFINE_PACKER_AS_VARIABLE_LENGTH_QUANTITY(chunk_length);


////////////////////////////////////////////////////////////////
// packer
////////////////////////////////////////////////////////////////
template<>
struct packer<key> {
    template<typename IT>
    static void pack(IT& it, const key& key_) {
	*it++ = libtemplate::underlying_value(key_.value());
    }
};

template<>
struct packer<midi_format> {
    template<typename IT>
    static void pack(IT& it, const midi_format& midi_format_) {
	uint16_t data = libtemplate::underlying_value(midi_format_.value());
	pack_msb(it, data);
    }
};

template<>
struct packer<chunk_type> {
    template<typename IT>
    static void pack(IT& it, const chunk_type& chunk_type_) {
	std::array<char, 4> a(chunk_type_.value());
	*it++ = a[0];
	*it++ = a[1];
	*it++ = a[2];
	*it++ = a[3];
    }
};

template<>
struct packer<chunk_length> {
    template<typename IT>
    static void pack(IT& it, const chunk_length& chunk_length_) {
	uint32_t data = chunk_length_.value();
	pack_msb(it, data);
    }
};

template<>
struct packer<key_signature> {
    template<typename IT>
    static void pack(IT& it, const key_signature& key_signature_) {
	*it++ = (char)libtemplate::underlying_value(key_signature_.get_sf());
	*it++ = (char)libtemplate::underlying_value(key_signature_.get_mi());
    }
};

template<>
struct packer<message_type> {
    template<typename IT>
    static void pack(IT& it, const message_type& message_type_) {
	uint16_t data = message_type_.get_composed_value();
	if (libtemplate::integral_eq<uint16_t>(data & 0xFF00, 0xFF00)) {
	    pack_msb(it, data);
	} else {
	    *it++ = (char)data;
	}
    }
};

template<>
struct packer<tempo> {
    template<typename IT>
    static void pack(IT& it, const tempo& tempo_) {
	std::array<uint8_t, 3> a(tempo_.value());
	*it++ = a[0];
	*it++ = a[1];
	*it++ = a[2];
    }
};

template<>
struct packer<smpte_offset> {
    template<typename IT>
    static void pack(IT& it, const smpte_offset& smpte_offset_) {
	smpte_offset_.pack(it);
    }
};

template<>
struct packer<time_signature> {
    template<typename IT>
    static void pack(IT& it, const time_signature& time_signature_) {
	// TODO
    }
};

template<>
struct packer<variable_message_data> {
    template<typename IT>
    static void pack(IT& it, const variable_message_data& variable_message_data_) {
	const char* ptr = variable_message_data_.get();
	for (std::size_t i = 0; i < variable_message_data_.size(); ++i) {
	    *it++ = ptr[i];
	}
    }
};

////////////////////////////////////////////////////////////////
namespace helper {

template<enum_message_type enum_message_type_,
	 enum_message_category C = libtraits::traits::constexpr_mapper<enum_message_type,
								       enum_message_type_,
								       enum_message_category>::map()>
struct event_packer {
    template<typename IT>
    static void pack(IT& it, const event<enum_message_type_>& event_) {
	typedef typename event<enum_message_type_>::tuple_type tuple_type;

	const event_base& event_base_ = event_;
	packer<delta_time>::pack(it, static_cast<const delta_time&>(event_base_));
	packer<message_type>::pack(it, message_type(event_base_.get_enum<enum_message_type>()));
	packer<tuple_type>::pack(it, static_cast<const tuple_type&>(event_));
    }
};

template<enum_message_type enum_message_type_>
struct event_packer<enum_message_type_, enum_message_category::channel_voice_message_type> {
    template<typename IT>
    static void pack(IT& it, const event<enum_message_type_>& event_) {
	typedef typename event<enum_message_type_>::tuple_type tuple_type;

	const event_base& event_base_ = event_;
	static_assert(std::is_same<channel, typename std::tuple_element<0, tuple_type>::type>::value, "");
	const channel& channel_ = std::get<0>(static_cast<const tuple_type&>(event_));

	packer<delta_time>::pack(it, static_cast<const delta_time&>(event_base_));
	packer<message_type>::pack(it, message_type(event_base_.get_enum<enum_message_type>(), channel_));
	packer<tuple_type>::template pack<1>(it, static_cast<const tuple_type&>(event_));
    }
};

template<enum_message_type enum_message_type_>
struct event_packer<enum_message_type_, enum_message_category::meta_message_type> {
    template<typename IT>
    static void pack(IT& it, const event<enum_message_type_>& event_) {
	typedef typename event<enum_message_type_>::tuple_type tuple_type;

	const event_base& event_base_ = event_;
	packer<delta_time>::pack(it, static_cast<const delta_time&>(event_base_));
	packer<message_type>::pack(it, message_type(event_base_.get_enum<enum_message_type>()));
	
	const tuple_type& tuple_ = event_;
	variable_length_quantity variable_length_quantity_(packer_sizer<tuple_type>::size(tuple_));

	packer<variable_length_quantity>::pack(it, variable_length_quantity_);
	packer<tuple_type>::template pack<0>(it, tuple_);
    }
};

}

////////////////
template<enum_message_type enum_message_type_>
struct packer<event<enum_message_type_>> {
    template<typename IT>
    static void pack(IT& it, const event<enum_message_type_>& event_) {
	helper::event_packer<enum_message_type_>::pack(it, event_);
    }
};

////////////////////////////////////////////////////////////////
#define PACKER_PACK__EVENT_SWITCH_CASE(ENUM_MESSAGE_TYPE)		\
    case ENUM_MESSAGE_TYPE:						\
    packer<event<ENUM_MESSAGE_TYPE>>::pack(it, static_cast<const event<ENUM_MESSAGE_TYPE>&>(event_base_)); \
    break								\
/***/

template<>
struct packer<event_base> {
    template<typename IT>
    static void pack(IT& it, const event_base& event_base_) {
	// packer<delta_time>::pack(it, static_cast<const delta_time&>(event_base_));
	enum_message_type enum_message_type_ = event_base_.get_enum<enum_message_type>();
	switch (enum_message_type_) {
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_sequence_number);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_text);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_copyright_notice);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_sequence_track_name);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_instrument_name);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_lyric);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_marker);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_cue_point);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_midi_channel_prefix);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_end_of_track);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_tempo);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_smpte_offset);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_time_signature);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_key_signature);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::meta_sequencer_specific_meta_event);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::note_off);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::note_on);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::polyphonic_key_pressure);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::control_change);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::program_change);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::channel_pressure);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::pitch_wheel_change);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::system_exclusive);
	    // PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::undefined_B11110001);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::song_position_pointer);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::song_select);
	    // PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::undefined_B11110100);
	    // PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::undefined_B11110101);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::tune_request);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::end_of_exclusive);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::timing_clock);
	    // PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::undefined_B11111001);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::start);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::continue_);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::stop);
	    // PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::undefined_B11111101);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::active_sensing);
	    PACKER_PACK__EVENT_SWITCH_CASE(enum_message_type::reset);
	default:
	    assert(0);
	    break;
	}
    }
};

template<>
struct packer<event_base::pointer_list> {
    template<typename IT>
    static void pack(IT& it, const event_base::pointer_list& event_base_list_) {
	for (auto it2 = event_base_list_.begin(); it2 != event_base_list_.end(); ++it2) {
	    packer<event_base>::pack(it, **it2);
	}

	// end of track (00ff 2f00)
	*it++ = 0x00;
	*it++ = 0xff;
	*it++ = 0x2f;
	*it++ = 0x00;
    }
};

template<>
struct packer<track> {
    template<typename IT>
    static void pack(IT& it, const track& track_) {
	packer<chunk_type>::pack(it, static_cast<const chunk_type&>(track_));
	packer<chunk_length>::pack(it, static_cast<const chunk_length&>(track_));
	packer<event_base::pointer_list>::pack(it, static_cast<const event_base::pointer_list&>(track_));
    }
};


////////////////////////////////////////////////////////////////
// packer (packer_by_getter)
////////////////////////////////////////////////////////////////
template<>
struct packer_getter_sequence<head> {
    typedef std::tuple<chunk_type, chunk_length, midi_format, track_count, division> sequence_type;
};

template<>
struct packer<head> {
    template<typename IT>
    static void pack(IT& it, const head& head_) {
	packer_by_getter<head>::pack(it, head_);
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_PACKER_HPP__ */
