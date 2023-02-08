#include "Array.hpp"
#include <string>
#include <iostream>

# define NB_INTS 10
# define NB_STRINGS 4
int main()
{
    Array<int> intArray = Array<int>(NB_INTS);
    for (size_t i = 0; i < NB_INTS; i++)
        intArray[i] = i * 3;
    for (size_t i = 0; i < NB_INTS; i++)
        std::cout << intArray[i] << std::endl;
    std::cout << std::endl;

    std::cout << "string array:" << std::endl;
    Array<std::string> strArray = Array<std::string>(NB_STRINGS);
    strArray[0] = "salut ca va?\n";
    strArray[1] = "wow c ouf\n";
    strArray[2] = "daccord\n";
    strArray[3] = "derniere string\n";
    for (size_t i = 0; i < NB_STRINGS; i++)
    {
        std::cout << strArray[i];
    }
    std::cout << std::endl;
    
    std::cout << "copied string array:" << std::endl;
    Array<std::string> copiedStrArray = Array<std::string>(strArray);
    for (size_t i = 0; i < NB_STRINGS; i++)
    {
        std::cout << strArray[i];
    }
}