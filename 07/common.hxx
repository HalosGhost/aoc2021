#if !defined(COMMON_HXX)
#define COMMON_HXX

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

template<typename T>
T absdiff (T left, T right) {

    return left >= right ? left - right : right - left;
}

template<typename T>
T reldiff (T left, T right) {
    T diff = absdiff(left, right);
    T tri = 0;
    for ( T i = 1; i <= diff; ++i ) {
        tri += i;
    }

    return tri;
}

#endif
