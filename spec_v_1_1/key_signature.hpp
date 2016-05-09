#ifndef __LIBMIDI_SPEC_V_1_1_KEY_SIGNATURE_HPP__
#define __LIBMIDI_SPEC_V_1_1_KEY_SIGNATURE_HPP__

namespace libmidi { namespace spec_v_1_1 {

class key_signature {
public:
    // TODO
    // spec just list the example, not the actrually value list?
    enum class sf{
	flats7 = -7,
	flat1 = -1,
	key_of_C = 0,
	sharp1 = 1,
	sharps7 = 7
	    };
    enum class mi {
	major = 0,
	minor = 1,
    };

private:
    sf m_sf;
    mi m_mi;

public:
    key_signature();
    key_signature(sf, mi);

    sf get_sf() const;
    mi get_mi() const;
};

}}
#endif	/* __LIBMIDI_SPEC_V_1_1_KEY_SIGNATURE_HPP__ */
