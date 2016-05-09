#ifndef __LIBMIDI_SPEC_V_1_1_EVENT_HPP__
#define __LIBMIDI_SPEC_V_1_1_EVENT_HPP__

#include <memory>
#include <list>
#include "libmidi/spec_v_1_1/delta_time.hpp"
#include "libmidi/spec_v_1_1/message_type.hpp"
#include "libmidi/spec_v_1_1/traits_extension/parameter_tuple.hpp"

namespace libmidi { namespace spec_v_1_1 {

template<enum_message_type enum_message_type_,
	 typename Parameter = typename traits::parameter_tuple<enum_message_type_>::type,
	 typename Tuple = typename libtemplate::type_sequence::drop_left1<Parameter>::type>
class event : public event_base,
	      public Tuple {
public:
    typedef event<enum_message_type_> self;
    typedef Tuple tuple_type;

    template<typename... Args>
    static std::shared_ptr<self> make(const delta_time& delta_time_, const Args&... args) {
	static_assert(std::is_same<std::tuple<delta_time, Args...>, 
		      typename traits::parameter_tuple<enum_message_type_>::type>::value, "");
	
	return std::shared_ptr<self>(new self(delta_time_, args...));
    }

    event() {}

    template<typename... Args>
    event(const delta_time& delta_time_, const Args&... args) 
	: event_base(delta_time_, enum_message_type_), Tuple(args...) 
	{
	    static_assert(std::is_same<tuple_type, std::tuple<Args...>>::value, "");
	}
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_EVENT_HPP__ */
