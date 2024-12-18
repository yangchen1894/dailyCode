#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

#define BUFFER_SIZE 10

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;

#if(0)
void producer(int id)
{
    for(int i = 0; i < BUFFER_SIZE; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 生产时间
        {
            std::lock_guard<std::mutex> lock(mtx);
            while(buffer.size() >= BUFFER_SIZE)
            {
                std::this_thread::yield();
            }
        }

        buffer.push(i);
        std::cout << "Producter " << id << "producer" << i << std::endl;
    }
}

void consumer(int id)
{
    for(int i = 0; i < buffer.size(); ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        {
            std::lock_guard<std::mutex> lock(mtx);
            while(buffer.empty())
            {
                std::this_thread::yield();
            }
        }
        int item = buffer.front();
        buffer.pop();
    }
}

#endif

bool QueueNotFull()
{
    return buffer.size() != BUFFER_SIZE;
}

bool QueueNotEmpty()
{
    return !buffer.empty();
}

void producer(int i)
{
    for(int i = 0; i < BUFFER_SIZE; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, QueueNotFull);
        buffer.push(i);
        lock.unlock();
        cv.notify_all();
    }
}

void consumer(int i)
{
    for(int i = 0; i < BUFFER_SIZE; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, QueueNotEmpty);
        buffer.pop();
        lock.unlock();
        cv.notify_all();
    }
}


int main()
{
    std::thread producer[2];
    std::thread consumer[2];

    for(int i = 0; i < 2; ++i)
    {
        producer[i] = std::thread(producer, i + 1);
    }

    for(int i = 0; i < 2; ++i)
    {
        consumer[i] = std::thread(consumer, i + 1);
    }

    for(int i = 0; i < 2; ++i)
    {
        producer[i].join();
        consumer[i].join();
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}
