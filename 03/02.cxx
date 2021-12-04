#include "common.hxx"

signed
main() {

    std::vector<std::string> lines{};
    {
        std::fstream input{"input"};

        std::string line;
        while ( input >> line ) {
            lines.push_back(std::move(line));
        }
    }

    std::vector<std::string> filtered{};
    std::copy(lines.begin(), lines.end(), std::back_inserter(filtered));

    for ( size_t i = 0, len = lines[0].length(); i < len; ++i ) {
        size_t ones = 0;
        for ( const auto& line : filtered ) {
            ones += line[i] == '1';
        }
        size_t zeroes = filtered.size() - ones;

        char greatest = ones >= zeroes ? '1' : '0';
        filtered.erase(std::remove_if(filtered.begin(), filtered.end(), [i, greatest](std::string s) {
            return s[i] != greatest;
        }), filtered.end());

        if ( filtered.size() == 1 ) { break; }
    }

    auto oxy = std::stoi(filtered[0], nullptr, 2);
    std::cout << filtered[0] << ": " << oxy << std::endl;

    filtered.clear();
    std::copy(lines.begin(), lines.end(), std::back_inserter(filtered));

    for ( size_t i = 0, len = lines[0].length(); i < len; ++i ) {
        size_t ones = 0;
        for ( const auto& line : filtered ) {
            ones += line[i] == '1';
        }
        size_t zeroes = filtered.size() - ones;

        char least = zeroes <= ones ? '0' : '1';
        filtered.erase(std::remove_if(filtered.begin(), filtered.end(), [i, least](std::string s) {
            return s[i] != least;
        }), filtered.end());

        if ( filtered.size() == 1 ) { break; }
    }

    auto scrub = std::stoi(filtered[0], nullptr, 2);
    std::cout << filtered[0] << ": " << scrub << std::endl;

    std::cout << oxy * scrub << std::endl;

    return 0;
}
