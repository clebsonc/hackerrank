#include <iostream>
#include <string>
#include <set>

int main(){
  int n=0, counter=0;
  std::string s = "";
  std::set<char> letters;
  std::cin >> n;

  for(int i=0; i<n; i++){
    std::cin >> s;
    for(int j=0; j<(int) s.size(); j++){
      if(!letters.count(s.at(j))){
        counter++;
        letters.insert(s.at(j));
      }
    }
    std::cout << counter << std::endl;
    letters.clear();
    counter=0;
  }


  return 0;
}
