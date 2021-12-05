#if !defined(COMMON_HXX)
#define COMMON_HXX

#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_set>

template<typename T, size_t Row = 5, size_t Col = 5>
using Matrix = std::array<std::array<T, Col>, Row>;

static std::vector<Matrix<std::tuple<size_t, bool>>> boards{};
static std::unordered_set<size_t> winners{};

static std::vector<size_t> numbers;

#endif
