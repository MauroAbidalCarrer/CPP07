#ifndef ITER_HPP
# define ITER_HPP
# include <cstring>

template<typename T> void iter(T* array, std::size_t size, void (*func)(T))
{
    for (std::size_t i = 0; i < size && array != NULL; i++)
    {
        (*func)(array[i]);
    }
}

#endif