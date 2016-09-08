#include <iostream>
#include <set>

int main(){
  int n=0, k=0;
  std::set<int> values;

  std::cin >> n >> k;
  int * p = new (std::nothrow) int;
  if(p==nullptr){
    std::cout << "Error allocating memory" << std::endl;
    return 0;
  }
  for(int i = 0; i < n; i++){
    std::cin >> p[i];
  }
  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j<n; j++){
      if( (p[i]+p[j])%k != 0){
        values.insert(p[i]);
        values.insert(p[j]);
      }
    }
  }
  std::cout << values.size() << std::endl;
  
  delete[] p;

  return 0;
}
