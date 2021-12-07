#include "common.hxx"

signed
main() {

    std::vector<std::string> lines{};
    {
        std::fstream input{"input"};

        std::string line;
        while ( std::getline(input, line) ) {
            lines.push_back(std::move(line));
        }
    }

    std::vector<lanternfish> fish{};

    std::string delim = ",";
    size_t cursor = 0;
    auto brk = lines[0].find(delim);
    while ( brk != std::string::npos ) {
        fish.emplace_back(std::stoull(lines[0].substr(cursor, brk - cursor)));
        cursor = brk + delim.length();
        brk = lines[0].find(delim, cursor);
    }

    fish.emplace_back(std::stoull(lines[0].substr(cursor)));

    for ( size_t day = 0; day < 80; ++day ) {
        std::vector<lanternfish> newfish{};

        for ( auto& f : fish ) {
            unsigned char timer = f.age();
            if ( timer == 0 ) {
                lanternfish baby{};
                newfish.push_back(baby);
            }
        }

        fish.insert(fish.end(), newfish.begin(), newfish.end());
    }

    std::cout << fish.size() << std::endl;

    return 0;
}

unsigned char
lanternfish::age () {

    if ( timer == 0 ) {
        timer = 6;
        return 0;
    }

    return timer--;
}
