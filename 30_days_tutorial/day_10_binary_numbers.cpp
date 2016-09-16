#include <iostream>


int main(){
  long int n;
  int r=0, c=0, max=0;
  std::cin >> n;
  while(n!=0){
    r = n%2;
    n /= 2;
    c = (r == 1 ? c+1 : 0);
    if(c>max)
      max = c;
  }
  
  std::cout << max << std::endl;
  return 0;
}
