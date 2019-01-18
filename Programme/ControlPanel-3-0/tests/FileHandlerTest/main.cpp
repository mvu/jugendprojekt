
#include <iostream>
#include <string>

#include "../../inc/model/file_handler.h"

int main(int argc, char const *argv[]) {
  FileHandler* file_handler_ = new FileHandler("test.config");
  std::cout << "Läuft\n";

  double d = file_handler_->readFromFile<double>("v_double");
  std::string s = file_handler_->readFromFile<std::string>("v_string");
  //bool b = file_handler_->readFromFile<bool>("v_bool");
  double d_err = file_handler_->readFromFile<double>("v_string");
  std::cout << "string: "<< s << std::endl;
  std::cout << "double: "<< d << std::endl;
  std::cout << "double: "<< d_err << std::endl;

  return 0;
}
