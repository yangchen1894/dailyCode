#include <iostream>
#include <memory>

class MyClass
:public std::enable_shared_from_this<MyClass()>
{
public:
    MyClass()
    {
        std::cout << "MyClass constructed" << std::endl;
    }
    ~MyClass()
    {
        std::cout << "MyClass destroy" << std::endl;
    }
    void DoSomething()
    {
        std::cout << "do something" << std::endl;
    }
};

int main()
{
    std::shared_ptr <MyClass> shared_1_ptr = std::make_shared<MyClass>();
    {
        // 创建另一个shared_ptr，共享所有权
        std::shared_ptr<MyClass> shared_2_ptr = shared_1_ptr;
        shared_2_ptr->DoSomething();

        // 创建weak_ptr，观察者
        std::weak_ptr<MyClass> weak_1_ptr = shared_1_ptr;

        // 检查weak_ptr是否可以提升为shared_ptr
        if(auto temp = weak_1_ptr.lock())
        {
            temp->DoSomething();
        }else{
            std::cout << "The object is no longe available" << std::endl;
        }
    }// shared_2_ptr离开作用域，但对象不会被销毁，因为share_1_ptr还在

    // 自定义删除器
    std::shared_ptr<MyClass> shared_3_ptr(new MyClass(), [](MyClass* p){
                                          std::cout << "Custom delete for shared_ptr called" << std::endl;
                                          delete p;
                                          });

    // 当shared_1_ptr和shared_3_ptr离开作用域时，它们管理的对象会被自动销毁
    return 0;
}

