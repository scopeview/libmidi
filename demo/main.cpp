#include <fstream>
#include "libmidi/_.hpp"
#include "libtraits/traits/setter.hpp"
#include "libtraits/parser.hpp"

using namespace libmidi::spec_v_1_1;

std::vector<char> read_file(const char*filename)
{
    std::ifstream ifs(filename);
    std::vector<char> content;

    char c;
    while (!ifs.eof()) {
	ifs.read(&c, 1);
	content.push_back(c);
    }
    return content;
}

void write_file(const char*filename, const char* ptr, size_t size)
{
    std::ofstream ofs(filename);
    for (int i = 0; i < size; ++i) {
	ofs << ptr[i];
    }
}

void test_generator()
{
    track track_;

    // meta message
    track_.add_event(event<enum_message_type::meta_text_sequence_track_name>::make(delta_time(0), std::string("track_name")));
    track_.add_event(event<enum_message_type::meta_tempo>::make(delta_time(0), tempo(0x068a1b)));
    // voice message
#if 0
    track_.add_note(delta_time(0), channel(0), key::A0, velocity(72), duration(200));
    track_.add_note(delta_time(200), channel(0), key::A1, velocity(72), duration(200));
    track_.add_note(delta_time(400), channel(0), key::A2, velocity(72), duration(200));

#else
    // melody
    add_melody(track_, channel(0), 
	       {std::make_tuple(key::C0, velocity(72), duration(200)),
		       std::make_tuple(key::E0, velocity(72), duration(200)),
		       std::make_tuple(key::G0, velocity(72), duration(200)),
		       std::make_tuple(key::E0, velocity(72), duration(200)),
		       std::make_tuple(key::G0, velocity(72), duration(200)),
		       std::make_tuple(key::C1, velocity(72), duration(200)),
		       std::make_tuple(key::G0, velocity(72), duration(200)),
		       std::make_tuple(key::C1, velocity(72), duration(200)),
		       std::make_tuple(key::E1, velocity(72), duration(200)),
		       });
#endif

    // 
    file file_;
    file_.push_back(track_);
    libtraits::traits::setter<file, head, division>::set(file_, division(division::metrical_time, 0x60));

    auto data = file_.generate();
    
    write_file("/tmp/demo.mid", data.first.get(), data.second);
}

void test_parser()
{
    std::vector<char> v(read_file("/tmp/demo.mid"));
    auto it = v.begin();
    auto file_ = libtraits::parse<file>(it);

    // 
    auto data = file_->generate();
    write_file("/tmp/demo_.mid", data.first.get(), data.second);
}

int main(int argc, char * argv[])
{
    test_generator();
    test_parser();
    return 0;
}
