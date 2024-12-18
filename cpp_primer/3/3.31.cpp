#include <iostream>
#include <vector>
#define ARRAY_SIZE 10
#if(0)
int main()
{
    int arr[10] = {};
    for(int i = 0; i < 10; ++i)
    {
        arr[i] = i;
    }
    
    for(int &i : arr)
    {
        std::cout<< " i " << i << std::endl;
    }
    std::cout << "a[5]" << arr[5] << std::endl;

    int arr2[10] = {};
    for(int &i : arr)
    {
        arr2[i] = i;
    }

    for(int &it : arr2)
    {
        std::cout<< " i2 " << it << std::endl;
    }

    return 0;
}
#endif

int main(int argc, char *argv[])
{
    std::vector<int> array;
    array.reserve(ARRAY_SIZE);
    std::cout << array.size() << std::endl;
    for(int i = 0; i < ARRAY_SIZE; ++i)
    {
        array.emplace_back(i);
    }
    for(int &it : array)
    {
        std::cout << "it" << it << std::endl;
    }
    
    std::vector<int> array_copy(array.rbegin(), array.rend());
    
    for(int &it : array_copy)
    {
        std::cout << "2it" << it << std::endl;
    }
    return 0;
}
