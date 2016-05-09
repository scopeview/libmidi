#ifndef __LIBMIDI_SPEC_V_1_1_ENUM_PERCUSSION_HPP__
#define __LIBMIDI_SPEC_V_1_1_ENUM_PERCUSSION_HPP__

#include <utility>
#include <iostream>

namespace libmidi { namespace spec_v_1_1 {

enum class enum_percussion : char {
    Acoustic_Bass_Drum = 35,
	Bass_Drum_1 = 36,
	Side_Stick = 37,
	Acoustic_Snare = 38,
	Hand_Clap = 39,
	Electric_Snare = 40,
	Low_Floor_Tom = 41,
	Closed_Hi_Hat = 42,
	High_Floor_Tom = 43,
	Pedal_Hi_Hat = 44,
	Low_Tom = 45,
	Open_Hi_Hat = 46,
	Low_Mid_Tom = 47,
	Hi_Mid_Tom = 48,
	Crash_Cymbal_1 = 49,
	High_Tom = 50,
	Ride_Cymbal_1 = 51,
	Chinese_Cymbal = 52,
	Ride_Bell = 53,
	Tambourine = 54,
	Splash_Cymbal = 55,
	Cowbell = 56,
	Crash_Cymbal_2 = 57,
	Vibraslap = 58,
	Ride_Cymbal_2 = 59,
	Hi_Bongo = 60,
	Low_Bongo = 61,
	Mute_Hi_Conga = 62,
	Open_Hi_Conga = 63,
	Low_Conga = 64,
	High_Timbale = 65,
	Low_Timbale = 66,
	High_Agogo = 67,
	Low_Agogo = 68,
	Cabasa = 69,
	Maracas = 70,
	Short_Whistle = 71,
	Long_Whistle = 72,
	Short_Guiro = 73,
	Long_Guiro = 74,
	Claves = 75,
	Hi_Wood_Block = 76,
	Low_Wood_Block = 77,
	Mute_Cuica = 78,
	Open_Cuica = 79,
	Mute_Triangle = 80,
	Open_Triangle = 81
	};

std::ostream& operator<<(std::ostream&, enum_percussion);

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_ENUM_PERCUSSION_HPP__ */
