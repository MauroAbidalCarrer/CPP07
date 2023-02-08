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
        std::cout << strArray[i];
    std::cout << std::endl;

    std::cout << "modifying copy array element at index 2:" << std::endl;
    copiedStrArray[2] = "modified string\n";
    for (size_t i = 0; i < NB_STRINGS; i++)
    {
        std::cout << "original: " << strArray[i];
        std::cout << "copy: " << copiedStrArray[i];
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "assigned string array to copied Array:" << std::endl;
    Array<std::string> assignedStrArray = Array<std::string>(NB_STRINGS);
    assignedStrArray = copiedStrArray;
    for (size_t i = 0; i < NB_STRINGS; i++)
    {
        std::cout << strArray[i];
    }
    std::cout << std::endl;

    std::cout << "modifying assigned array element at index 3:" << std::endl;
    assignedStrArray[3] = "another modified string\n";
    for (size_t i = 0; i < NB_STRINGS; i++)
    {
        std::cout << "copied: " << copiedStrArray[i];
        std::cout << "assigned: " << assignedStrArray[i];
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "trying to access array element outside of bounds" << std::endl;
    try
    {
        std::cout << strArray[NB_STRINGS];
    }
    catch(const std::exception& e)
    {
        std::cout << "caught an error as expected: " << e.what() << '\n';
    }
    try
    {
        std::cout << strArray[-1];
    }
    catch(const std::exception& e)
    {
        std::cout << "caught an error as expected: " << e.what() << '\n';
    }
}