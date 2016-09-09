#include <iostream>

int main(){
  int n = 0, jumps = 0;
  int *p;
  std::cin >> n;
  p = new (std::nothrow) int[n];
  if(p == nullptr){
    std::cout << "Error allocating memory." << std::endl;
    return 1;
  }
  for(int i = 0; i < n; i++){
    std::cin >> p[i];
  }
  int j = 0;
  while(j!=n-1){
    if(j+2 < n && p[j+2] != 1)
      j+=2;
    else
      j+=1;
    jumps++;
  }
  std::cout << jumps << std::endl;
  delete[] p;

  return 0;
}
