#ifndef __LIBMIDI_SPEC_V_1_1_VARIABLE_MESSAGE_DATA_HPP__
#define __LIBMIDI_SPEC_V_1_1_VARIABLE_MESSAGE_DATA_HPP__

#include <memory>

namespace libmidi { namespace spec_v_1_1 {

class variable_message_data : public std::shared_ptr<char>
{
    // static uint8_t s_each_max = 0x7F;
    typedef std::shared_ptr<char> data_type;

    size_t m_size;

public:
    variable_message_data();
    variable_message_data(char*, size_t);
    variable_message_data(std::shared_ptr<char>&, size_t);
    
    size_t size() const;
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_VARIABLE_MESSAGE_DATA_HPP__ */
