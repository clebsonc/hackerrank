#include <iostream>
#include <string>
#include <cmath>

int main(){
  int n = 0;
  std::string s;
  std::cin >> n;
  bool funny = false;

  for(int i = 0; i<n; i++){
    std::string s;
    std::cin >> s;
    funny = true;
    for(int j = 1, k=(int) s.size()-2; j<(int) s.size(), k>=0; j++, k--){
      if(abs(s.at(j) - s.at(j-1)) != abs(s.at(k) - s.at(k+1))){
        funny = false;
        break;
      }
    }
    std::cout << (funny? "Funny" : "Not Funny") << std::endl;
  }

  return 0;
}
