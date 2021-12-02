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
    std::array<size_t, 3> samples{depths[0], depths[1], depths[2]};
    size_t measure = std::accumulate(samples.begin(), samples.end(), 0);
    for ( size_t i = 1, len = depths.size(); i <= len - 2; ++i ) {
        size_t nm = std::accumulate(samples.begin(), samples.end(), 0);
        if ( nm > measure ) {
            ++inc;
        } else if ( nm < measure ) {
            ++dec;
        } else {
            ++unc;
        }

        samples[0] = depths[i];
        samples[1] = depths[i+1];
        samples[2] = depths[i+2];
        measure = nm;
    }

    std::cout << dec << ',' << unc << ',' << inc << std::endl;

    return 0;
}
