#if !defined(COMMON_HXX)
#define COMMON_HXX

#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <optional>

enum class direction {
    forward,
    down,
    up
};

struct submarine {
    long horizontal{0}, depth{0}, aim{0};

    void move (direction d, long m);
};

static std::map<std::string, direction> const directions = {
    { "forward", direction::forward },
    { "down", direction::down },
    { "up", direction::up }
};

static std::optional<direction>
from_string (std::string s) {

    auto it = directions.find(s);
    if ( it != directions.end() ) {
        return it->second;
    }

    return std::nullopt;
}


#endif
