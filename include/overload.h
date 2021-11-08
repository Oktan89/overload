#pragma once
#include <ostream>

class String
{
    char *_string;
    std::size_t _size;
    std::size_t len(const char* string) const
    {
        std::size_t size = 0;
        while(string[size] != '\0')
            ++size;
        ++size;
        return size;
    }
    void copy_str(char* string_this, const char* string_in, std::size_t len)
    {
        for(std::size_t i = 0; i < len; ++i)
        {
            string_this[i] = string_in[i];
        }    
    }
public:

    String(const char* string) // При конструировани так () или так =
    {
        _size = len(string);
       
        _string = new (std::nothrow) char[(_size)];

        copy_str(_string, string, _size);
    }
    String(const String& str)
    {
        _size = str._size;
        _string = new (std::nothrow) char[_size];

        copy_str(_string, str._string, _size);  
    }

 
    String& operator=(const String& str)
    {
        if(this == &str)
            return *this;
        delete[] _string;

        _size = str._size;
        _string = new (std::nothrow) char[_size];

        copy_str(_string, str._string, _size);    
        return *this;
    }

    String& operator=(const char* str)
    {
        delete[] _string;
        _size = len(str);
      
        _string = new (std::nothrow) char[_size];

        copy_str(_string, str, _size);    
        
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
        return _size-1;
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

