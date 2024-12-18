#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
#if(0)
    int arr[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    int (&row)[4] = arr[1];
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            std::cout << "a[i][j] " << arr[i][j] << std::endl;
        }
    }

    for(auto &row : arr)
    {
        for(auto &col : row)
        {
            std::cout << col << std::endl;
        }
    }
    std::vector<int> ar = {1, 2, 3, 4, -1, 8};
    auto are = ar.begin();
    while(are != ar.end() && *are >=0)
    {
        std::cout << *++are << std::endl;
    }

    std::cout << *are << std::endl;
    
    std::string test = "jiayoujiyouy y yjiayoujiayouyyy";
    for(auto it = test.begin(); it != test.end() && !std::isspace(*it); ++it)
        *it = std::toupper(*it);
    std::cout << test << std::endl;

    for(const auto &iter : test)
    {
        std::cout << iter << std::endl;
    }
#endif
    std::vector<int> ar = {1, 2, 3, 4, -1, 8};
    auto are = ar.begin();
    auto it = ar.begin();
    while(are != ar.end() && *are >= 0)
    {
        std::cout << *++are << std::endl;
    }

    std::cout <<" -- "<< *are << std::endl;
    

    while(it != ar.end() && *it >= 0)
    {
        std::cout << *it++ << std::endl;
    }
    std::cout << " 0000 " <<*it << std::endl;
    return 0;
}

