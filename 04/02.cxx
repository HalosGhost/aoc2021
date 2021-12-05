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

    const size_t boardwidth = 5;
    std::string delim = ",";

    size_t cursor = 0;
    auto brk = lines[0].find(delim);
    while ( brk != std::string::npos ) {
        numbers.push_back(std::stoi(lines[0].substr(cursor, brk - cursor)));
        cursor = brk + delim.length();
        brk = lines[0].find(delim, cursor);
    }

    for ( size_t cursor = 2; cursor < lines.size(); ++cursor ) {
        Matrix<std::tuple<size_t, bool>> b{};
        for ( size_t i = 0; i < boardwidth; ++i ) {
            std::istringstream l(lines[cursor]);
            for ( size_t j = 0; j < boardwidth; ++j ) {
                size_t num;
                l >> num;
                b[i][j] = std::make_tuple(num, false);
            }
            ++cursor;
        }
        boards.push_back(b);
    }
    size_t boardcount = boards.size();

    size_t winning_number = 0;
    size_t winning_board = 0;
    for ( const auto& n : numbers ) {
        // mark the number on each board
        for ( size_t b = 0; b < boardcount; ++b ) {
            if ( winners.find(b) != winners.end() ) {
                continue;
            }

            for ( size_t i = 0; i < boardwidth; ++i ) {
                for ( size_t j = 0; j < boardwidth; ++j ) {
                    const auto num = get<0>(boards[b][i][j]);
                    if ( n == num ) {
                        get<1>(boards[b][i][j]) = true;
                        goto nextboard;
                    }
                }
            }

            nextboard:;
        }

        // check for a winning board
        for ( size_t b = 0; b < boardcount; ++b ) {
            if ( winners.find(b) != winners.end() ) {
                continue;
            }

            for ( size_t i = 0; i < boardwidth; ++i ) {
                size_t marked_count = 0;
                for ( size_t j = 0; j < boardwidth; ++j ) {
                    if ( get<1>(boards[b][i][j]) ) {
                        ++marked_count;
                    }
                }

                if ( marked_count == boardwidth ) {
                    winners.insert(b);
                    if ( winners.size() == boardcount ) {
                        winning_number = n;
                        winning_board = b;
                        goto score;
                    }
                    goto nextcheck;
                }
            }

            for ( size_t i = 0; i < boardwidth; ++i ) {
                size_t marked_count = 0;
                for ( size_t j = 0; j < boardwidth; ++j ) {
                    if ( get<1>(boards[b][j][i]) ) {
                        ++marked_count;
                    }
                }

                if ( marked_count == boardwidth ) {
                    winners.insert(b);
                    if ( winners.size() == boardcount ) {
                        winning_number = n;
                        winning_board = b;
                        goto score;
                    }
                    goto nextcheck;
                }
            }

            nextcheck:;
        }
    }

    score:

    size_t unmarked = 0;
    for ( size_t i = 0; i < boardwidth; ++i ) {
        for ( size_t j = 0; j < boardwidth; ++j ) {
            const auto [ num, marked ] = boards[winning_board][i][j];
            if ( !marked ) {
                unmarked += num;
            }
        }
    }

    size_t total = unmarked * winning_number;

    std::cout << total << std::endl;

    return 0;
}
