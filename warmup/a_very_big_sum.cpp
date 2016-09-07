#include <iostream>
#include <vector>


int main(){
  int n;
  long long v = 0;
  std::cin >> n;
  std::vector<long long int> numbers(n);

  for(int i = 0; i < n; i++){
    std::cin >> v;
    numbers.at(i) = v;
  }

  v = 0;
  for(int i = 0; i < n; i++){
    v += numbers.at(i);
  }
  
  std::cout << v << "\n";
  return 0;
}
