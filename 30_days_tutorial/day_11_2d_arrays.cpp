#include <iostream>
#include <new>
#include <climits>

void print_matrix(int **p){
  if(p == nullptr)
    std::cout << "Empty matrix" << std::endl;
  else{
    std::cout << "Matrix is: " << std::endl;
    for(int i = 0; i < 6; i++){
      for(int j = 0; j < 6; j++){
        std::cout << p[i][j] << " ";
      }
      std::cout << "\n";
    }
  }
}

void clean(int ** & p ){
  for(int i = 0; i < 6; i++){
    delete [] p[i];
  }
  delete [] p;
  p = nullptr;
}

void allocate_matrix(int ** & p){
  try{
    p = new int* [6];
    for(int i = 0; i < 6; i++){
      *(p+i) = new int [6];
    }
  } catch(const std::bad_alloc& ba){
    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
  }
}

void read_values_into_matrix(int ** &p){
  if(p!=nullptr){
    for(int i = 0; i < 6; i++){
      for(int j = 0; j < 6; j++){
        std::cin >> p[i][j];
      }
    }
  }
}


int find_max_hour_glass_sum(const int * const * const & p){
  int max=INT_MIN, curr=0;
  for(int i=0; i<=3; i++){
    for(int j=0; j<=3; j++){
      curr = p[i][j] + p[i][j+1] + p[i][j+2] +
             p[i+1][j+1] +
             p[i+2][j] + p[i+2][j+1] + p[i+2][j+2];
      if(curr > max)
        max = curr;
    }
  }
  return max;
}


int main(){
  int **p = nullptr;
  
  allocate_matrix(p);
  
  read_values_into_matrix(p);

  print_matrix(p);


  std::cout << find_max_hour_glass_sum(p) << std::endl;

  clean(p);
  print_matrix(p);

  return 0;
}
