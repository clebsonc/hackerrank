#include <iostream>

int main(){
  int n = 0, k = 0, t=0;
  std::cin >> t; 
  int c = 0;

  for(int i = 0; i < t; i++){
    std::cin >> n >> k;
    int max = 0;
    for(int j = 1; j <= n-1; j++){
      for(int l = j+1; l <= n; l++){
        c = j & l;
        if(c > max && c < k)
          max = c;
      }
    }
    std::cout << max << std::endl;
  }


  return 0;
}
