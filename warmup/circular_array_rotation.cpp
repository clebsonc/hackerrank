#include <iostream>
#include <sstream>
#include <vector>

void read_values(int * p, int n){
  for(int i = 0; i < n; i++){
    std::cin >> p[i];
  }
}

void perform_rotation(int * const p, const int k, const int n){
  for(int i = 0; i < k; i++){
    int last = p[n-1];
    for(int j = n-1; j>0; j--){
      p[j] = p[j-1];
    }
    p[0] = last;
  }
}

void read_queries(int *p, int q){
  std::vector<int> queries(q);
  int v;
  for(int i = 0; i < q; i++){
    std::cin >> v;
    queries.at(i) = v;
  }
  for(int i = 0; i < q; i++){
    std::cout << p[queries.at(i)] << std::endl;
  }
}

int main(){
  int n, k, q;
  std::cin >> n >> k >> q;
  int * values  = new (std::nothrow) int[n];
  if (values != nullptr){
    read_values(values, n);
    perform_rotation(values, k, n);
    read_queries(values, q);
  }

  return 0;
}
