#if !defined(COMMON_HXX)
#define COMMON_HXX

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

template<typename T, size_t Row = 1000, size_t Col = 1000>
using Matrix = std::array<std::array<T, Col>, Row>;

template<typename T>
using Point = std::tuple<T, T>;

template<typename T>
using Segment = std::tuple<Point<T>, Point<T>>;

template <typename T>
Segment<T>
parse_segment (const std::string& str) {

    T x1, x2, y1, y2;
    size_t cursor = 0;
    std::string coorddelim = ",";
    std::string pointdelim = " -> ";

    auto brk = str.find(coorddelim);
    x1 = std::stoi(str.substr(cursor, brk - cursor));

    cursor = brk + coorddelim.length();
    brk = str.find(pointdelim, cursor);

    y1 = std::stoi(str.substr(cursor, brk - cursor));
    cursor = brk + pointdelim.length();
    brk = str.find(coorddelim, cursor);

    x2 = std::stoi(str.substr(cursor, brk - cursor));
    cursor = brk + coorddelim.length();

    y2 = std::stoi(str.substr(cursor));

    auto fst = std::make_tuple(x1, y1);
    auto snd = std::make_tuple(x2, y2);
    if ( x1 <= x2 && y1 <= y2 ) {
        return std::make_tuple(fst, snd);
    } else {
        return std::make_tuple(snd, fst);
    }
}

#endif
