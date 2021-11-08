#include <iostream>
#include <string>
#include "overload.h"

int main()
{
    okt::string string;
   
    string = "test";
    
    std::cout<<" hi! " + string + " end" <<std::endl;
    return 0;
}