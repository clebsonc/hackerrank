#include <iostream>
#include <vector>


void swap(std::vector<int> & values, int i, int j){
  int temp = values.at(i);
  values.at(i) = values.at(j);
  values.at(j) = temp;
}

void bubble_sort(std::vector<int> & values){
  bool is_sorted = false;
  int counter = 0;
  while (!is_sorted){
    is_sorted = true;
    for (int i = 0; i < values.size()-1; i++){
      if (values.at(i) >= values.at(i+1)){
        is_sorted = false;
        counter++;
        swap(values, i, i+1);
      }
    }
  }
  std::cout << "Array is sorted in " << counter << " swaps." << std::endl;
  std::cout << "First Element: " << values.front() << std::endl;
  std::cout << "Last Element: " << values.back() << std::endl;
}

int main(){
  std::vector<int> values({5, 3, 4, 2, 1});
  bubble_sort(values);
  
  return 0;
}

