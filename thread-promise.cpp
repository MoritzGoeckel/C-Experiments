#include<iostream>
#include<thread>

#include<string>

#include <future>

int main(){
  std::promise<std::string> p;

  std::thread t([&p](){
    std::cout << "It works: " << p.get_future().get() << std::endl;
  });

  p.set_value("Yoyo!");
  t.join();
}

//g++ thread.cpp -pthread -o main.exe
