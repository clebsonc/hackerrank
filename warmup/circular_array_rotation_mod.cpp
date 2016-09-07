#include <iostream>
#include <sstream>

void read_values(int * p, int n){
  for(int i = 0; i < n; i++){
    std::cin >> p[i];
  }
}

void read_queries(int *p, int q, int k, int n){
  k = k%n;
  int v, j;
  for(int i = 0; i < q; i++){
    std::cin >> v;
    j = v - k;
    if(j<0){
      std::cout << p[n+j] << std::endl;
    } else{
      std::cout << p[j] << std::endl;
    }
  }
}

int main(){
  int n, k, q;
  std::cin >> n >> k >> q;
  int * values  = new (std::nothrow) int[n];
  if (values != nullptr){
    read_values(values, n);
    read_queries(values, q, k, n);
  }

  return 0;
}
