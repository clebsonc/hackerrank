#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 5

void read_values(std::vector<unsigned int> & array){
  for(int i = 0; i < SIZE; i++){
    std::cin >> array[i];
  }
}

void print_min_max(std::vector<unsigned int> & array){
  std::sort(array.begin(), array.end());
  unsigned int sum = 0;
  for(int x : array)
    sum += x;
  std::cout << sum - array.back() << " " << sum-array.front();
}

int main(){
  std::vector<unsigned int> array(SIZE);
  read_values(array);
  print_min_max(array);

  return 0;
}
