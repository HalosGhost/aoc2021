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

    std::array<size_t, 9> age_counts{};

    std::string delim = ",";
    size_t cursor = 0;
    auto brk = lines[0].find(delim);
    while ( brk != std::string::npos ) {
        auto age = std::stoull(lines[0].substr(cursor, brk - cursor));
        age_counts[age] += 1;
        cursor = brk + delim.length();
        brk = lines[0].find(delim, cursor);
    }

    age_counts[std::stoull(lines[0].substr(cursor))] += 1;

    for ( size_t day = 0; day < 256; ++day ) {
        size_t temp = age_counts[0];
        for ( size_t i = 0; i < age_counts.size(); ++i ) {
            age_counts[i] = age_counts[i+1];
        }

        age_counts[8] = temp;
        age_counts[6] += temp;
    }

    size_t sum = 0;
    for ( const auto& c : age_counts ) {
        sum += c;
    }

    std::cout << sum << std::endl;

    return 0;
}

