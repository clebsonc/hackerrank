#include <iostream>


void read_values(int * const p, const int n){
  for(int i = 0; i < n; i++){
    std::cin >> *(p+i);
  }
}

int compute_energy(const int * const p, const int n, const int k){
  int position = 0, energyPoints = 100;
  
  do{
    position = (position+k)%n;
    energyPoints = energyPoints - (p[position] == 1 ? 3 : 1);
  } while(position!=0);
  
  return energyPoints;
}

int main(){
  int n, k;
  std::cin >> n >> k;
  int *p = new (std::nothrow) int[n];
  if(p == nullptr){
    std::cout << "Error while allocating memory" << std::endl;
    return 1;
  }

  read_values(p, n);
  int finalEnergy = compute_energy(p, n, k);
  std::cout << finalEnergy;

  delete [] p;
  return 0;
}
