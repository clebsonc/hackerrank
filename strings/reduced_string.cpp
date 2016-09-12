#include <iostream>
#include <string>


int main(){
  std::string s;
  int i;
  bool verify = false;
  std::getline(std::cin, s);
  
  do{
    i = 0;
    verify = false;
    std::cout << "bla" << std::endl;
    while(i<(int)s.size()-1){
      if(s.at(i) == s.at(i+1)){
        s.erase(i,2);
        verify = true;
      } else if(s.at(i) != s.at(i+1)){
        i++;
      } 
    }
  }while(s.size() >= 2 && verify == true);
  std::cout << (s.size() == 0? "Empty String" : s) << "\n";
  return 0;
}
