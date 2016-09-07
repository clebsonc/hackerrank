#include <iostream>
#include <string>

int main(){
  std::string s;
  std::getline(std::cin, s);

  if(s.at(0) == '1' && s.at(1) == '2' && s.at(8) == 'A'){
    s.at(0) = '0';
    s.at(1) = '0';
    s.pop_back();
    s.pop_back();
  } else if( (s.at(0) == '1' && s.at(1) == '2' && s.at(8) == 'P') || 
              s.at(8)=='A'){
    s.pop_back();
    s.pop_back();
  }
  else{
    s.pop_back();
    s.pop_back();
    int a = (s.at(0) - '0') * 10 + (s.at(1) - '0');
    a += 12;
    std::cout << "a: "<<a << std::endl;
    s.at(0) = '0'+a/10;
    s.at(1) = '0'+a%10;
  }

  std::cout << s << std::endl;


  return 0;
}

