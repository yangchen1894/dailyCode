#include <iostream>
#include <cstring>

int main()
{
    std::string test = "hellowor\0ld!!!";
    std::string test1;
    test1 = "hellowor\0ld!!!";
    const char* puf = static_cast<const char*>(test.c_str());
    size_t iLen = strlen(puf);
    std::cout << "iLen = " << iLen << ", test size =  " << test.size() << ", test1 size =" << test1.size() << std::endl;
    return 0;
}

