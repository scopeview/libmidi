#include <algorithm>
#include <cassert>
#include <iterator>
#include <functional>
#include "string.h"
#include "libmidi/spec_v_1_1/common.hpp"
#include "libmidi/spec_v_1_1/file.hpp"
#include "libmidi/spec_v_1_1/internal_midi_types.hpp"
#include "libmidi/spec_v_1_1/traits_extension/_.hpp"
#include "libmidi/spec_v_1_1/libtraits_extension/generator.hpp"
#include "libtraits/traits/packer_sizer.hpp"
#include "libtraits/traits/generator.hpp"

namespace libmidi { namespace spec_v_1_1 {

file::file()
{}

file::generate_result file::generate()
{
    ////////////////////////////////////////////////////////////////
    // buffer
    int track_byte_count = libtraits::packer_size(*this);
    std::shared_ptr<char> midi_output = std::shared_ptr<char>(new char[track_byte_count], std::default_delete<char[]>());
    
    ////////////////////////////////////////////////////////////////
    // fill
    char* ptr = midi_output.get();
    typedef __gnu_cxx::__normal_iterator<char*, C> iterator_type;
    iterator_type it(ptr);

    libtraits::traits::generator<file>::generate(it, *this);

    return generate_result(midi_output, track_byte_count);
}

}}
