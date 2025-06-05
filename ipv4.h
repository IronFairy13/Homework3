#include <array>
#include <string>
#include <cstdint>
#include <array>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#pragma once

class IPv4
{
public:
    explicit  IPv4(const std::string& s);

    static std::array<uint8_t, 4> parser_ipv4(const std::string &s);

    void print(std::ostream& out = std::cout);

private:
    std::array<uint8_t,4> ipv4;
};
