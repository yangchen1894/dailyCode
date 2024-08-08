#include <iostream>
#include <memory>

class MyClass
:public std::enable_shared_from_this<MyClass>
{
public:
    void CreateWeakPtr()
    {
        std::weak_ptr<MyClass> weak_1_ptr = shared_from_this();
        std::cout << "weak_ptr create" << std::endl;
    }

    void DisPlay()
    {
        std::cout << "MyClass instance" << std::endl;
    }

};

void TestFunction(std::weak_ptr<MyClass> weak_2_ptr)
{
    std::shared_ptr<MyClass> shared_1_ptr = weak_2_ptr.lock();
    if(shared_1_ptr)
    {
        shared_1_ptr->DisPlay();
    }
    else
    {
        std::cout << "object has been destroy" << std::endl;
    }
}

int main()
{
    std::shared_ptr<MyClass> shared_2_ptr = std::make_shared<MyClass>();
    shared_2_ptr->CreateWeakPtr();

    std::weak_ptr<MyClass> weak_1_ptr = shared_2_ptr;

    TestFunction(weak_1_ptr);

    shared_2_ptr.reset();

    TestFunction(weak_1_ptr);

    return 0;
}
