#include <iostream>
#include <cstddef>
#include <array>
int main(int argc, char* argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    // size_t array_size = std::size(arr); // c++17
    size_t array_size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < static_cast<int>(array_size); ++i)
    {
        *(ptr + i) = 0;
    }

    for(const int &it : arr)
    {
        std::cout << "it = " << it << std::endl;
    }
    return 0;
}

