#include <iostream>
#include <vector>

void read_values(std::vector<int> & array){
  for(unsigned int i = 0; i < array.size(); i++){
    std::cin >> array.at(i);
  }
}

int find_unique(const std::vector<int> array){
  int x = 0;
  for(int c : array){
    x = x ^ c;
  }
  return x;
}


int main(){
  int qt=0, unique=0;
  std::cin >> qt;
  std::vector<int> array(qt);
  read_values(array); // TODO
  unique = find_unique(array);
  std::cout << unique << std::endl;
  
  return 0;
}
