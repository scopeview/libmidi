#include "libtemplate/cast/underlying_value.hpp"
#include "libmidi/spec_v_1_1/instrument_family_helper.hpp"

namespace libmidi { namespace spec_v_1_1 {

bool is_instrument_family(enum_instrument inst, enum_instrument_family inst_family)
{
    int index = libtemplate::underlying_value(inst);
    int f_index = libtemplate::underlying_value(inst_family);
    return f_index == index / 8;
}

enum_instrument_family to_instrument_family(enum_instrument inst)
{
    int index = libtemplate::underlying_value(inst);
    return static_cast<enum_instrument_family>(index / 8);
}

}}
