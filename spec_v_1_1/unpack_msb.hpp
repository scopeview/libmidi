#ifndef __LIBMIDI_SPEC_V_1_1_UNPACK_MSB_HPP__
#define __LIBMIDI_SPEC_V_1_1_UNPACK_MSB_HPP__

#include <arpa/inet.h>

namespace libmidi { namespace spec_v_1_1 {

template<typename IT, typename T>
void unpack_msb(IT& it, T& t);

template<typename IT>
void unpack_msb(IT& it, uint8_t& data) {
    data = *it++;
}

template<typename IT>
void unpack_msb(IT& it, uint16_t& data) {
    uint16_t msb_data;
    char* ptr = (char*)&msb_data;
    ptr[0] = *it++;
    ptr[1] = *it++;
    data = ntohs(msb_data);
}

template<typename IT>
void unpack_msb(IT& it, uint32_t& data) {
    uint32_t msb_data;
    char* ptr = (char*)&msb_data;
    ptr[0] = *it++;
    ptr[1] = *it++;
    ptr[2] = *it++;
    ptr[3] = *it++;
    data = ntohl(msb_data);
}

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_UNPACK_MSB_HPP__ */
