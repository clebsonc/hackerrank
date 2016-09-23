#include <iostream>
#include <exception>
#include <stdexcept>

class Calculator{
  public:
    Calculator(){}

    static int power(int n, int p){
      if(n < 0 || p  < 0){
        throw std::runtime_error("n and p should be non-negative");
      }
      int power = n;
      if(p == 0)
        return 1;
      else{
        for(int i = 0; i<p-1; i++){
          power *= n;
        }
        return power;
      }
    }
};

int main(){
  int n, p;
  std::cin >> n >> p;
  try{
    std::cout << Calculator::power(n, p) << std::endl;
  } catch(const std::exception & e){
    std::cout << e.what() << std::endl;
  }
  
  return 0;
}
