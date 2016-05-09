#ifndef __LIBMIDI_SPEC_V_1_1_VARIABLE_LENGTH_QUANTITY_HPP__
#define __LIBMIDI_SPEC_V_1_1_VARIABLE_LENGTH_QUANTITY_HPP__

#include <array>

namespace libmidi { namespace spec_v_1_1 {

// actual	variable length quantity
// 0x7F		7F
// 0x80		81 00
// 0x2000	C0 00
// 0x3FFF	FF 7F
// 0x4000	81 80 00
// 
// 
// 0x80 / (0x7F + 1) = 1
// 0x80 % (0x7F + 1) = 0
// byte[0] = 0x80 + 1 = 0x81
// byte[1] = 0
// 
// 
// 0x2000 / (0x7F + 1) = 40
// 0x2000 % 0x7F = 0
// byte[0] = 0x80 + 0x40 = 0xC0
// byte[1] = 0
//
// 
// 0x3FFF / (0x7F + 1) = 7F
// 0x3FFF % (0x7F + 1) = 7F
// byte[0] = 0x80 + 0x7F = 0xFF
// byte[1] = 7F
//
// 
// 0x4000 / (0x7F + 1) = 80
// 0x80 / (0x7f + 1) = 1
// 0x80 % (0x7f + 1) = 0
// 0x4000 % (0x7f + 1) = 0
// byte[0] = 0x80 + 1 = 0x81
// byte[1] = 0x80 + 0 = 0x80
// byte[2] = 0
class variable_length_quantity {
    static size_t s_max;

    size_t m_value;

public:
    variable_length_quantity();
    variable_length_quantity(size_t);

    size_t get_actural();
    std::array<uint8_t, 4> get_as_variable() const;
    void set_value(std::array<uint8_t, 4>&);
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_VARIABLE_LENGTH_QUANTITY_HPP__ */
