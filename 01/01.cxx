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

    std::vector<size_t> depths{lines.size()};
    for ( const auto& line : lines ) {
        depths.emplace_back(std::stoi(line));
    }

    size_t unc = 1, inc = 0, dec = 0;
    for ( size_t i = 1, len = depths.size(); i < len; ++i ) {
        if ( depths[i] > depths[i - 1] ) {
            ++inc;
        } else if ( depths[i] < depths[i - 1] ) {
            ++dec;
        } else {
            ++unc;
        }
    }

    std::cout << dec << ',' << unc << ',' << inc << std::endl;

    return 0;
}
