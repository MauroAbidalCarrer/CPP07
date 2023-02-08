#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T> void ft_print(T t)
{
    std::cout << t << std::endl;
}

int main()
{
    int intArray[] = {0, 1, 2, 3};
    iter<int>(intArray, 4, &ft_print<int>);
    std::cout << std::endl;

    std::string strArray[] = {"salut", "ca", "va", "?"};
    iter<std::string>(strArray, 4, &ft_print<std::string>);
}