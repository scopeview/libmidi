#include <cassert>
#include "libmidi/spec_v_1_1/variable_length_quantity.hpp"

namespace libmidi { namespace spec_v_1_1 {

size_t variable_length_quantity::s_max = 0x0FFFFFFF;

variable_length_quantity::variable_length_quantity() : m_value(0)
{}

variable_length_quantity::variable_length_quantity(size_t n) : m_value(n)
{
    assert(n <= s_max);
}

size_t variable_length_quantity::get_actural()
{
    return m_value;
}

std::array<uint8_t, 4> variable_length_quantity::get_as_variable() const
{
    uint8_t a1 = 0;
    uint8_t a2 = 0;
    uint8_t a3 = 0;
    uint8_t a4 = 0;
    int tmp = m_value;
    a1 = tmp % 0x80;
    if (tmp /= 0x80) {
	a2 = tmp % 0x80;
	a2 += 0x80;
	if (tmp /= 0x80) {
	    a3 = tmp % 0x80;
	    a3 += 0x80;
	    if (tmp /= 0x80) {
		a4 = tmp % 0x80;
		a4 += 0x80;
	    }
	}
    }

    return std::array<uint8_t, 4>({a4, a3, a2, a1});
}

void variable_length_quantity::set_value(std::array<uint8_t, 4>& a)
{
    size_t tmp = 0;

    assert((a[0] == 0) || a[0] & 0x80);
    assert((a[1] == 0) || a[1] & 0x80);
    assert((a[2] == 0) || a[2] & 0x80);
    assert(!(a[3] & 0x80));

    if (a[0] & 0x80) {
	tmp = a[0] - 0x80;
	tmp *= 0x80;
    }
    if (a[1] & 0x80) {
	tmp += a[1] - 0x80;
	tmp *= 0x80;
    }
    if (a[2] & 0x80) {
	tmp += a[2] - 0x80;
	tmp *= 0x80;
    }
    tmp += a[3];

    m_value = tmp;
}

}}
