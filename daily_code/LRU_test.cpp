#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache
{
public:
    LRUCache()
    {

    }
    
    LRUCache(size_t capacity)
    : m_capacity(capacity)
    {

    }
    
    int Put(int key, int value)
    {
        // std::undered_map<int, std::list<CacheNode>::iterator> iter = m_cache.find(key);
        auto iter = m_cache.find(key);
        // cache命中，更新value
        if(iter != m_cache.end())
        {
            iter->second->value = value;
            m_nodes.splice(m_nodes.begin(), m_nodes, iter->second); 
        }
        else
        {
            if(m_capacity == m_nodes.size())
            {
                auto del_node = m_nodes.back().key;
                m_cache.erase(del_node);
                m_nodes.pop_back();
            }

            m_nodes.emplace_front(key, value);
            m_cache[key] = m_nodes.begin();
        }

            return 0;
    }

    int Get(int key)
    {
        auto iter = m_cache.find(key);
        if(iter != m_cache.end())
        {
            m_nodes.splice(m_nodes.begin(), m_nodes, iter->second);
            /* return m_nodes.begin()->value; */
            return iter->second->value;
        }
        else
        {
            return -1;
        }

    }

    ~LRUCache()
    {

    }


private:
    struct CacheNode
    {
        CacheNode(int k, int v)
        :key(k), value(v)
        {

        }
        int key;
        int value;
    };

private:
    size_t m_capacity;  // 驻留集大小
    std::list<CacheNode> m_nodes;  // 双向链表
    std::unordered_map<int, std::list<CacheNode>::iterator> m_cache; //哈希表
};

void test()
{
    LRUCache LRU(2);
    LRU.Put(1,100);
    std::cout << "Get(1) = " << LRU.Get(1) << std::endl;

    LRU.Put(3, 300);
    std::cout << "Get(2) = " << LRU.Get(2) << std::endl;

    LRU.Put(4, 400);
    std::cout << "Get(1) = " << LRU.Get(1) << std::endl;

    std::cout << "Get(3) = " << LRU.Get(3) << std::endl;
    std::cout << "Get(4) = " << LRU.Get(4) << std::endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
