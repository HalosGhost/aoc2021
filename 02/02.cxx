#include "common.hxx"

void
submarine::move (direction d, long m) {

    switch ( d ) {
        case direction::forward:
            this->horizontal += m;
            this->depth += this->aim * m;
            break;

        case direction::down:
            this->aim += m;
            break;

        case direction::up:
            this->aim -= m;
            break;
    }
}

signed
main() {

    std::fstream input{"input"};

    submarine sub{};

    std::string dir;
    long magnitude;

    while ( input >> dir >> magnitude ) {
        auto d = from_string(dir);
        if ( !d ) {
            std::cerr << "Failed to parse a direction from '" << dir << "'" << std::endl;
            return 1;
        }
        sub.move(d.value(), magnitude);
    }

    std::cout << sub.horizontal * sub.depth << std::endl;

    return 0;
}
