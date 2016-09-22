#include <iostream>
#include <new>

void print_array(const int * const p, const int n){
  for(int i = 0; i < n; i++){
    std::cout <<  *(p+i) << " ";
  }
  std::cout << "\n";
}

void insertion_sort(int *p, int n){
  int j = 0, temp = 0;
  for(int i = 1; i < n; i++){
    j = i;
    temp = p[i];
    while(j>0 && p[j-1] > temp){
      p[j] = p[j-1];
      j--;
    }
    p[j] = temp;
    //std::cout << "(i,j) = (" <<  i << ", " << j << ")" << std::endl;
    print_array(p, n);
  }
}

void read_values_into_array(int *p, int n){
  for(int i=0; i<n; i++){
    std::cin >> *(p+i);
  }
}

int main(){
  int n;
  std::cin >> n;
  int * p = new (std::nothrow) int[n];
  if(p==nullptr){
    std::cout << "Error allocating memory" << std::endl;
    return 1;
  }
  read_values_into_array(p, n);

  insertion_sort(p, n);

  //print_array(p, n);

  delete[] p;

  return 0;
}
