#ifndef __LIBMIDI_SPEC_V_1_1_PACK_MSB_HPP__
#define __LIBMIDI_SPEC_V_1_1_PACK_MSB_HPP__

#include <arpa/inet.h>

namespace libmidi { namespace spec_v_1_1 {

template<typename IT, typename T>
void pack_msb(IT& it, const T& t);

template<typename IT>
void pack_msb(IT& it, const uint8_t& data) {
    *it++ = data;
}

template<typename IT>
void pack_msb(IT& it, const uint16_t& data) {
    uint16_t msb_data = htons(data);
    const char* ptr = (char*)&msb_data;
    *it++ = ptr[0];
    *it++ = ptr[1];
}

template<typename IT>
void pack_msb(IT& it, const uint32_t& data) {
    uint32_t msb_data = htonl(data);
    const char* ptr = (char*)&msb_data;
    *it++ = ptr[0];
    *it++ = ptr[1];
    *it++ = ptr[2];
    *it++ = ptr[3];
}

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_PACK_MSB_HPP__ */
