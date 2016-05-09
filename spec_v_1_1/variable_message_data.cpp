#include <memory>
#include <cstring>
#include "libmidi/spec_v_1_1/variable_message_data.hpp"

namespace libmidi { namespace spec_v_1_1 {

variable_message_data::variable_message_data()
    : m_size(0)
{}

variable_message_data::variable_message_data(char* ptr, size_t sz)
    : data_type(new char[sz], std::default_delete<char[]>()), m_size(sz)
{
    memcpy(((data_type&)(*this)).get(), ptr, sz);
}

variable_message_data::variable_message_data(std::shared_ptr<char>& ptr, size_t sz)
    : data_type(ptr), m_size(sz)
{}

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
size_t variable_message_data::size() const
{
    return m_size;
}

}}
