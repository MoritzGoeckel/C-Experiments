#include <thread>
#include <future>
#include <iostream>

int main(){
    auto future = std::async(std::launch::async, [](){
        std::cout << "Output!" << std::endl;
        return 0;
    });

    int x = future.get(); //Block until done
    //x == 0
}
