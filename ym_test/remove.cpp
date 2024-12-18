#include <iostream>
#include <vector>
#include <algorithm>
#if(0)
bool IsEven(int& value)
{
    // return value % 2 == 0;
    return (value & 1) == 0;
}

int main(int argc, char* argv[])
{
    std::vector<int> vec = {1, 2 , 3, 4, 5, 6, 7, 8};
    vec.erase(std::remove_if(vec.begin(), vec.end(), IsEven), vec.end());
    return 0;
}
#endif

#if(1)
int main(int argc, char* argv[])
{    
    std::vector<int> vec = {1, 2 , 3, 4, 5, 6, 7, 8};
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int &x)
                             {
                             return (x & 1) == 0;
                             }
                             ),vec.end());
}
#endif
