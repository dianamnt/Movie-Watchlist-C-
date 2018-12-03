#pragma once
#include <string>
#include <vector>

// Trims spaces from a string
std::string trim(const std::string& s);

// Tokensizes a string
std::vector<std::string> tokenize(const std::string& str, char delimiter);