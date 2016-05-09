#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "libmidi/_.hpp"

namespace {

using namespace std;
using namespace libmidi::spec_v_1_1;
// namespace midi = libmidi::spec_v_1_1;

TEST(test_libmidi, enum_message_type)
{
    EXPECT_EQ(to_enum_message_category(enum_message_type::note_off), enum_message_category::channel_voice_message_type);

}

}
