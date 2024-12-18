#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {1, 2, 3 ,4, 5};
    std::vector<int> reversed_vec(vec.size());
    // 使用reverse_iterator输出
    
    for(auto rit = vec.rbegin(); rit != vec.rend(); ++rit)
    {
        std::cout << *rit << ", " << std::endl;
    }
    
    std::cout << "test2:" << std::endl;
    std::reverse_copy(vec.begin(), vec.end(), reversed_vec.begin());

    for(const auto &rit : reversed_vec)
    {
        std::cout << rit << ", " << std::endl;
    }
    
    std::cout << "test3:" << std::endl;
    std::for_each(vec.rbegin(), vec.rend(),[](const int& val)
                  {
                       std::cout << val << ", " << std::endl;
                  });

    return 0;
}

