#include <iostream>
#include <random>

void Random(int &random_num, char &random_char){
    std::random_device random_device;
    std::mt19937 generator(random_device());
    //std::string charset = "abcd";
    std::uniform_int_distribution<int> distribution_int(0, 25);
    //std::uniform_int_distribution<int> distribution_char(0, charset.size() - 1);
    random_num = distribution_int(generator);

    random_char = 'a' + random_num;
}


int main()
{
    int random_num;
    char random_char;
    Random(random_num, random_char);
    std::cout << "random_num: " << random_num << std::endl << "random_char: " << random_char <<  std::endl;
    return 0;
}

