#include <iostream>
#include <algorithm>

int main(){
  int n;
  std::cin >> n;
  std::vector<int> values(n);
  for(int i = 0; i < n; i++){
    std::cin >> values.at(i);
  }
  std::sort(values.rbegin(), values.rend());
  while(!values.empty()){
    std::vector<int>::reverse_iterator it = values.rbegin();
    std::cout << values.size() << std::endl;
    int min = *it;
    while(it != values.rend()){
      *it = *it - min;
      if(*it == 0){
        it++;
       values.pop_back();
      } else{
        it++;
      }
    }
  }

  return 0;
}

