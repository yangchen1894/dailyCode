#include <iostream>

class MyStack
{
public:
    MyStack(int capacity)
    :data_(new int[capacity]), top_(-1), capacity_(capacity){}
    ~MyStack()
    {
        if(data_)
        {
            delete data_;
            data_ = nullptr;
        }
    }

    bool empty() const
    {
        if(top_ == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool full() const
    {
        if(top_ == capacity_ - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int value)
    {
        if(!full())
        {
            data_[++top_] = value;
        }
        else
        {
            std::cout << "full" << std::endl;
        }
    }

    void pop()
    {
        if(!empty())
        {
            --top_;
        }
        else
        {
            std::cout << "full" << std::endl;
        }
    }

    int top()
    {
        if(!empty())
        {
            return data_[top_];
        }
        else
        {
            std::cout << "empty" << std::endl;
            return -1;
        }
    }
private:
    int* data_;
    int top_;
    int capacity_;
};

void test()
{
    MyStack stack1(10);
    std::cout << "is this stack empty? "<< stack1.empty() << std::endl;
    for(int i = 0; i < 9; ++i){
        stack1.push(i);
        std::cout << "栈中元素为-->" << stack1.top() << std::endl;
    }
    std::cout << "is this stack full? "<< stack1.full() << std::endl;
    for(int i = 0; i < 9; ++i){
        stack1.pop();
        std::cout << "栈中元素为-->" << stack1.top() << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    test();
    return 0;
}
