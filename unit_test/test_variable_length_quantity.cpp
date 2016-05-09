#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "libmidi/_.hpp"

namespace {

using namespace std;
namespace midi = libmidi::spec_v_1_1;

TEST(test_libmidi, variable_length_quantity)
{
// actual	variable length quantity
// 0x7F		7F
// 0x80		81 00
// 0x2000	C0 00
// 0x3FFF	FF 7F
// 0x4000	81 80 00
    {
	auto a = midi::variable_length_quantity(0x7F).get_as_variable();
	EXPECT_EQ(0x00, a[0]);
	EXPECT_EQ(0x00, a[1]);
	EXPECT_EQ(0x00, a[2]);
	EXPECT_EQ(0x7F, a[3]);
    }
    {
	auto a = midi::variable_length_quantity(0x80).get_as_variable();
	EXPECT_EQ(0x00, a[0]);
	EXPECT_EQ(0x00, a[1]);
	EXPECT_EQ(0x81, a[2]);
	EXPECT_EQ(0x00, a[3]);
    }
    {
	auto a = midi::variable_length_quantity(0x2000).get_as_variable();
	EXPECT_EQ(0x00, a[0]);
	EXPECT_EQ(0x00, a[1]);
	EXPECT_EQ(0xC0, a[2]);
	EXPECT_EQ(0x00, a[3]);
    }
    {
	auto a = midi::variable_length_quantity(0x3FFF).get_as_variable();
	EXPECT_EQ(0x00, a[0]);
	EXPECT_EQ(0x00, a[1]);
	EXPECT_EQ(0xFF, a[2]);
	EXPECT_EQ(0x7F, a[3]);
    }
    {
	auto a = midi::variable_length_quantity(0x4000).get_as_variable();
	EXPECT_EQ(0x00, a[0]);
	EXPECT_EQ(0x81, a[1]);
	EXPECT_EQ(0x80, a[2]);
	EXPECT_EQ(0x00, a[3]);
    }
}

TEST(test_libmidi, variable_length_quantity_set_value)
{
    {
	auto a = midi::variable_length_quantity(0x4000).get_as_variable();
	midi::variable_length_quantity v(midi::variable_length_quantity(0x4000));
	v.set_value(a);
	auto b = v.get_as_variable();
	EXPECT_EQ(a, b);
    }
}

}
