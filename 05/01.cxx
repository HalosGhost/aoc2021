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

        auto is_vert  = x1 == x2;
        auto is_horiz = y1 == y2;

        if ( is_vert ) {
            for ( size_t y = y1; y <= y2; ++y ) {
                ++grid[x1][y];
            }
        } else if ( is_horiz ) {
            for ( size_t x = x1; x <= x2; ++x ) {
                ++grid[x][y1];
            }
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
