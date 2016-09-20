#include <iostream>
#include <string>

int main(){
  std::string s;
  std::cin >> s;
  int count = 0;

  for(int i=0; i <= s.size()-3; i+=3){
    if(s.at(i) != 'S')
      count++;
    if(s.at(i+1) != 'O')
      count++;
    if(s.at(i+2) != 'S')
      count++;
  }
  std::cout << count << std::endl;

  return 0;
}
