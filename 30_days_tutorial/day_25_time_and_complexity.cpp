#include <iostream>
#include <new>
#include <vector>
#include <cmath>

void print_prime_in_sieve(const std::vector<int> & sieve, int n){
  for(int i = 0; i < n; i++){
    if(sieve.at(i))
      std::cout << i+1 << " ";
  }
}

int  read_numbers(const int & n, int * & t){
  int max = 0;
  try{
    t = new int [n];
    for(int i = 0; i < n; i++){
      std::cin >> *(t+i);
      if(*(t+i) > max)
        max = *(t+i);
    }
  }catch(const std::bad_alloc & ba){
    std::cerr << "Error allocating memory.\n" << ba.what() << std::endl;
  }
  return max; 
}

void compute_sieve(std::vector<int> & sieve, int max){
  sieve.at(0) = 0;
  max = floor(sqrt(max));
  for(int i = 1; i < max; i++){
    if(sieve.at(i) == 1){
      int j = 2, multiple = 2;
      while(true)
      {
        multiple = (i+1) * j;
        if(multiple > static_cast<int>(sieve.size()))
          break;
        sieve.at(multiple - 1) = 0;
        j++;
      }
    }
  }
}

int main(){
  int * t = nullptr;
  int n = 0;
  std::cin >> n;
  int max = read_numbers(n, t);
  if(max){
    std::vector<int> sieve(max, 1);
    compute_sieve(sieve, max);
    for(int i = 0; i < n; i++){
      if(sieve.at(*(t+i)-1) == 1){
        std::cout << "Prime" << std::endl;
        std::cout << "The list of primes until this number are: \n";
        print_prime_in_sieve(sieve, *(t+i));
        std::cout << "\n\n";
      } else{
        std::cout << "Not Prime \n\n";
      }

    }
  }

  if(t != nullptr)
    delete [] t;

  return 0;
}
