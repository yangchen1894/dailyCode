#include <iostream>
#include <memory>

class MyVector
{
public:
#if(0)
    MyVector()
    {
        m_capacity = 1;
        m_size = 0;
        m_data = new int[m_capacity];
    }
    MyVector(int capacity)
    :m_capacity(capacity)
    {
        m_size = 0;
        m_data = new int[m_capacity];
    }
    ~MyVector()
    {
        if(m_data)
        {
            delete []m_data;
            m_data = nullptr;
        }
    }
#endif
    
#if(1)
    MyVector():m_capacity(0), m_size(0){}
    MyVector(size_t capacity)
        :m_capacity(capacity), m_size(0)
    {
        m_data = std::make_unique<int[]>(m_capacity);
    }
    ~MyVector(){}
#endif
    size_t Size()
    {
        return m_size;
    }

    bool Empty()
    {
        return m_size == 0;
    }

    size_t Capacity()
    {
        return m_capacity;
    }

    void Push(int value)
    {
        if(m_capacity == m_size)
        {
            m_capacity = m_capacity * 2;
            /* int *new_data =new int[m_capacity]; */
            std::unique_ptr<int[]> new_data = std::make_unique<int[]>(m_capacity);
            for(int i = 0; i < m_size; ++i)
            {
                new_data[i] = m_data[i];
            }
            /* delete []m_data; */
            /* m_data = new_data; */
        }
        m_data[m_size++] = value;
    }

    void Pop()
    {
       if(!Empty())
       {
            m_size--;
       }
       else
       {
           return;
       }
    }

    int& operator[](size_t index)
    {
        if(index >= m_size)
        {
            throw std::out_of_range("out of range");
        }
        return m_data[index];
    }

    const int& operator[](size_t index) const
    {
        if(index >= m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

private:
    /* int* m_data; // 数组数据 */
    std::unique_ptr<int[]> m_data;
    size_t m_capacity; // 数组容量
    size_t m_size;  // 数组元素大小

};

int main() {
    MyVector vec(1);
    vec.Push(1);
    vec.Push(2);
    vec.Push(3);

    for(int i = 0; i < vec.Size(); ++i)
    {
        std::cout << vec[i] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
