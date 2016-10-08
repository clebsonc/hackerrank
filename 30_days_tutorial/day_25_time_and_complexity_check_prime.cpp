#include <iostream>
#include <cmath>

void check_prime(const int n){
  int max = floor(sqrt(n));
  bool prime = true;
  if(n!=2)
    for(int i = 2; i < max; i++){
      if(n%i == 0)
        prime = false;
    }
  if(n==1)
    prime = false;
  if(prime)
    std::cout << "Prime" << std::endl;
  else
    std::cout << "Not prime" << std::endl;
}


int main(){
  int t = 0, n =0;
  std::cin >> t;
  for(int i = 0; i < t; i++){
    std::cin >> n;
    check_prime(n);
  }

  return 0;
}
