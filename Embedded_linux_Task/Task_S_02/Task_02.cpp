/*
Author: Ahmed Abdelaziz
 Subject: Task3
 Objectives: 3 threads 
 (Using Lambda Expr. , struct object, paramterized Function, different sleep time)
 */

#include <iostream>
#include <thread>
#include <chrono>


struct Temperature_Sensor
{
    public:
    void operator()()
    {
        while(1)   
        {
        Addition();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        }
    }
    void Set_Temp(float *data)
    {
        temp =*data;
    }
    float Get_Temp()
    {
        float *data = &temp; 
       return *data;
    }
    void Addition()
    {
        while(1)
       {
        auto Reading =Get_Temp();
        Reading+=0.5;
        Set_Temp(&Reading);
        std::cout<<"Addition: "<<Get_Temp()<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }  
    }
    private:
    float temp=0.0;
};
void Temperature_Modifier(float tempo)
{
    Temperature_Sensor TS;
    TS.Set_Temp(&tempo);
    while(1)
    {
        auto Reading =TS.Get_Temp();
        Reading+=0.5;
        TS.Set_Temp(&Reading); 
        std::cout<<"Modified Readings: "<<TS.Get_Temp()<<std::endl;;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


int main()
{
  
float temp =25;
Temperature_Sensor TS;
std::thread Readings_Thread(TS);
std::thread Temperature_Displayer_Thread(Temperature_Modifier,temp);
std::thread Seconds_Counter_Thread([](){
    int s=0;
    while(1)
    {
    s++;
    std::cout<<"Seconds Passed: "<<s<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
});
Readings_Thread.join();
Temperature_Displayer_Thread.join();
Seconds_Counter_Thread.join();
//
        /*
        float tempo =25.0;
        Temperature_Sensor TS;
        TS.Set_Temp(&tempo);
        std::cout<<TS.Get_Temp()<<std::endl;
        TS.Readings();
        */


return 0;
}