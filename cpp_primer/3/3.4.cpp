#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::vector<int> arr2;    
    for(const int &it : arr)
    {
        arr2.emplace_back(it);
    }

    for(const int &iter : arr2)
    {
        std::cout << "iter " << iter << std::endl;
    }
#if(0)
    std::vector<int> arr3(arr2.rbegin(), arr2.rend());
    for(const int &ite : arr3)
    {
        std::cout << "iter " << ite << std::endl;
    }
#endif
    std::vector<int> arr3;
    arr3.resize(arr2.size());
    std::copy(arr2.begin(), arr2.end(), arr3.begin());
    for(const int &ite : arr3)
    {
        std::cout << "iter " << ite << std::endl;
    }
    return 0;
}

