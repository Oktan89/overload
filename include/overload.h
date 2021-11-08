#pragma once
#include <ostream>

namespace okt
{
    class string
    {
        char *_string;

        std::size_t _size;

        std::size_t len(const char *string) const
        {
            std::size_t size = 0;
            while (string[size] != '\0')
                ++size;
            //++size;
            return size;
        }
        void copy_str(char *string_this, const char *string_in, std::size_t len)
        {
            for (std::size_t i = 0; i <= len; ++i)
            {
                string_this[i] = string_in[i];
            }
        }

    public:
        string() : _string{new char[0]}, _size{0} {}

        string(const char *string) // При конструировани так () или так =
        {
            _size = len(string);

            _string = new (std::nothrow) char[_size + 1];

            copy_str(_string, string, _size);
        }

        string(const string &str)
        {
            _size = str._size;
        
            _string = new (std::nothrow) char[_size + 1];

            copy_str(_string, str._string, _size);
        }

        string &operator=(const string &str) //Если объект уже создан
        {
            if (this == &str)
                return *this;
            delete[] _string;

            _size = str._size;
            _string = new (std::nothrow) char[_size + 1];

            copy_str(_string, str._string, _size);
            return *this;
        }

        string &operator=(const char *str)
        {
            delete[] _string;
            _size = len(str);

            _string = new (std::nothrow) char[_size + 1];

            copy_str(_string, str, _size);

            return *this;
        }

        char &operator[](std::size_t index)
        {
            return _string[index];
        }

        const char &operator[](std::size_t index) const
        {
            return _string[index];
        }

        string &operator+=(const string &str)
        {
            std::size_t new_size = _size + str._size;
            char *temp_string = new char[new_size];
            std::size_t i = 0;
            for (; i < _size; ++i)
            {
                temp_string[i] = _string[i];
            }
            for (std::size_t j = 0; j < str._size; ++i, ++j)
            {
                temp_string[i] = str._string[j];
            }

            delete[] _string;
            _string = new char[new_size];
            copy_str(_string, temp_string, new_size);
            delete[] temp_string;
            _size = new_size;

            return *this;
        }

        friend std::ostream &operator<<(std::ostream &out, const string &str)
        {
            out << str._string;
            return out;
        }

        std::size_t size() const
        {
            return _size;
        }

        ~string()
        {
            delete[] _string;
        }
    };
    //Если реализовывать в классе, то левый операнд не явно this
    const string operator+(const string &str, const string &str_n)
    {
        string s = str;
        string s_n = str_n;

        return s += s_n;
    }
}