#ifndef __LIBMIDI_SPEC_V_1_1_SMPTE_OFFSET_HPP__
#define __LIBMIDI_SPEC_V_1_1_SMPTE_OFFSET_HPP__

#include <cinttypes>

namespace libmidi { namespace spec_v_1_1 {

class smpte_offset {
    uint8_t m_hour;
    uint8_t m_minute;
    uint8_t m_second;
    uint8_t m_frame;
    uint8_t m_ff;			// ?

public:
    smpte_offset();
    smpte_offset(uint8_t hour, uint8_t minute, uint8_t second, uint8_t frame, uint8_t ff);

    template<typename IT>
    void pack(IT& it) const {
	*it++ = m_hour;
	*it++ = m_minute;
	*it++ = m_second;
	*it++ = m_frame;
	*it++ = m_ff;
    }
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_SMPTE_OFFSET_HPP__ */
