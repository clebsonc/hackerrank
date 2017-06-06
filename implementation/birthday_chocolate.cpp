#include <iostream>
#include <vector>

int main(){
  int n=0;
  std::cin >> n;
  std::vector<int> squares(n);
  for (int i = 0; i < n; i++){
    std::cin >> squares.at(i);
  }
  int d=0, m=0;
  std::cin >> d >> m;
  int count = 0;
  for (int i = 0; i <= n-m; i++){
    int sum = 0;
    int idxmax=i + m;
    for (int j = i; j < idxmax; j++){
      sum += squares.at(j);
    }
    if (sum == d){
      count++;
    }
  }
  std::cout << count << std::endl;

  return 0;
}

