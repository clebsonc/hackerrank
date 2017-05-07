#include <iostream>
#include <string>

int main(){
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++){
    std::string a, b;
    std::cin >> a >> b;
    
    int mina = std::stoi(a.substr(0, 2));
    if (mina == 12)
      mina = 0;
    
    int minb = std::stoi(b.substr(0, 2));
    if (minb == 12) 
      minb = 0;
    
    int seca = std::stoi(a.substr(3, 2));
    int secb = std::stoi(b.substr(3, 2));
    
    if (a.at(a.size()-2) == 'A' && b.at(a.size()-2)=='P')
      std::cout << "First" << std::endl;
    else if (a.at(a.size()-2) == 'P' && b.at(a.size()-2)=='A')
      std::cout << "Second" << std::endl;
    else if (a.at(a.size()-2) == 'A' && b.at(a.size()-2)=='A' || 
        a.at(a.size()-2) == 'P' && b.at(a.size()-2)=='P') {
      if (mina < minb)
        std::cout << "First" << std::endl;
      else if(minb < mina)
        std::cout << "Second" << std::endl;
      else if(mina == minb){
        if(seca < secb)
          std::cout << "First" << std::endl;
        else
          std::cout << "Second" << std::endl;
      }
    }
  }
  return 0;
}

