#include <iostream>
#include <new>

void read_data(int * const & array, int n){
  for(int i=0; i<n; i++){
    std::cin >> *(array+i);
  }
}

void print_updated_array(const int * const & array, const int & n, const int & d){
  int start = d%n;
  std::cout << *(array+start) << " ";
  int i = start+1;
  while(i != start){
    if(i == n)
      i = 0;
    else{
      std::cout << *(array+i) << " " ;
      i++;
    }
  }
  std::cout << std::endl;
}

int main(){
  int n=0, d=0;
  int * array = nullptr;
  std::cin >> n >> d;
  try{
    array = new int[n];
    read_data(array, n);
    print_updated_array(array, n, d);
    delete [] array;
  }catch(const std::bad_alloc & ba){
    std::cout << "Error allocating memory:\n" <<  ba.what();
  }
  
  return 0;
}

