#include <algorithm>
#include "libmidi/spec_v_1_1/track.hpp"
#include "libmidi/spec_v_1_1/libtraits_extension/packer_sizer.hpp"
#include "libmidi/spec_v_1_1/libtraits_extension/packer.hpp"

namespace libmidi { namespace spec_v_1_1 {

track::track() : chunk_type(chunk_type::TRACK)
{}

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
void track::add_event(const event_base::pointer& e)
{
    event_base::pointer_list& event_base_list_ = *this;
    event_base_list_.push_back(e);
}

void track::add_note(const delta_time& delta_time_, const channel& channel_, 
		     const key& key_, const velocity& velocity_, const duration& duration_)
{
    event_base::pointer_list& event_base_list_ = *this;
    delta_time delta_time_start(delta_time_);
    delta_time delta_time_end(duration_.value());

    event_base_list_.push_back(event<enum_message_type::note_on>::make(delta_time_start, channel_, key_, velocity_));
    event_base_list_.push_back(event<enum_message_type::note_off>::make(delta_time_end, channel_, key_, velocity_));
}

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
void add_melody(track& track_, const channel& channel_,
		const std::list<std::tuple<key, velocity, duration>>& tuple_list)
{
    typedef std::tuple<key, velocity, duration> tuple_type;
    std::for_each(tuple_list.begin(), tuple_list.end(), [&](const tuple_type& tuple_) {
	    track_.add_note(delta_time(0), channel_,
			    std::get<0>(tuple_), std::get<1>(tuple_), std::get<2>(tuple_));
	});
}

}}
