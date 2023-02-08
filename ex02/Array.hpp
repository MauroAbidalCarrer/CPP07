#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <string>
# include <cstring>
# include <exception>

template<typename T> class Array
{
    private:
    T* array;
    size_t _size;

    public:
    //constructors and destructors
    Array()
    {
        array = new T[0];
    }
    Array(unsigned int size)
    {
        if (size < 0)
            throw WrongSizeException();
        _size = size;
        array = new T[size];
        for (size_t i = 0; i < size; i++)
        {
            array[i] = T();
        }
        
    }
    Array(const Array& other)
    {
        *this = other;
    }
    ~Array()
    {
        delete[] array;
    }
    //overloads
    Array& operator=(const Array& rhs)
    {
        array = rhs.getArray();
        return *this;
    }
    //accessors
    T& operator[](std::size_t index)
    {
        if (index < 0 || index >= _size)
            throw OutOfBoundException();
        return array[index];
    }
    T* getArray() const
    {
        T* copy = new T[_size];
        for (std::size_t i = 0; i < _size; i++)
            copy[i] = array[i];
        return copy;
    }
    size_t size() const
    {
        return _size;
    }

    class OutOfBoundException : public std::exception
    {
        const char* what() const throw()
        {
            return "Errror: index out of bounds!";
        }
    };
    class WrongSizeException : public std::exception
    {
        const char* what() const throw()
        {
            return "Error: passed negative size array constructor parameter!";
        }
    };
};
#endif