#include<iostream>
#include<vector>
#include<string>

#include <functional>

#include<typeinfo>

auto generateOutputFunc(std::string s) {
  return [s](){
    std::cout << "Output is " << s << std::endl;
  };
}

int main(){
  std::vector<std::function<void()>> v = {generateOutputFunc("tes"), generateOutputFunc("tes2"), generateOutputFunc("tes3")};
  v[1]();
}

//g++ *.cpp -o main.exe
