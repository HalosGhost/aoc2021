#include "common.hxx"

signed
main() {

    std::fstream input{"input"};

    size_t linecount{};
    std::string line;
    std::array<size_t, 12> ones{};
    while ( input >> line ) {
        ++linecount;
        for ( std::string::size_type n = line.size(); n > 0; --n ) {
            if ( line[n-1] == '1' ) {
                ones[n-1] += 1;
            }
        }
    }

    std::stringstream gm{};
    for ( auto i : ones ) {
        auto b = i > (linecount - i);
        gm << b;
    }

    std::stringstream ep{};
    for ( auto i : ones ) {
        auto b = i < (linecount - i);
        ep << b;
    }

    auto power_consumption = std::stoi(gm.str(), nullptr, 2) * std::stol(ep.str(), nullptr, 2);

    std::cout << power_consumption << std::endl;

    return 0;
}
