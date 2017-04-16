#include <iostream>
#include <cmath>

bool check_primality(int number){
  if (number == 2)
    return true;
  if (number == 1)
    return false;
  int sqrt_number = std::sqrt(number);
  for (int i = 2; i <= sqrt_number; i++){
    if (number % i == 0)
      return false;
  }
  return true;
}

int main(){
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++){
    int v;
    std::cin >> v;
    if (check_primality(v))
      std::cout << "Prime" << std::endl;
    else
      std::cout << "Not prime" << std::endl;
  }

  return 0;
}

