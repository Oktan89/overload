#include <iostream>
#include <string>
#include "overload.h"

int main()
{
    String string = "str";
    
    std::cout<<string<<std::endl;

    std::cout<< string[2] << std::endl;

    std::string test = "test";

    std::cout << test[10] <<std::endl;
    return 0;
}