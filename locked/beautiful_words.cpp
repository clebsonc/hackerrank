#include <iostream>
#include <string>

int main(){
  std::string s;
  std::cin >> s;
  bool is_beautiful = true;
  for (int i = 0; i < s.size()-1; i++){
    if (s.at(i) == s.at(i+1) || 
        ((s.at(i) == 'a' || s.at(i) == 'e' || s.at(i) == 'i' ||
        s.at(i) == 'o' || s.at(i) == 'u' || s.at(i) == 'y') &&
        (s.at(i+1) == 'a' || s.at(i+1) == 'e' || s.at(i+1) == 'i' ||
        s.at(i+1) == 'o' || s.at(i+1) == 'u' || s.at(i+1) == 'y'))){
      is_beautiful = false;
      break;
    }
  }

  std::cout << (is_beautiful ? "Yes" : "No") << std::endl;

  return 0;
}

