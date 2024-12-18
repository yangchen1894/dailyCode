#include <iostream>


void test1()
{

    for(int i = 0; i < 5; ++i)
    {
        do{
            if(i == 0)
            {
                break;
                std::cout << "i1 = "  << i << std::endl;
            }
            
            std::cout << "i2 = "  << i << std::endl;
        }while(0);
            
        std::cout << "i3 = "  << i << std::endl;
    }
}

void test2()
{
    bool testc = false;
    for(int i = 0; i < 5; ++i)
    {
        do{
            if(i == 0)
            {
                break;
                std::cout << "i4 = "  << i << std::endl;
            }
            testc = true;
            std::cout << "i5 = "  << i << std::endl;
        }while(0);
        
        if(testc){
            continue;
        }
        std::cout << "i6 = "  << i << std::endl;
    }
}
int main()
{   
    test1();

        std::cout << "-------------------------------------" << std::endl;
    test2();
    return 0;
}

