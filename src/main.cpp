#include <iostream>
#include <string>
#include "overload.h"

int main()
{
    String string = "str";
    
    std::cout<<string<<std::endl;

    std::cout<< string[2] << std::endl;

    String test = "test";
    string = test;
    std::cout << string <<std::endl;
    return 0;
}