//This is a playground for the following topics:
//  Const, Pointer, Reference,
//  Call by value, Call by Reference, (Null allowed / forbidden)

#include<iostream>

int main()
{
  int i = 12;

  int* pi = &i;
  int* pi2 = pi;

  *pi = 15;

  std::cout << "pi2 = " << *pi2 << std::endl;
  std::cout << pi << " == " << pi2 << " == " << &i << std::endl;

  int& refi = i;

  *pi2 = 20;

  std::cout << refi << std::endl;

  //Not null and const
  auto notNullConst = [](const int& param){
    std::cout << "Function: " << param << std::endl;
    //param = 10; -> Error!
  };

  //Not null by reference
  auto notNullRef = [](int& param){
    std::cout << "Function: " << param << std::endl;
    param = 10;
  };

  //Null possible const
  auto nullConst = [](const int* param){
    if(param != nullptr){
      std::cout << "Function: " << *param << std::endl;
      //*param = 10; -> Error!
    }
  };

  //Null possible pointer
  auto nullByRef = [](int* param){
    if(param != nullptr){
      std::cout << "Function: " << *param << std::endl;
      *param = 10;
    }
  };

  notNullRef(i);
  std::cout << "pi2 = " << *pi2 << std::endl;

  nullByRef(nullptr);

  return 0;
}
