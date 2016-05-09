#ifndef __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_UNPACKER_HPP__
#define __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_UNPACKER_HPP__

#include <algorithm>
#include <sstream>
#include <tuple>
#include <functional>
#include <type_traits>
#include "libtemplate/_.hpp"
#include "libtraits/traits/unpacker.hpp"
#include "libmidi/spec_v_1_1/unpack_msb.hpp"
#include "libmidi/spec_v_1_1/internal_midi_types.hpp"
#include "libmidi/spec_v_1_1/traits/_.hpp"
#include "libmidi/spec_v_1_1/traits_extension/_.hpp"

namespace libtraits { namespace traits {

using namespace libmidi::spec_v_1_1;

////////////////////////////////////////////////////////////////
// unpacker (default)
////////////////////////////////////////////////////////////////
#define DEFINE_UNPACKER(TYPE)					\
template<>							\
struct unpacker<TYPE> {						\
    template<typename IT>					\
    static void unpack(IT& it, TYPE& TYPE_) {			\
	typedef decltype(std::declval<TYPE>().value()) value_type; \
	value_type value;					\
	unpack_msb(it, value);					\
	TYPE_.set_value(value);					\
    }								\
};								\
/***/

DEFINE_UNPACKER(division);
DEFINE_UNPACKER(channel);
// DEFINE_UNPACKER(key);
DEFINE_UNPACKER(track_count);


////////////////////////////////////////////////////////////////
// packer (use base class value)
////////////////////////////////////////////////////////////////
template<>
struct unpacker<value> {
    template<typename IT>
    static void unpack(IT& it, value& value_) {
	value_ = value(*it++);
    }
};

#define DEFINE_UNPACKER_USE_BASE_CLASS_VALUE(TYPE)	\
    template<>						\
    struct unpacker<TYPE> {				\
	template<typename IT>				\
	static void unpack(IT& it, TYPE& TYPE_) {	\
	    unpacker<value>::unpack(it, static_cast<value&>(TYPE_));	\
	}						\
    };							\
/***/

DEFINE_UNPACKER_USE_BASE_CLASS_VALUE(velocity);
DEFINE_UNPACKER_USE_BASE_CLASS_VALUE(controller_number);

////////////////////////////////////////////////////////////////
// packer (primitive)
////////////////////////////////////////////////////////////////
template<>
struct unpacker<std::string> {
    template<typename IT>
    static void unpack(IT& it, IT& it_end, std::string& t) {
	std::stringstream ss;
	while (it != it_end) {
	    ss << *it++;
	}
	t = ss.str();
    }
};

template<>
struct unpacker<char> {
    template<typename IT>
    static void unpack(IT& it, char& c) {
	c = *it++;
    }
    // TODO
    // - unpack char*
};

template<>
struct unpacker<uint8_t> {
    template<typename IT>
    static void unpack(IT& it, uint8_t& c) {
	c = *it++;
    }
};

template<>
struct unpacker<std::array<uint8_t, 2>> {
    template<typename IT>
	static void unpack(IT& it, std::array<uint8_t, 2>& t) {
	t[0] = *it++;
	t[1] = *it++;
    }
};

////////////////////////////////////////////////////////////////
// packer (variable_length_quantity)
////////////////////////////////////////////////////////////////
template<>
struct unpacker<variable_length_quantity> {
    template<typename IT>
    static void unpack(IT& it, variable_length_quantity& variable_length_quantity_) {
	std::array<uint8_t, 4> a4 = {};
	for (int i = 0; i < 4; ++i) {
	    auto it_first = a4.begin();
	    ++it_first;
	    std::rotate(a4.begin(), it_first, a4.end());
	    a4[3] = *it;
	    if (!(*it & 0x80)) {
		++it;
		break;
	    }
	    ++it;
	}
	variable_length_quantity_.set_value(a4);
    }
};

#define DEFINE_UNPACKER_AS_VARIABLE_LENGTH_QUANTITY(TYPE)	\
    template<>							\
    struct unpacker<TYPE> {					\
	template<typename IT>					\
	static void unpack(IT& it, TYPE& TYPE_) {		\
	    variable_length_quantity v;				\
	    unpacker<variable_length_quantity>::unpack(it, v);	\
	    TYPE_.set_value(v.get_actural());			\
	}							\
    };								\
/***/

DEFINE_UNPACKER_AS_VARIABLE_LENGTH_QUANTITY(delta_time);


////////////////////////////////////////////////////////////////
template<>
struct unpacker<key> {
    template<typename IT>
    static void unpack(IT& it, key& key_) {
	key_ = key(static_cast<key::type>(*it++));
    }
};

template<>
struct unpacker<midi_format> {
    template<typename IT>
    static void unpack(IT& it, midi_format& midi_format_) {
	uint16_t data;
	unpack_msb(it, data);
	midi_format_ = midi_format(static_cast<enum_midi_format>(data));
    }
};

template<>
struct unpacker<chunk_type> {
    template<typename IT>
    static void unpack(IT& it, chunk_type& chunk_type_) {
	std::array<char, 4> a;
	a[0] = *it++;
	a[1] = *it++;
	a[2] = *it++;
	a[3] = *it++;
	chunk_type_.set_value(a);
    }
};

template<>
struct unpacker<chunk_length> {
    template<typename IT>
    static void unpack(IT& it, chunk_length& chunk_length_) {
	uint32_t n;
	unpack_msb(it, n);
	chunk_length_ = chunk_length(n);
    }
};

template<>
struct unpacker<key_signature> {
    template<typename IT>
    static void unpack(IT& it, key_signature& key_signature_) {
	key_signature::sf sf = static_cast<key_signature::sf>(*it++);
	key_signature::mi mi = static_cast<key_signature::mi>(*it++);

	key_signature_ = key_signature(sf, mi);
    }
};

template<>
struct unpacker<message_type> {
    template<typename IT>
    static void unpack(IT& it, message_type& message_type_) {
	uint16_t data = 0;
	if (libtemplate::integral_eq<uint8_t>(*it, 0xFF)) {
	    data = 0xFF00;
	    ++it;
	}
	data |= (uint8_t)(*it++);
	message_type_.set_value(data);
    }
};

template<>
struct unpacker<tempo> {
    template<typename IT>
    static void unpack(IT& it, tempo& tempo_) {
	std::array<uint8_t, 3> a;
	a[0] = *it++;
	a[1] = *it++;
	a[2] = *it++;
	
	tempo_.set_value(a);
    }
};

template<>
struct unpacker<smpte_offset> {
    template<typename IT>
    static void unpack(IT& it, smpte_offset& smpte_offset_) {
	// TODO
    }
};

template<>
struct unpacker<time_signature> {
    template<typename IT>
    static void unpack(IT& it, time_signature& time_signature_) {
	// TODO
    }
};

template<>
struct unpacker<variable_message_data> {
    template<typename IT>
    static void unpack(IT& it, variable_message_data& variable_message_data_) {
	// TODO
    }

    template<typename IT>
    static void unpack(IT& it, IT& it_end, variable_message_data& variable_message_data_) {
	// TODO
    }
};

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
namespace helper {

////////////////
// variable_unpacker
template<typename Tuple,
	 bool is_range = std::is_same<std::string, typename std::tuple_element<0, Tuple>::type>::value>
struct variable_unpacker {
    template<typename IT>
    static void unpack(IT& it, IT& it_end, Tuple& tuple_) {
	unpacker<Tuple>::unpack(it, tuple_);
    }
};

template<typename Tuple>
struct variable_unpacker<Tuple, true> {
    template<typename IT>
    static void unpack(IT& it, IT& it_end, Tuple& tuple_) {
	unpacker<Tuple>::unpack(it, it_end, tuple_);
    }
};

template<enum_message_type enum_message_type_, 
	 enum_message_category C = libtraits::traits::constexpr_mapper<enum_message_type,
								       enum_message_type_,
								       enum_message_category>::map()>
struct category_event_unpacker {
    template<typename IT>
    static void unpack(IT& it, event<enum_message_type_>& event_) {
	event_base& event_base_ = event_;
	delta_time& delta_time_ = static_cast<delta_time&>(event_base_);
	message_type message_type_;

	unpacker<delta_time>::unpack(it, delta_time_);
	unpacker<message_type>::unpack(it, message_type_);

	event_base_.set_enum<enum_message_type>(message_type_.get_enum_message_type());

	typedef typename event<enum_message_type_>::tuple_type tuple_type;
	tuple_type& tuple_ = event_;
	unpacker<tuple_type>::unpack(it, tuple_);
    }
};

template<enum_message_type enum_message_type_>
struct category_event_unpacker<enum_message_type_, enum_message_category::meta_message_type> {
    template<typename IT>
    static void unpack(IT& it, event<enum_message_type_>& event_) {
	event_base& event_base_ = event_;
	delta_time& delta_time_ = static_cast<delta_time&>(event_base_);
	message_type message_type_;
	variable_length_quantity variable_length_quantity_;

	unpacker<delta_time>::unpack(it, delta_time_);
	unpacker<message_type>::unpack(it, message_type_);
	unpacker<variable_length_quantity>::unpack(it, variable_length_quantity_);

	event_base_.set_enum<enum_message_type>(message_type_.get_enum_message_type());

	typedef typename event<enum_message_type_>::tuple_type tuple_type;
	tuple_type& tuple_ = event_;
	IT it_end = it;
	std::advance(it_end, variable_length_quantity_.get_actural());
	variable_unpacker<tuple_type>::unpack(it, it_end, tuple_);
    }
};

template<enum_message_type enum_message_type_>
struct category_event_unpacker<enum_message_type_, enum_message_category::channel_voice_message_type> {
    template<typename IT>
    static void unpack(IT& it, event<enum_message_type_>& event_) {
	event_base& event_base_ = event_;
	delta_time& delta_time_ = static_cast<delta_time&>(event_base_);
	message_type message_type_;

	unpacker<delta_time>::unpack(it, delta_time_);
	unpacker<message_type>::unpack(it, message_type_);

	event_base_.set_enum<enum_message_type>(message_type_.get_enum_message_type());

	typedef typename event<enum_message_type_>::tuple_type tuple_type;
	tuple_type& tuple_ = event_;
	std::get<0>(tuple_) = static_cast<channel&>(message_type_);
	unpacker<tuple_type>::template unpack<1>(it, tuple_);
    }
};


////////////////
template<enum_message_type enum_message_type_, 
	 bool is_parameter_size_1 = std::tuple_size<typename libmidi::spec_v_1_1::traits::parameter_tuple<
					    enum_message_type_>::type>::value == 1>
struct event_unpacker {
    template<typename IT>
    static void unpack(IT& it, event<enum_message_type_>& event_) {
	category_event_unpacker<enum_message_type_>::unpack(it, event_);
    }
};

template<enum_message_type enum_message_type_>
struct event_unpacker<enum_message_type_, true> {
    template<typename IT>
    static void unpack(IT& it, event<enum_message_type_>& event_) {
	event_base& event_base_ = event_;
	delta_time& delta_time_ = static_cast<delta_time&>(event_base_);
	message_type message_type_;

	unpacker<delta_time>::unpack(it, delta_time_);
	unpacker<message_type>::unpack(it, message_type_);

	event_base_.set_enum<enum_message_type>(message_type_.get_enum_message_type());
    }
};

}

////////////////////////////////////////////////////////////////
template<enum_message_type enum_message_type_>
struct unpacker<event<enum_message_type_>> {
    template<typename IT>
    static void unpack(IT& it, event<enum_message_type_>& event_) {
	helper::event_unpacker<enum_message_type_>::unpack(it, event_);
    }
};

template<>
struct unpacker<event<enum_message_type::system_exclusive>> {
    template<typename IT>
    static void unpack(IT& it, event<enum_message_type::system_exclusive>& event_) {
	event_base& event_base_ = event_;
	delta_time& delta_time_ = static_cast<delta_time&>(event_base_);
	message_type message_type_;

	unpacker<delta_time>::unpack(it, delta_time_);
	unpacker<message_type>::unpack(it, message_type_);

	event_base_.set_enum<enum_message_type>(message_type_.get_enum_message_type());

	// find end of system exclusive (0xF7)
	IT& it_find = it;
	while (*it_find != 0xF7) {
	    ++it_find;
	}

	// 
	typedef typename libmidi::spec_v_1_1::traits::parameter_tuple<enum_message_type::system_exclusive>::type parameter_tuple_type;
	typedef typename libtemplate::type_sequence::drop_left1<parameter_tuple_type>::type tuple_type;
	tuple_type& tuple_ = event_;
	variable_message_data& variable_message_data_ = std::get<0>(tuple_);
	variable_message_data_ = variable_message_data(&*it, std::distance(it, it_find));

	it = it_find;
	++it;			// skip end_of_system_exclusive
    }
};

////////////////////////////////////////////////////////////////
#define DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(ENUM_MESSAGE_TYPE)	\
    case ENUM_MESSAGE_TYPE:						\
		       {						\
			   std::shared_ptr<event<ENUM_MESSAGE_TYPE>> tmp_event(new event<ENUM_MESSAGE_TYPE>); \
			   unpacker<event<ENUM_MESSAGE_TYPE>>::unpack(it, *tmp_event); \
			   event_ptr = std::static_pointer_cast<event_base, event<ENUM_MESSAGE_TYPE>>(tmp_event); \
		       }						\
		       break						\
/***/

template<>
struct unpacker<event_base::pointer> {
    template<typename IT>
    static void unpack(IT& it, event_base::pointer& event_ptr) {
	IT it_begin = it;

	delta_time delta_time_;
	message_type message_type_;

	unpacker<delta_time>::unpack(it, delta_time_);
	unpacker<message_type>::unpack(it, message_type_);

	it = it_begin;

	enum_message_type enum_ = message_type_.get_enum_message_type();
	switch (enum_) {
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_sequence_number);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_text);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_copyright_notice);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_sequence_track_name);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_instrument_name);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_lyric);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_marker);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_text_cue_point);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_midi_channel_prefix);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_end_of_track);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_tempo);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_smpte_offset);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_time_signature);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_key_signature);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::meta_sequencer_specific_meta_event);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::note_off);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::note_on);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::polyphonic_key_pressure);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::control_change);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::program_change);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::channel_pressure);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::pitch_wheel_change);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::system_exclusive);
	    // DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::undefined_B11110001);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::song_position_pointer);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::song_select);
	    // DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::undefined_B11110100);
	    // DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::undefined_B11110101);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::tune_request);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::end_of_exclusive);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::timing_clock);
	    // DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::undefined_B11111001);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::start);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::continue_);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::stop);
	    // DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::undefined_B11111101);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::active_sensing);
	    DEFINE_UNPACKER_UNPACK__EVENT_SWITCH_CASE(enum_message_type::reset);
	default:
	    assert(0);
	    break;
	}
    }
};

template<>
struct unpacker<event_base::pointer_list> {
    template<typename IT>
    static void unpack(IT& it, event_base::pointer_list& event_list_) {
	IT it_tmp;
	while (1) {
	    // peek meta_end_of_track
	    it_tmp = it;
	    if (libtemplate::integral_eq<uint8_t>(*it_tmp++, 0x00) &&
		libtemplate::integral_eq<uint8_t>(*it_tmp++, 0xff) &&
		libtemplate::integral_eq<uint8_t>(*it_tmp++, 0x2f) &&
		libtemplate::integral_eq<uint8_t>(*it_tmp++, 0x00)) {
		break;
	    }
	    
	    event_base::pointer event_;
	    unpacker<event_base::pointer>::unpack(it, event_);
	    event_list_.push_back(event_);
	}

	// ignore end of track (00ff 2f00)
	libtemplate::integral_eq<uint8_t>(*it++, 0x00);
	libtemplate::integral_eq<uint8_t>(*it++, 0xff);
	libtemplate::integral_eq<uint8_t>(*it++, 0x2f);
	libtemplate::integral_eq<uint8_t>(*it++, 0x00);
    }
};

////////////////////////////////////////////////////////////////
template<>
struct unpacker_getter_sequence<head> {
    typedef std::tuple<chunk_type, chunk_length, midi_format, track_count, division> sequence_type;
};

template<>
struct unpacker<head> {
    template<typename IT>
    static void unpack(IT& it, head& head_) {
	unpacker_by_getter<head>::unpack(it, head_);
    }
};

////////////////////////////////////////////////////////////////
template<>
struct unpacker<track> {
    template<typename IT>
    static void unpack(IT& it, track& track_) {
	unpacker<chunk_type>::unpack(it, static_cast<chunk_type&>(track_));
	unpacker<chunk_length>::unpack(it, static_cast<chunk_length&>(track_));
	unpacker<event_base::pointer_list>::unpack(it, static_cast<event_base::pointer_list&>(track_));
    }
};

template<>
struct unpacker<file> {
    template<typename IT>
    static void unpack(IT& it, file& file_) {
	unpacker<head>::unpack(it, static_cast<head&>(file_));
	int track_count_ = libtemplate::static_cast_reference<file, head, track_count>(file_).value();

	track track_;
	track_list& track_list_ = static_cast<track_list&>(file_);
	while (track_count_--) {
	    unpacker<track>::unpack(it, track_);
	    track_list_.push_back(track_);
	}
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_LIBTRAITS_EXTENSION_UNPACKER_HPP__ */
