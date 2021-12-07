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

    std::vector<size_t> positions{};

    std::string delim = ",";
    size_t cursor = 0;
    auto brk = lines[0].find(delim);
    while ( brk != std::string::npos ) {
        positions.emplace_back(std::stoull(lines[0].substr(cursor, brk - cursor)));
        cursor = brk + delim.length();
        brk = lines[0].find(delim, cursor);
    }

    positions.emplace_back(std::stoull(lines[0].substr(cursor)));

    size_t candidate = 0;
    size_t min_fuel = std::numeric_limits<size_t>::max();
    for ( size_t target = 0; target < 2000; ++target ) {
        size_t fuel = 0;
        for ( const auto& p : positions ) {
            fuel += reldiff(p, target);
        }

        if ( fuel < min_fuel ) {
            min_fuel = fuel;
            candidate = target;
        }
    }

    std::cout << candidate << " (" << min_fuel << ')' << std::endl;

    return 0;
}
