#ifndef __LIBMIDI_SPEC_V_1_1_ENUM_MESSAGE_TYPE_HPP__
#define __LIBMIDI_SPEC_V_1_1_ENUM_MESSAGE_TYPE_HPP__

#include <utility>
#include <iostream>

namespace libmidi { namespace spec_v_1_1 {

enum class enum_message_type : uint16_t {
    meta_sequence_number = 0xFF00,
	meta_text = 0xFF01,
	meta_text_copyright_notice = 0xFF02,
	meta_text_sequence_track_name = 0xFF03,
	meta_text_instrument_name = 0xFF04,
	meta_text_lyric = 0xFF05,
	meta_text_marker = 0xFF06,
	meta_text_cue_point = 0xFF07,
	meta_midi_channel_prefix = 0xFF20,
	meta_end_of_track = 0xFF2F,
	meta_tempo = 0xFF51,
	meta_smpte_offset = 0xFF54,
	meta_time_signature = 0xFF58,
	meta_key_signature = 0xFF59,
	meta_sequencer_specific_meta_event = 0xFF7F,

	note_off = 0x80,
	note_on = 0x90,
	polyphonic_key_pressure = 0xA0,
	control_change = 0xB0,
	program_change = 0xC0,
	channel_pressure = 0xD0,
	pitch_wheel_change = 0xE0,
	system_exclusive = 0xF0,
	undefined_B11110001 = 0xF1,
	song_position_pointer = 0xF2,
	song_select = 0xF3,
	undefined_B11110100 = 0xF4,
	undefined_B11110101 = 0xF5,
	tune_request = 0xF6,
	end_of_exclusive = 0xF7,
	timing_clock = 0xF8,
	undefined_B11111001 = 0xF9,
	start = 0xFA,
	continue_ = 0xFB,
	stop = 0xFC,
	undefined_B11111101 = 0xFD,
	active_sensing = 0xFE,
	reset = 0xFF
	};

std::ostream& operator<<(std::ostream&, enum_message_type);

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_ENUM_MESSAGE_TYPE_HPP__ */
