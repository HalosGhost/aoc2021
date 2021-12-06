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

    std::vector<Segment<size_t>> segments{};
    for ( const auto& line : lines ) {
        segments.emplace_back(parse_segment<size_t>(line));
    }

    Matrix<size_t> grid{};
    for ( const auto& [ fst, snd ] : segments ) {
        const auto& [ x1, y1 ] = fst;
        const auto& [ x2, y2 ] = snd;

        if ( x1 == x2 ) {
            auto lesser = std::min(y1, y2);
            auto greater = std::max(y1, y2);
            for ( size_t y = lesser; y <= greater; ++y ) {
                ++grid[x1][y];
            }
        } else if ( y1 == y2 ) {
            auto lesser = std::min(x1, x2);
            auto greater = std::max(x1, x2);
            for ( size_t x = lesser; x <= greater; ++x ) {
                ++grid[x][y1];
            }
        } else {
            auto ysign = y1 < y2 ? +1 : -1;
            auto xsign = x1 < x2 ? +1 : -1;

            for ( size_t x = x1, y = y1; x != x2 && y != y2; x += xsign, y += ysign ) {
                ++grid[x][y];
            }

            ++grid[x2][y2];
        }
    }

    size_t overlapped = 0;
    for ( const auto& row : grid ) {
        for ( const auto& cell : row ) {
            if ( cell > 1 ) {
                ++overlapped;
            }
        }
    }

    std::cout << overlapped << std::endl;

    return 0;
}
