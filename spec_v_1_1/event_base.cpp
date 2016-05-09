#include "libmidi/spec_v_1_1/event_base.hpp"

namespace libmidi { namespace spec_v_1_1 {

event_base::event_base()
{}

event_base::event_base(const delta_time& delta_time_, enum_message_type enum_message_type_)
    : delta_time(delta_time_)
{
    set_enum<enum_message_type>(enum_message_type_);
}

}}
