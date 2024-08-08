#include <iostream>
#include <vector>
#include "ymlocal/comm2/mm3rd/abseil-cpp/absl/strings/str_split.h"

int main()
{
    std::string test_str = "ni,nhao,hshe";
    std::vector<std::string> test_vec;
    test_vec = absl::StrSplit(test_str, ",");
    for(auto & it : test_vec)
    {
        std::cout << it << std::endl;
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

