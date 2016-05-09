#ifndef __LIBMIDI_SPEC_V_1_1_FILE_HPP__
#define __LIBMIDI_SPEC_V_1_1_FILE_HPP__

#include <list>
#include "libmidi/spec_v_1_1/head.hpp"
#include "libmidi/spec_v_1_1/track.hpp"

namespace libmidi { namespace spec_v_1_1 {

class file : public head,
	     public track_list
{
public:
    file();
    typedef std::pair<std::shared_ptr<char>, size_t> generate_result;

    generate_result generate();

    // - head chunk
    // - track count
    // - track to music::script
    std::string dump();
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_FILE_HPP__ */
