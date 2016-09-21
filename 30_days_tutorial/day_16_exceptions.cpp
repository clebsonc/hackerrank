#include <iostream>
#include <string>
#include <stdexcept>

int main(){
  int v=0;
  std::string s = "";
  try{
    std::cin >> s;
    v = std::stoi(s);
    std::cout << v << std::endl;
  } catch(const std::invalid_argument & ia){
    std::cout << "Bad String" << std::endl;
  }

  return 0;
}
