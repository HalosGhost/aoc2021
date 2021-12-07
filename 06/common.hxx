#if !defined(COMMON_HXX)
#define COMMON_HXX

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>

struct lanternfish {
    unsigned char timer = 8;

    unsigned char age();
};

#endif
