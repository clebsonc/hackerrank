#include <iostream>
#include <vector>

void swap(std::vector<int> & array, int i, int j){
  int temp = array.at(i);
  array.at(i) = array.at(j);
  array.at(j) = temp;
}

int bubble_sort(std::vector<int> & array){
  int numberOfSwaps = 0;
  for(int i = 0; i < (int) array.size(); i++){
    bool ordered = true;
    // Track number of elements swapped during a single array traversal
    for(int j = 0; j < (int) array.size() - 1; j++) {
      // Swap adjacent elements if they are in decreasing order
      if( array.at(j) > array.at(j+1) ) {
        swap(array, j, j + 1);
        numberOfSwaps++;
        ordered = false;
      }  
    }
    // If no elements were swapped during a traversal, array is sorted
    if(ordered) {
      break;
    }
  }
  return numberOfSwaps;
}

void print(const std::vector<int> & array){
  std::vector<int>::const_iterator it = array.cbegin(); 
  while(it != array.cend()){
    std::cout << *it << " ";
    it++;
  }
}


int main(){
  int n=0;
  std::cin >> n;
  std::vector<int> a(n);
  for(int i = 0; i < n; i++)
    std::cin >> a.at(i);
  int nswaps = bubble_sort(a);
  print(a);
  std::cout << "Array is sorted in " << nswaps << " swaps." << std::endl;
  std::cout << "First Element: " << a.front() << std::endl;
  std::cout << "Last Element: " << a.back() << std::endl;

  return 0;
}
