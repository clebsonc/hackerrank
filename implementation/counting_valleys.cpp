#include <iostream>
#include <stack>
#include <string>
#include <limits>

int count_valleys(){
  std::stack<char> up;
  std::stack<char> down;
  int valleys = 0;

  std::string s = "";
  std::cin >> s;

  for (auto c : s){
    if (c == 'U'){
      if (down.empty()){  // climbing hill
        up.emplace('U');
      }
      else {
        down.pop();
      }
    }
    else{
      if(!up.empty()){
        up.pop();
      }
      else{
        if (down.empty())
          valleys++;
        down.emplace('D');
      }
    }
  }
  return valleys;
}

int main(){
  int n;
  std::cin >> n;
  std::cout << count_valleys() << std::endl;

  return 0;
}

