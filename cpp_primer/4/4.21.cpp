#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec_em;
    for(int i = 0; i < 20; ++i)
    {
        vec_em.emplace_back(i);
    }

    for(auto &it : vec_em)
    {
        int tmp = it / 2;

        int result = (it == 0) ? 0 : (tmp == 0) ? it : it*2;
        std::cout << it << result << std::endl;
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

