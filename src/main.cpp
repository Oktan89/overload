#include <iostream>
#include <string>
#include "overload.h"

int main()
{
    okt::string str("1234");
    
    str += str + "5678";
    std::cout<< str + "T"+"T"+"TTTTTT";
    std::cout<<"END";
    return 0;
}