#include <iostream>
#include <string>

int main()
{
    std::string str = " ";
    std::cout << "size" << str.size() <<","<<  str.empty()<< std::endl;
    std::string str1 = "";
    std::cout << "size" << str1.size() <<","<<  str1.empty()<< std::endl;
    return 0;
}

