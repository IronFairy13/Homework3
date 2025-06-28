
#include <iostream>
#include <map>
#include "my_allocator.hpp"
#include "my_container.hpp"

int factorial(int n)
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main()
{
    std::map<int, int> def_map;
    for (int i = 0; i < 10; ++i)
        def_map[i] = factorial(i);

    for (const auto &[key, value] : def_map)
        std::cout << key << ' ' << value << '\n';

    std::map<int, int, std::less<>, MyAllocator<std::pair<const int, int>>> my_map;

    for (int i = 0; i < 10; ++i)
        my_map[i] = factorial(i);

    for (const auto& [key, value] : my_map)
        std::cout << key << ' ' << '\n';

    MyContainer<int> my_cont;
    for (int i = 0; i < 10; i++)
        my_cont.push_back(i);
    
    my_cont.print();

    MyContainer<int, MyAllocator<int>> cont2;
    for (int i = 0; i < 10; ++i)
        cont2.push_back(i);
    cont2.print(); 

    return 0;
}