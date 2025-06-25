
#include <string>

int main(int argc, char const *argv[])
{
    std::string s = "123.123.123.123";
    IPv4 ip1 (s);
    ip1.print(std::cout);

    return 0;
}