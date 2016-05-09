#include "libmidi/spec_v_1_1/enum_instrument_family.hpp"

namespace libmidi { namespace spec_v_1_1 {

constexpr std::pair<enum_instrument_family, const char*> string_of_enum_instrument_family[] = {
    {enum_instrument_family::Piano, "Piano"},
    {enum_instrument_family::Chromatic_Percussion, "Chromatic_Percussion"},
    {enum_instrument_family::Organ, "Organ"},
    {enum_instrument_family::Guitar, "Guitar"},
    {enum_instrument_family::Bass, "Bass"},
    {enum_instrument_family::Strings, "Strings"},
    {enum_instrument_family::Ensemble, "Ensemble"},
    {enum_instrument_family::Brass, "Brass"},
    {enum_instrument_family::Reed, "Reed"},
    {enum_instrument_family::Pipe, "Pipe"},
    {enum_instrument_family::Synth_Lead, "Synth_Lead"},
    {enum_instrument_family::Synth_Pad, "Synth_Pad"},
    {enum_instrument_family::Synth_Effects, "Synth_Effects"},
    {enum_instrument_family::Ethnic, "Ethnic"},
    {enum_instrument_family::Percussive, "Percussive"},
    {enum_instrument_family::Sound_Effects, "Sound_Effects"}
};

std::ostream& operator<<(std::ostream& os, enum_instrument_family o) {
    size_t i = 0;
    for (;i < sizeof(string_of_enum_instrument_family); ++i) {
	if (string_of_enum_instrument_family[i].first == o)
	    break;
    }
    return os << "enum_instrument_family::" << string_of_enum_instrument_family[i].second;
}

}}
