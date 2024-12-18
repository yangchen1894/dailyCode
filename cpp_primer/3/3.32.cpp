#include <iostream>

int main(int argc, char* argv[])
{
    unsigned scores[11];
    unsigned grade;
    while(std::cin >> grade){
        if(grade <= 100){
            ++scores[grade / 10];
        }
    }
    std::cout << "scores" << scores  << std::endl;
    return 0;
}

