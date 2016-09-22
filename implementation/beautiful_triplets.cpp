#include <iostream>

void read_values(int *p, int n){
  for(int i = 0; i < n; i++){
    std::cin >> *(p+i);
  }
}

int find_triplets(int *p, int n, int d){
  int count=0, val=0;
  bool first=true;
  for(int i=0; i<=n-3; i++){
    first=true;
    val=*(p+i);
    for(int j = i+1; j<n; j++){
      if(p[j]-val == d){
        if(first){
          first=false;
          val = p[j];
        } else {
          first = true;
          count++;
          break;
        }
      }
    }
  }
  return count;
}

int main(){
  int n=0, d=0;
  std::cin >>  n >> d;

  int *p = new (std::nothrow) int [n];
  if(p == nullptr){
    std::cout << "Error allocating memory" << std::endl;
    return 1;
  }
  read_values(p, n);

  std::cout << find_triplets(p, n, d) << std::endl;
  
  delete [] p;

  return 0;
}
