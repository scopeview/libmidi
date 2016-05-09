#ifndef __LIBMIDI_SPEC_V_1_1_EVENT_BASE_HPP__
#define __LIBMIDI_SPEC_V_1_1_EVENT_BASE_HPP__

#include <memory>
#include <list>
#include "libmidi/spec_v_1_1/delta_time.hpp"
#include "libmidi/spec_v_1_1/message_type.hpp"
#include "libtemplate/_.hpp"

namespace libmidi { namespace spec_v_1_1 {

class event_base : public delta_time,
		   public libtemplate::enum_selector<enum_message_type>
{
public:
    typedef std::shared_ptr<event_base> pointer;
    typedef std::list<pointer> pointer_list;

    event_base();
    event_base(const delta_time&, enum_message_type);
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_EVENT_BASE_HPP__ */
