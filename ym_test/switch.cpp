#include <iostream>

void test_switch(int iCase){
    switch(iCase){
    case 1:
        std::cout << "this is case 1" << std::endl;
        break;
    case 2:
        std::cout << "this is case 2" << std::endl;
        break;
    case 3:
        std::cout << "this is case 3" << std::endl;
        return;
    case 4:
        std::cout << "this is case 4" << std::endl;
        break;
    default:
        std::cout << "this is case default" << std::endl;
        break;

    } 
        
} 

int main(int argc, char *argv[])
{
    int iCase = std::stoll(argv[1]);
    test_switch(iCase);
    return 0;
}

