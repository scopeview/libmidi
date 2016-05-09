#include "libmidi/spec_v_1_1/key_signature.hpp"

namespace libmidi { namespace spec_v_1_1 {

key_signature::key_signature() : m_sf(sf::key_of_C), m_mi(mi::major) {}

key_signature::key_signature(sf sf_, mi mi_) : m_sf(sf_), m_mi(mi_) {}

////////////////////////////////////////////////////////////////
key_signature::sf key_signature::get_sf() const
{
    return m_sf;
}

key_signature::mi key_signature::get_mi() const
{
    return m_mi;
}

}}
