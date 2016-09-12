#include <iostream>
#include <climits>

int main(){
  int n=0;
  std::cin >> n;
  std::cin.clear();
  std::cin.ignore(INT_MAX,'\n');
  for(int i = 0; i<n; i++){
    std::string s;
    std::getline(std::cin, s);
    for(int j = 0; j < s.size(); j++){
      if(j%2 == 0)
        std::cout << s.at(j);
    }
    std::cout << "  ";
    for(int j = 0; j < s.size(); j++){
      if(j%2 != 0)
        std::cout << s.at(j);
    }
    std::cout << "\n";
  }
  return 0;
}
