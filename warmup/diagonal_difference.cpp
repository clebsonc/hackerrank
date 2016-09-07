#include <iostream>
#include <vector>
#include <cmath>

int main(){
  int n, d1=0, d2=0;
  std::cin >> n;
  int val;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      std::cin >> val;
      if(i == j)
        d1 += val;
      if( j==(n-1-i) )
        d2 += val;
    }
  }
  std::cout << abs(d1 - d2);

  return 0;
}
