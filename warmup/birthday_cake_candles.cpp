#include <iostream>


int main(){
  int n;
  std::cin >> n;
  
  int max = 0;
  int qtd = 0;
  for (int i = 0; i < n; i++){
    int v;
    std::cin >> v;
    if (v > max){
      max = v;
      qtd = 1;
    }
    else if (v == max){
      qtd++;
    }
  }
  std::cout << qtd << std::endl;

  return 0;
}

