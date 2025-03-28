#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>
#include <atomic>
//
std::mutex accel_m;
std::mutex head_m;
std::mutex oriant_m;
int read_ACCEL()
{
    return 55;
}

int read_Compass()
{
    return 66;
}

void sensor_Fusion()
{
    while(1)
    {
        std::lock_guard<std::mutex> guard(oriant_m);   
        // accel_m.lock();
        auto accel=read_ACCEL();
        // head_m.lock();
        auto comp=read_Compass();
        // accel_m.unlock();
        // head_m.unlock();
    }
}
void promisethread(std::promise<int> promise)
{

}


/// atomic

void get_orintation()
{
    while(1)
    {
        std::lock_guard<std::mutex> guard(oriant_m);
        // head_m.lock();
        auto comp=read_Compass();
        // accel_m.lock();
        auto accel=read_ACCEL();
        // accel_m.unlock();
        // head_m.unlock();
    }
}



int main()
{
/*
std::thread T1(sensor_Fusion);
std::thread T2(get_orintation);

T1.join();
T2.join();
*/






return 0;

}