#include <cstdint>
#include <array>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

class IPv4
{
public:

    explicit  IPv4(const std::string& s) : ipv4(parser_ipv4(s))
    {
        
    }

    static std::array<uint8_t, 4> parser_ipv4(const std::string &s)
    {
        std::array<uint8_t, 4> ip{};
        std::istringstream ss(s);
        std::string num;
        for(int i = 0; i < 4 && std::getline(ss, num, '.'); ++i)
        {
            ip[i] = std::stoi(num);
        }
        return ip;
    }

    void print(std::ostream& out = std::cout) const 
    {
        out << ipv4[0] << '.' 
            << ipv4[1] << '.'
            << ipv4[2] << '.'
            << ipv4[3] << std::endl;
    }

private:
    std::array<uint8_t,4> ipv4;

};