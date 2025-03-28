#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <functional>
#include <sstream>
#include <mutex>
#include <condition_variable>

class ThreadPool
{
public:
ThreadPool(size_t no_threads) : Stop(false)
{
    for(size_t i=0;i<no_threads;i++)
    {
        workers.emplace_back([this]{

            for(;;)
            {
                std::unique_lock<std::mutex> lock(Q_mutex);
                condition.wait(lock, [this]{
                    return Stop || !tasks.empty();});
                if(Stop && tasks.empty())
                {
                    return;
                }
                auto task =std::move(tasks.front()); // extract Task from Task list 
                tasks.pop(); // Remove Task from Queue as it's going to be executed
                lock.unlock(); //unlock mutex for other threads can take Tasks
                task(); // Run Task
            }
        });
    }
}

template<class F>
void enqueue(F&& task)
{
    std::unique_lock<std::mutex> lock(Q_mutex);
    tasks.emplace(std::forward<F>(task));
    lock.unlock();
    condition.notify_one();
}

~ThreadPool()
{
    std::unique_lock<std::mutex> lock(Q_mutex);
    Stop=true;
    lock.unlock();
    condition.notify_all();
    for(std::thread& worker :workers)
    {
        worker.join();
    }
}
private:
std::vector<std::thread> workers;
std::queue<std::function<void()>> tasks;

std::mutex Q_mutex;
std::condition_variable condition;
bool Stop;
};

std::string get_thread_id()
{
    auto my_id =std::this_thread::get_id();
    std::stringstream ss;
    ss <<my_id;
    std::string my_str = ss.str();
    return my_str;
}

int main()
{
    ThreadPool TP(4); // creating a Pool of N Threads
    std::cout<<"ThreadPool is Created\n";
    std::cout<<" Enqueuing Some  Tasks....\n\n";

    for (auto i=0; i<18; i++)
    {
        TP.enqueue([i]{printf("Task %d %s Excuted by Thread\n", i+1,get_thread_id().c_str());
        std::this_thread::sleep_for(std::chrono::seconds(1)); // simulate some work

        
        });
    }
// main thread continous doing other things 
//write the tasks are executed in the background

return 0;

}