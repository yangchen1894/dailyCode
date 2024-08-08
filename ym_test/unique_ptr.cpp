#include <iostream>
#include <memory>

// 一个简单的类
class MyClass
{
public:
    MyClass()
    {
        std::cout << "constructed" << std::endl;
    }
    ~MyClass()
    {
        std::cout << "destroy" << std::endl;
    }

    void greet()
    {
        std::cout << "hello" << std::endl;
    }
};
int main()
{
    std::unique_ptr<MyClass> my_unique_ptr1(new MyClass());
    std::unique_ptr<MyClass> my_unique_ptr2 = std::make_unique<MyClass>();

    return 0;
}

