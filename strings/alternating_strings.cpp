#include <iostream>
#include <string>


int main(){
  std::string s;
  int n = 0;
  std::cin >> n;
  for(int k = 0; k < n; k++){
  int count = 0;
  int deletions = 0;
    std::cin >> s;
    for(int i = 0; i < s.size(); i++){
      int j = i+1;
      count = 0;
      while(j<s.size() && s.at(j) == s.at(i)){
        count++;
        j++;
      }
      s.erase(i+1, count);
      deletions += count;
    }
    std::cout << deletions  << std::endl;
  }
  return 0;
}
