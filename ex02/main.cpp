#include "Array.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

# define NB_INTS 10
# define NB_STRINGS 4
# define MAX_VAL 750

void myTests()
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

int schoolTests()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "School test caught an error as expected: " << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "School test caught an error as expected: " << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main()
{
    std::cout << "--------------------my tests--------------------" << std::endl;
    myTests();
    std::cout << "--------------------school tests--------------------" << std::endl;
    return schoolTests();
}