//wait & notify (test01.exe)
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <condition_variable>
//ASYNC [Future&Promise](test02.exe)
#include <future>
// ASYNC Ex2 (test03.exe)
#include <exception>
#include <math.h>

//wait & notify (Conditional_Variable)
typedef int data_t;
std::mutex my_m;
std::queue<data_t> my_q;
std::condition_variable data_cond; //conditional variable

void consume_data(data_t data)
{
    std::cout<<data<<std::endl;
}

data_t produce_data()
{
    static data_t var=0;
    var++;
    return var;
}

void producer()
{
    while(true)
    {
        const data_t data =produce_data();
        std::lock_guard<std::mutex> prod_lock(my_m); // guard the push 
        my_q.push(data);
        data_cond.notify_one(); // notify the waiting thread to evaluate cond
    }
}

void consumer()
{
    std::unique_lock<std::mutex> cons_lock(my_m); //unique lock used in wait condation 
    data_cond.wait(cons_lock, //return if lambda return true
        []{return !my_q.empty();}); //else unlock and wait || .empty() returns 1 if empyu, 0 if not empty
        data_t data = my_q.front(); // lock is hold here to protect popping.......
        my_q.pop();
        cons_lock.unlock(); //......untill here 
        consume_data(data);
}
//ASYNC [Future&Promise](test02.exe)
// ASYNC Ex2 (test03.exe)
double Sqr_root(double x)
{
    if (x<0)
    {
        throw std::out_of_range("x<0");
    }
    else return sqrt(x);
}
//future_exceptions (test04.exe)
void async_fun(std::promise<int> my_promise)
{
    int result;
    try
    {
        //calculate the result
        my_promise.set_value(result);
    }
    catch(...)
    {
        my_promise.set_exception(std::current_exception());
    }

}
int main()
{
    //wait & notify (test01.exe)
    /*
    std::thread cons_thread(consumer);
    std::thread prod_thread(producer);
    cons_thread.join();
    prod_thread.join();
    */
    //ASYNC [Future&Promise](test02.exe)
    /*
    std::future<int> future = std::async(std::launch::async, [](){
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return 8;
    });
    std::cout << "waiting....\n";
    std::future_status stats;
    do
    {
        stats =future.wait_for(std::chrono::seconds(1));
        if(stats ==std::future_status::deferred) // delegated or skipped for another thing
        {
            std::cout<< "deferred\n"; 
        }
        else if(stats ==std::future_status::timeout) // suppossed to return data but data is not returned 
        {
            std::cout<< "timeout\n"; 
        } 
        else if(stats ==std::future_status::ready) // ready to return data
        {
            std::cout<< "ready\n"; 
        }
    } 
    while (stats !=std::future_status::ready); // wait until status is ready 
    std::cout << "result is " << future.get()<< std::endl;
    */
    // ASYNC Ex2 (test03.exe)
    /*
    std::future<double> fut = std::async(Sqr_root, -1);
    //do something else
    double res= fut.get(); // f becomes ready on exception and rethrows 
    // exception object could be a copy of original
    */
    //future_exceptions (test04.exe)
    /*std::promise<int> intpromise;
    std::future<int> intfuture = intpromise.get_future();
    std::thread t(async_fun, std::move(intpromise));
    //do other stuff here while async_fun is working
    int result = intfuture.get(); // may throw my exception
    */
    //
    
    return 0;
}