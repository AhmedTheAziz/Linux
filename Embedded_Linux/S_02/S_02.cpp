/*
Author: Ahmed Abdelaziz
Session: Embedded Linux S_02
Subject: Concurrency & Threads
*/

 #include <iostream>
 #include<thread>
 #include <chrono>
 #include <fstream>
 #include <ostream>
//1- Threading (test01.exe)
void Function()
{
    while(1)
    {
        std::cout<<"Hello Multi-Threading..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
void Fun2()
{
    while(1)
    {
        std::cout<<"Fun2()..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
//2-input/output Thread (test02.exe)
void OutputFilethread()
{
    while(1)
    {
        std::ofstream file("/home/buddha73/Documents/Robotics-Corner/Embedded_Linux/S_02/filename.txt");
        file<< "Write Data \n";
      // std::ofstream::file.close;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
void InputFileThread()
{
    while(1)
    {
        std::string buffer; 
        std::ifstream f("/home/buddha73/Documents/Robotics-Corner/Embedded_Linux/S_02/filename.txt");
        f>>buffer;
        std::cout<<"filename.txt consest of: "<<buffer<<std::endl;        
        unsigned int n =std::thread::hardware_concurrency();
        std::cout<<"number of threads supported by hardware:"<<n<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
//3- paramaterized function (test03.exe)
void InPutFun(std::string *data)
{
    /*
        data = nullptr;
        while(1)
        {
            if(data == nullptr)
            {
            while(1)
            {
            std::cout<<"Enter data: "<<std::endl;
                std::cin>> *data;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
            }
        }
    */
       
    while(1)
    {
    std::cout<<"Enter data: "<<std::endl;
    std::cin>> *data;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
void OutPutFun(const std::string *data)
{
     /*   
            while(1)
            {
                if(data !=nullptr)
                {
                while(1)
                {
                    std::cout<< *data<<std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
                }
            }
    */
        
    while(1)
    {
                std::cout<< *data<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
//4-TemperatureSensor Displayer(test04.exe) 
  //Global Variable (Dummy Technique)
  float temperature =0.0;
void TemperatureSensor()
{   
        temperature =25.0;
    while(1)
    {
        temperature +=0.5;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
void Display()
{
    while(1)
    {
    std::cout<<"Tempreature is : "<<temperature<<" Degrees"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}
//5- Threading Using Function Objects (test05.exe)
struct Accelerometer
{
void operator()()
{
    while(1)
    {
      std::cout<<" Accelerometer Task"<<std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
};
//6- Lambda Experssion  (test06.exe)
int main()
{
//1- Threading (test01.exe)
    /*
    std::thread t1(Function);
    std::thread t2(Fun2);
    t1.join();
    t2.join();
    */
//2-input/output Thread (test02.exe)
    /*
    std::thread thread1(OutputFilethread);
    std::thread thread2(InputFileThread);
    thread1.join();
    thread2.join();
    */
//3- paramaterized function (test03.exe)
    /*
        std::string data; 
        std::thread thread1(InPutFun,&data);
        std::thread thread2(OutPutFun,&data);

        thread1.join();
        thread2.join();
    */
//4-TemperatureSensor Displayer(test04.exe)
    /* 
       std::thread Sensor_Thread(TemperatureSensor);
       std::thread Disply_Thread(Display);

       Sensor_Thread.join();
       Disply_Thread.join();
    */   
//5- Threading Using Function Objects (test05.exe)
    /*
       std::thread Sensor_Thread(TemperatureSensor);
       std::thread Disply_Thread(Display);
       Accelerometer Accel;
       std::thread Accel_Thread(Accel);

       Sensor_Thread.join();
       Disply_Thread.join();
       Accel_Thread.join();
    */   
//6- Lambda Experssion  (test06.exe)
    /*
       std::thread Sensor_Thread(TemperatureSensor);
       std::thread Disply_Thread(Display);
       std::thread Accel_Thread([](){
            while(1)
       {
        std::cout<<" Accelerometer Task"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

       });

       Sensor_Thread.join();
       Disply_Thread.join();
       Accel_Thread.join();
    */ 






return 0;
}