#include <iostream>
#include <string>
#include "overload.h"

int main()
{
    okt::string str("1234");
    okt::string t("load");
    str += str + "5678";
    std::cout<< str + "T"+"T "+t+" TTTTTT";
    std::cout<<"END";
    return 0;
}