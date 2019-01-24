
#include <iostream>
#include <string>
#include <functional>
#include <vector>

//#include "../../inc/model/file_handler.h"

void do_nothing(int i){
    std::cout << "in do_nothing\n";
};

int main(int argc, char const *argv[]) {
  // FileHandler* file_handler_ = new FileHandler("test.config");
  // std::cout << "Läuft\n";
  //
  // file_handler_->writeToFile("v_string", "hallo");
  //
  // double d = file_handler_->readFromFile<double>("v_double");
  // std::cout << "double: "<< d << std::endl;
  // std::string s = file_handler_->readFromFile<std::string>("v_string");
  // std::cout << "string: "<< s << std::endl;
  // //bool b = file_handler_->readFromFile<bool>("v_bool");
  //double d_err = file_handler_->readFromFile<double>("v_string");
  //std::cout << "double err: "<< d_err << std::endl;

  auto lam = [](){std::cout<< "in lambda\n";};
  void (*l)() = lam;
  l();

  int i = 0;
  std::function<void(void)> foo = [i](){do_nothing(i);std::cout << "in foo\n";};
  foo();
  auto f_ptr = &foo;
  std::vector<std::function<void(void)>*> v;
  v.push_back(f_ptr);
  (*(v[0]))();


  return 0;
}
