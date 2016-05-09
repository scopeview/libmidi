#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "libmidi/_.hpp"
#include "libtemplate/_.hpp"
#include "libtraits/_.hpp"

namespace {

using namespace libmidi::spec_v_1_1;

static void test_unpacker_variable_length_quantity(int n)
{
    std::array<char, 10> a = {};
    variable_length_quantity v_expected(n);
	
    auto it = a.begin();
    libtraits::pack(it, v_expected);

    // unpack
    variable_length_quantity v;
    it = a.begin();
    libtraits::unpack(it, v);
    EXPECT_EQ(v_expected.get_actural(), v.get_actural());
}


TEST(test_libmidi, unpacker)
{
    test_unpacker_variable_length_quantity(0x0);
    test_unpacker_variable_length_quantity(0x1);
    test_unpacker_variable_length_quantity(0x7F);
    test_unpacker_variable_length_quantity(0x80);
    test_unpacker_variable_length_quantity(0x2000);
    test_unpacker_variable_length_quantity(0x4000);

    {
	std::vector<char> vec = {0x00};
	variable_length_quantity v;
	auto it = vec.begin();

	libtraits::unpack(it, v);
	EXPECT_EQ(0, v.get_actural());
    }
}

}
