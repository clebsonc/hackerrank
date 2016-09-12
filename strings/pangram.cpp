#include <iostream>
#include <string>
#include <vector>

int main(){
  std::string s;
  std::vector<int> alphabet(26, 0);
  int p = 0;
  std::getline(std::cin, s);
  
  for(int i = 0; i<s.size(); i++){
    if(s.at(i) >= 'A' && s.at(i) <= 'Z')
      p = s.at(i) - 'A';
    else if(s.at(i) >= 'a' && s.at(i) <= 'z')
      p = s.at(i) - 'a';
    else
      continue;
    alphabet.at(p) = 1;
  }
  p = 0;
  for(int i = 0; i < 26; i++){
    p += alphabet.at(i);
  }
  std::cout << (p == 26 ? "pangram" : "not pangram") << std::endl;

  return 0;
}
