#include <iostream>

int main(){
  int words = 1;
  std::string s;
  std::getline(std::cin, s);

  for(int i = 0; i < s.size(); i++){
    if(s.at(i) >= 'A' and s.at(i) <= 'Z')
      words++;
  }
  
  std::cout << words << "\n";

  return 0;
}
