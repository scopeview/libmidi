#ifndef __LIBMIDI_SPEC_V_1_1_TRACK_HPP__
#define __LIBMIDI_SPEC_V_1_1_TRACK_HPP__

#include <list>
#include "libmidi/spec_v_1_1/internal_midi_types.hpp"

namespace libmidi { namespace spec_v_1_1 {

// chunk_length is calculated in generate
class track : public chunk_type,
	      public chunk_length,
	      public event_base::pointer_list
{
public:
    track();

    void add_event(const event_base::pointer&);

    template<enum_message_type enum_message_type_>
    void add_event(const std::shared_ptr<event<enum_message_type_>>& event_) {
	add_event(std::static_pointer_cast<event_base, event<enum_message_type_>>(event_));
    }

    void add_note(const delta_time&, const channel&, const key&, const velocity&, const duration&);
};
typedef std::list<track> track_list;

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
void add_melody(track&, const channel&, const std::list<std::tuple<key, velocity, duration>>&);

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_TRACK_HPP__ */
