#include <iostream>
#include <string>

int main(){
  int n=0, r=0, temp=0, count=0, count2=0;
  std::string s;

  std::cin >> n;
  std::cin >> s;

  r = n/s.size();
  temp = r*s.size();
  
  for(int i = 0; i < (int) s.size(); i++){
    if(s.at(i) == 'a')
      count++;
    if(temp < n){
      temp++;
      if(s.at(i) == 'a')
        count2++;
    }
  }
  std::cout << count * r + count2 << std::endl;

  return 0;
}
