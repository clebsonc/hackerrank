#include <iostream>
#include <vector>


int main(){
  int n, k, counter=0;

  std::cin >> n >> k;
  std::vector<int> values(n);

  for(int i = 0; i<n; i++){
    std::cin >> values.at(i);
  }

  for(int i = 0; i < n; i++){
    for(int j = i; j<n; j++){
      //std::cout << values.at(i) << " " << values.at(j) << " " << (values.at(i)+values.at(j))%k << std::endl;
      if((values.at(i) + values.at(j)) % k == 0 && i!=j)
        counter ++;
    }
  }
  
  std::cout << counter << std::endl;

  return 0;
}
