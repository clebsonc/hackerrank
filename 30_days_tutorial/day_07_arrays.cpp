#include <iostream>

int main(){
  int n;
  std::cin >> n;
  int * p = new (std::nothrow) int [n];
  if(p==nullptr){
    std::cout << "error allocating memory";
    return 0;
  }
  for(int i = 0; i<n; i++){
    std::cin >> *(p+i);
  }
  
  int temp = 0;
  for(int i = 0, j=n-1; i<=j; i++, j--){
    temp = *(p+i);
    *(p+i) = *(p+j);
    *(p+j) = temp;
  }
  for(int i = 0; i < n; i++){
    std::cout << *(p+i) << " ";
  }

  delete [] p;
  return 0;
}
