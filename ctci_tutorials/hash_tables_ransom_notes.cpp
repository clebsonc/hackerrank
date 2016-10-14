#include <iostream>
#include <map>
#include <string>


void build_magazine(std::map<std::string, int> & magazine, const int m){
  std::string s;
  std::map<std::string, int>::iterator it;
  for(int i = 0; i < m; i++){
    std::cin >> s;
    it = magazine.find(s);
    if(it!=magazine.end()){
      it->second++;
    } else{
      magazine.insert( std::pair<std::string, int>(s, 1) );
    }
  }
}

bool build_ransom_note(std::map<std::string, int> magazine, const int n){
  std::string s;
  std::map<std::string, int>::iterator it;
  for(int i = 0; i < n; i++){
    std::cin >> s;
    it = magazine.find(s);
    if(it != magazine.end()){
      it->second--;
      if(it->second == 0){
        magazine.erase(it);
      }
    } else{
      return false;
    }
  }
  return true;
}


int main(){
  int m=0, n=0;
  std::map<std::string, int> magazine;
  std::string s;

  std::cin >> m >> n;
  build_magazine(magazine, m);
  bool ranson_note = build_ransom_note(magazine, n);
  
  if(ranson_note)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}
