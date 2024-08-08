#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <string>
#include <unistd.h>

//日志上报
class ReportClass
:public std::enable_shared_from_this<ReportClass>
{
public:
    static std::shared_ptr<ReportClass> GetInstance();
    static void ReleaseInstance();
    void pushEvent(const std::string& event);

    ReportClass()
    :count_(0)
    {

    }

    ~ReportClass()
    {

    }

private:
    void AddWorkThread();
    static void WorkThread(std::weak_ptr<ReportClass> weak_report_ptr);
    static std::shared_ptr<ReportClass> instance_;
    static std::mutex static_mutex_;
    
    std::mutex mutex_;
    int count_;
};

std::mutex ReportClass::static_mutex_;
std::shared_ptr<ReportClass> ReportClass::instance_;

std::shared_ptr<ReportClass> ReportClass::GetInstance()
{
    std::lock_guard<std::mutex> lock(static_mutex_);
    if(!instance_)
    {
        instance_ = std::shared_ptr<ReportClass>(new ReportClass());
        instance_->AddWorkThread();
    }
    return instance_;
}

void ReportClass::ReleaseInstance()
{
    std::lock_guard<std::mutex> lock(static_mutex_);
    instance_.reset();
}

void ReportClass::WorkThread(std::weak_ptr<ReportClass> weak_report_ptr)
{
    while(true)
    {
        std::shared_ptr<ReportClass> shared_report_ptr = weak_report_ptr.lock();
        if(!shared_report_ptr)
        {
            return;
        }

        std::unique_lock<std::mutex> lock(shared_report_ptr->mutex_);

        if(shared_report_ptr->count_ > 0)
        {
            shared_report_ptr->count_--;
            std::cout << "Processing log event, remaining count: " << shared_report_ptr->count_ << std::endl;
        }
        lock.unlock();
        usleep(1000*1000);
    }
}

void ReportClass::AddWorkThread()
{
    std::weak_ptr<ReportClass> weak_report_ptr = shared_from_this();
    std::thread work_thread(WorkThread, weak_report_ptr);
    work_thread.detach();
}

void ReportClass::pushEvent(const std::string& event)
{
    std::unique_lock<std::mutex> lock(mutex_);
    ++count_;
    std::cout<< "Event pushed, new count: "<< count_ << "Event: "<< event<< std::endl;
}

int main()
{
    auto report = ReportClass::GetInstance();
    report->pushEvent("Event 1");
    report->pushEvent("Event 2");

    sleep(3);

    ReportClass::ReleaseInstance();
    return 0;
}

