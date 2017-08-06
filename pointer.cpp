#include<string>
#include<iostream>

#include<memory>

class Test{
  public:
    int s;
};

int main(){
  //auto x = std::make_unique<Test>();

  auto a = std::make_shared<Test>();
  a->s = 10;

  auto b = std::shared_ptr<Test>(a);

  a->s = 15;

  //Deleting a pointer
  a = nullptr;

  std::cout << "It is " << b->s << " Alive: " << b.use_count() << std::endl;
  //std::make_shared<>
}

//g++ thread.cpp -pthread -o main.exe
