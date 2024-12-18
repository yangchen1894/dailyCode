#include <iostream>
#include <algorithm>
#include <memory>

template <typename T>
class MyVector
{
public:
#if(0)
    MyVector()
        :m_data(nullptr), m_size(0), m_capacity(0)
    {}

    MyVector(size_t capacity)
        :m_capacity(capacity), m_size(0)
    {
        m_data = new T[m_capacity];
    }

    ~MyVector()
    {
        if(m_data)
        {
            delete [] m_data;
            m_data = nullptr;
        }
    }
#endif

#if(1)
    MyVector()
    :m_capacity(0), m_size(0){}

    MyVector(size_t capacity)
    :m_capacity(capacity), m_size(0)
    {
        m_data = std::make_unique<T[]>(m_capacity);
        /* m_data = std::shared_ptr<T[]>(new T[m_capacity]); */
    }

    ~MyVector(){}
#endif
    size_t Size() const
    {
        return m_size;
    }

    size_t Capacity() const
    {
        return m_capacity;
    }

    bool Empty()
    {
        return m_size == 0;
    }

    void PushBack(const T& value)
    {
        if(m_size == m_capacity)
        {
            m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
            /* T* new_data = new T[m_capacity]; */
            std::unique_ptr<T[]> new_data =std::make_unique<T[]>(m_capacity);
            // make_shared不支持创建数组类型的shared_ptr;
            /* std::shared_ptr<T[]> new_data(new T[m_capacity]); */
            for(int i = 0; i < m_size; ++i)
            {
                /* new_data[i] = m_data[i]; */
                new_data[i] = std::move(m_data[i]); // 智能指针需要使用std::move
            }
            
            /* delete []m_data; */
            /* m_data = new_data; */
            m_data = std::move(new_data);
        }

        //m_data[++m_size] = value; // 会段错误
        m_data[m_size++] = value;
    }

    void Pop()
    {
        if(!Empty())
        {
            --m_size;
            return;
        }
        else
        {
            return;
        }
    }

    T& operator[](size_t index)
    {
        if(index >= m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        else
        {
            return m_data[index];
        }
    }
    
    const T& operator[](size_t index) const
    {
        if(index >= m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        else
        {
            return m_data[index];
        }
    }
    
    //迭代器
    class Iterator
    {
    public:
        Iterator(T* p)
            :ptr(p)
        {}
        Iterator& operator++()
        {
            ++ptr;
            return *this;
        }

        bool operator != (const Iterator& other) const
        {
            return ptr != other.ptr;
        }

        T& operator*()
        {
            return *ptr;
        };
    
    private:
        T* ptr;
    };

        Iterator begin()
        {
            return Iterator(m_data.get());
        }

        Iterator end()
        {
            return Iterator(m_data.get() + m_size);
        }

private:
    /* T* m_data; */
    std::unique_ptr<T[]> m_data;
    size_t m_size;
    size_t m_capacity;
};


int main()
{
    /* MyVector<int> vec; */
    /* vec.PushBack(1); */
    /* vec.PushBack(2); */
    /* vec.PushBack(3); */
    
    MyVector<std::string> vec;
    std::string str1 = "nihao";
    std::string str2 = "nihaobu";
    vec.PushBack(str1);
    vec.PushBack(str2);
    for (const auto& value : vec) {
        std::cout << value << std::endl;
    }
    
    return 0;
}

