#include<iostream>

int main(){
  auto doOutput = [](){
    std::cout << "It works" << std::endl;
  };

  doOutput();
}

//g++ *.cpp -o main.exe
