#include "libmidi/spec_v_1_1/enum_percussion.hpp"

namespace libmidi { namespace spec_v_1_1 {

constexpr std::pair<enum_percussion, const char*> string_of_enum_percussion[] = {
    {enum_percussion::Acoustic_Bass_Drum, "Acoustic_Bass_Drum"},
    {enum_percussion::Bass_Drum_1, "Bass_Drum_1"},
    {enum_percussion::Side_Stick, "Side_Stick"},
    {enum_percussion::Acoustic_Snare, "Acoustic_Snare"},
    {enum_percussion::Hand_Clap, "Hand_Clap"},
    {enum_percussion::Electric_Snare, "Electric_Snare"},
    {enum_percussion::Low_Floor_Tom, "Low_Floor_Tom"},
    {enum_percussion::Closed_Hi_Hat, "Closed_Hi_Hat"},
    {enum_percussion::High_Floor_Tom, "High_Floor_Tom"},
    {enum_percussion::Pedal_Hi_Hat, "Pedal_Hi_Hat"},
    {enum_percussion::Low_Tom, "Low_Tom"},
    {enum_percussion::Open_Hi_Hat, "Open_Hi_Hat"},
    {enum_percussion::Low_Mid_Tom, "Low_Mid_Tom"},
    {enum_percussion::Hi_Mid_Tom, "Hi_Mid_Tom"},
    {enum_percussion::Crash_Cymbal_1, "Crash_Cymbal_1"},
    {enum_percussion::High_Tom, "High_Tom"},
    {enum_percussion::Ride_Cymbal_1, "Ride_Cymbal_1"},
    {enum_percussion::Chinese_Cymbal, "Chinese_Cymbal"},
    {enum_percussion::Ride_Bell, "Ride_Bell"},
    {enum_percussion::Tambourine, "Tambourine"},
    {enum_percussion::Splash_Cymbal, "Splash_Cymbal"},
    {enum_percussion::Cowbell, "Cowbell"},
    {enum_percussion::Crash_Cymbal_2, "Crash_Cymbal_2"},
    {enum_percussion::Vibraslap, "Vibraslap"},
    {enum_percussion::Ride_Cymbal_2, "Ride_Cymbal_2"},
    {enum_percussion::Hi_Bongo, "Hi_Bongo"},
    {enum_percussion::Low_Bongo, "Low_Bongo"},
    {enum_percussion::Mute_Hi_Conga, "Mute_Hi_Conga"},
    {enum_percussion::Open_Hi_Conga, "Open_Hi_Conga"},
    {enum_percussion::Low_Conga, "Low_Conga"},
    {enum_percussion::High_Timbale, "High_Timbale"},
    {enum_percussion::Low_Timbale, "Low_Timbale"},
    {enum_percussion::High_Agogo, "High_Agogo"},
    {enum_percussion::Low_Agogo, "Low_Agogo"},
    {enum_percussion::Cabasa, "Cabasa"},
    {enum_percussion::Maracas, "Maracas"},
    {enum_percussion::Short_Whistle, "Short_Whistle"},
    {enum_percussion::Long_Whistle, "Long_Whistle"},
    {enum_percussion::Short_Guiro, "Short_Guiro"},
    {enum_percussion::Long_Guiro, "Long_Guiro"},
    {enum_percussion::Claves, "Claves"},
    {enum_percussion::Hi_Wood_Block, "Hi_Wood_Block"},
    {enum_percussion::Low_Wood_Block, "Low_Wood_Block"},
    {enum_percussion::Mute_Cuica, "Mute_Cuica"},
    {enum_percussion::Open_Cuica, "Open_Cuica"},
    {enum_percussion::Mute_Triangle, "Mute_Triangle"},
    {enum_percussion::Open_Triangle, "Open_Triangle"}
};

std::ostream& operator<<(std::ostream& os, enum_percussion o) {
    size_t i = 0;
    for (; i < sizeof(string_of_enum_percussion); ++i) {
	if (string_of_enum_percussion[i].first == o)
	    break;
    }
    return os << "enum_percussion::" << string_of_enum_percussion[i].second;
}

}}
