#include "libmidi/spec_v_1_1/enum_instrument.hpp"

namespace libmidi { namespace spec_v_1_1 {

constexpr std::pair<enum_instrument, const char*> string_of_enum_instrument[] = {
    {enum_instrument::Acoustic_Grand_Piano, "Acoustic_Grand_Piano"},
    {enum_instrument::Bright_Acoustic_Piano, "Bright_Acoustic_Piano"},
    {enum_instrument::Electric_Grand_Piano, "Electric_Grand_Piano"},
    {enum_instrument::Honky_tonk_Piano, "Honky_tonk_Piano"},
    {enum_instrument::Electric_Piano_1__Rhodes_Piano, "Electric_Piano_1__Rhodes_Piano"},
    {enum_instrument::Electric_Piano_2__Chorused_Piano, "Electric_Piano_2__Chorused_Piano"},
    {enum_instrument::Harpsichord, "Harpsichord"},
    {enum_instrument::Clavinet, "Clavinet"},
    {enum_instrument::Celesta, "Celesta"},
    {enum_instrument::Glockenspiel, "Glockenspiel"},
    {enum_instrument::Music_Box, "Music_Box"},
    {enum_instrument::Vibraphone, "Vibraphone"},
    {enum_instrument::Marimba, "Marimba"},
    {enum_instrument::Xylophone, "Xylophone"},
    {enum_instrument::Tubular_Bells, "Tubular_Bells"},
    {enum_instrument::Dulcimer__Santur, "Dulcimer__Santur"},
    {enum_instrument::Drawbar_Organ__Hammond, "Drawbar_Organ__Hammond"},
    {enum_instrument::Percussive_Organ, "Percussive_Organ"},
    {enum_instrument::Rock_Organ, "Rock_Organ"},
    {enum_instrument::Church_Organ, "Church_Organ"},
    {enum_instrument::Reed_Organ, "Reed_Organ"},
    {enum_instrument::Accordion__French, "Accordion__French"},
    {enum_instrument::Harmonica, "Harmonica"},
    {enum_instrument::Tango_Accordion__Band_neon, "Tango_Accordion__Band_neon"},
    {enum_instrument::Acoustic_Guitar__nylon, "Acoustic_Guitar__nylon"},
    {enum_instrument::Acoustic_Guitar__steel, "Acoustic_Guitar__steel"},
    {enum_instrument::Electric_Guitar__jazz, "Electric_Guitar__jazz"},
    {enum_instrument::Electric_Guitar__clean, "Electric_Guitar__clean"},
    {enum_instrument::Electric_Guitar__muted, "Electric_Guitar__muted"},
    {enum_instrument::Overdriven_Guitar, "Overdriven_Guitar"},
    {enum_instrument::Distortion_Guitar, "Distortion_Guitar"},
    {enum_instrument::Guitar_harmonics, "Guitar_harmonics"},
    {enum_instrument::Acoustic_Bass, "Acoustic_Bass"},
    {enum_instrument::Electric_Bass__fingered, "Electric_Bass__fingered"},
    {enum_instrument::Electric_Bass__picked, "Electric_Bass__picked"},
    {enum_instrument::Fretless_Bass, "Fretless_Bass"},
    {enum_instrument::Slap_Bass_1, "Slap_Bass_1"},
    {enum_instrument::Slap_Bass_2, "Slap_Bass_2"},
    {enum_instrument::Synth_Bass_1, "Synth_Bass_1"},
    {enum_instrument::Synth_Bass_2, "Synth_Bass_2"},
    {enum_instrument::Violin, "Violin"},
    {enum_instrument::Viola, "Viola"},
    {enum_instrument::Cello, "Cello"},
    {enum_instrument::Contrabass, "Contrabass"},
    {enum_instrument::Tremolo_Strings, "Tremolo_Strings"},
    {enum_instrument::Pizzicato_Strings, "Pizzicato_Strings"},
    {enum_instrument::Orchestral_Harp, "Orchestral_Harp"},
    {enum_instrument::Timpani, "Timpani"},
    {enum_instrument::String_Ensemble_1__strings, "String_Ensemble_1__strings"},
    {enum_instrument::String_Ensemble_2__slow_strings, "String_Ensemble_2__slow_strings"},
    {enum_instrument::SynthStrings_1, "SynthStrings_1"},
    {enum_instrument::SynthStrings_2, "SynthStrings_2"},
    {enum_instrument::Choir_Aahs, "Choir_Aahs"},
    {enum_instrument::Voice_Oohs, "Voice_Oohs"},
    {enum_instrument::Synth_Voice, "Synth_Voice"},
    {enum_instrument::Orchestra_Hit, "Orchestra_Hit"},
    {enum_instrument::Trumpet, "Trumpet"},
    {enum_instrument::Trombone, "Trombone"},
    {enum_instrument::Tuba, "Tuba"},
    {enum_instrument::Muted_Trumpet, "Muted_Trumpet"},
    {enum_instrument::French_Horn, "French_Horn"},
    {enum_instrument::Brass_Section, "Brass_Section"},
    {enum_instrument::SynthBrass_1, "SynthBrass_1"},
    {enum_instrument::SynthBrass_2, "SynthBrass_2"},
    {enum_instrument::Soprano_Sax, "Soprano_Sax"},
    {enum_instrument::Alto_Sax, "Alto_Sax"},
    {enum_instrument::Tenor_Sax, "Tenor_Sax"},
    {enum_instrument::Baritone_Sax, "Baritone_Sax"},
    {enum_instrument::Oboe, "Oboe"},
    {enum_instrument::English_Horn, "English_Horn"},
    {enum_instrument::Bassoon, "Bassoon"},
    {enum_instrument::Clarinet, "Clarinet"},
    {enum_instrument::Piccolo, "Piccolo"},
    {enum_instrument::Flute, "Flute"},
    {enum_instrument::Recorder, "Recorder"},
    {enum_instrument::Pan_Flute, "Pan_Flute"},
    {enum_instrument::Blown_Bottle, "Blown_Bottle"},
    {enum_instrument::Shakuhachi, "Shakuhachi"},
    {enum_instrument::Whistle, "Whistle"},
    {enum_instrument::Ocarina, "Ocarina"},
    {enum_instrument::Lead_1__square_wave, "Lead_1__square_wave"},
    {enum_instrument::Lead_2__sawtooth_wave, "Lead_2__sawtooth_wave"},
    {enum_instrument::Lead_3__calliope, "Lead_3__calliope"},
    {enum_instrument::Lead_4__chiffer, "Lead_4__chiffer"},
    {enum_instrument::Lead_5__charang, "Lead_5__charang"},
    {enum_instrument::Lead_6__voice_solo, "Lead_6__voice_solo"},
    {enum_instrument::Lead_7__fifths, "Lead_7__fifths"},
    {enum_instrument::Lead_8__bass_plus_lead, "Lead_8__bass_+_lead"},
    {enum_instrument::Pad_1__new_age_Fantasia, "Pad_1__new_age_Fantasia"},
    {enum_instrument::Pad_2__warm, "Pad_2__warm"},
    {enum_instrument::Pad_3__polysynth, "Pad_3__polysynth"},
    {enum_instrument::Pad_4__choir_space_voice, "Pad_4__choir_space_voice"},
    {enum_instrument::Pad_5__bowed_glass, "Pad_5__bowed_glass"},
    {enum_instrument::Pad_6__metallic_pro, "Pad_6__metallic_pro"},
    {enum_instrument::Pad_7__halo, "Pad_7__halo"},
    {enum_instrument::Pad_8__sweep, "Pad_8__sweep"},
    {enum_instrument::FX_1__rain, "FX_1__rain"},
    {enum_instrument::FX_2__soundtrack, "FX_2__soundtrack"},
    {enum_instrument::FX_3__crystal, "FX_3__crystal"},
    {enum_instrument::FX_4__atmosphere, "FX_4__atmosphere"},
    {enum_instrument::FX_5__brightness, "FX_5__brightness"},
    {enum_instrument::FX_6__goblins, "FX_6__goblins"},
    {enum_instrument::FX_7__echoes__drops, "FX_7__echoes__drops"},
    {enum_instrument::FX_8__sci_fi__star_theme, "FX_8__sci_fi__star_theme"},
    {enum_instrument::Sitar, "Sitar"},
    {enum_instrument::Banjo, "Banjo"},
    {enum_instrument::Shamisen, "Shamisen"},
    {enum_instrument::Koto, "Koto"},
    {enum_instrument::Kalimba, "Kalimba"},
    {enum_instrument::Bag_pipe, "Bag_pipe"},
    {enum_instrument::Fiddle, "Fiddle"},
    {enum_instrument::Shanai, "Shanai"},
    {enum_instrument::Tinkle_Bell, "Tinkle_Bell"},
    {enum_instrument::Agogo, "Agogo"},
    {enum_instrument::Steel_Drums, "Steel_Drums"},
    {enum_instrument::Woodblock, "Woodblock"},
    {enum_instrument::Taiko_Drum, "Taiko_Drum"},
    {enum_instrument::Melodic_Tom, "Melodic_Tom"},
    {enum_instrument::Synth_Drum, "Synth_Drum"},
    {enum_instrument::Reverse_Cymbal, "Reverse_Cymbal"},
    {enum_instrument::Guitar_Fret_Noise, "Guitar_Fret_Noise"},
    {enum_instrument::Breath_Noise, "Breath_Noise"},
    {enum_instrument::Seashore, "Seashore"},
    {enum_instrument::Bird_Tweet, "Bird_Tweet"},
    {enum_instrument::Telephone_Ring, "Telephone_Ring"},
    {enum_instrument::Helicopter, "Helicopter"},
    {enum_instrument::Applause, "Applause"},
    {enum_instrument::Gunshot, "Gunshot"}
};

std::ostream& operator<<(std::ostream& os, enum_instrument o) {
    size_t i = 0;
    for (;i < sizeof(string_of_enum_instrument); ++i) {
	if (string_of_enum_instrument[i].first == o)
	    break;
    }
    return os << "enum_instrument::" << string_of_enum_instrument[i].second;
}

}}
