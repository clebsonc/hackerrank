#include <iostream>

int fibonnacci(int n){
  int i = 0;
  int j = 1;
  if (n <= 0)
    return i;
  else if (n == 1)
    return j;
  for (int k = 2; k <= n; k++){
    int temp = i;
    i = j;
    j += temp;
  }
  return j;
}


int main(){
  int n;
  std::cin >> n;
  std::cout << fibonnacci(n) << std::endl;

  return 0;
}

