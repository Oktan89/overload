#pragma once
#include <ostream>

class String
{
    char *_string;
    std::size_t _size;
public:

    String(const char* string) // При конструировани так () или так =
    {
        _size = 0;
        while(string[_size] != '\0')
            ++_size;
        
        _string = new (std::nothrow) char[(_size+1)];

        for(std::size_t i = 0; i < _size; ++i)
        {
            _string[i] = string[i];
        }    
    }
    String(const String& str)
    {
        _size = str._size;
        _string = new (std::nothrow) char[(_size+1)];

        for(std::size_t i = 0; i < _size; ++i)
        {
            _string[i] = str._string[i];
        }    
    }

 
    String& operator=(const String& str)
    {
        if(this == &str)
            return *this;
        delete[] _string;

        _size = str._size;
        _string = new (std::nothrow) char[(_size+1)];

        for(std::size_t i = 0; i < _size; ++i)
        {
            _string[i] = str._string[i];
        }    
        return *this;
    }

    String& operator=(const char* str)
    {
        delete[] _string;
        _size = 0;
        while(str[_size] != '\0')
            ++_size;
        
        _string = new (std::nothrow) char[(_size+1)];

        for(std::size_t i = 0; i < _size; ++i)
        {
            _string[i] = str[i];
        }    
        
        return *this;
    }
    char& operator[](std::size_t index)
    {
        return _string[index];
    }
    const char& operator[](std::size_t index) const
    {
        return _string[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const String& str) 
    {
        out<<str._string;
        return out;
    }

    std::size_t size() const
    {
        return _size;
    }
    void print()
    {   
        std::cout <<_string <<std::endl;
    }

    ~String()
    {
        delete[] _string;
    }

};

