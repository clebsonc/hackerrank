#include <iostream>
#include <vector>


int possibilities_to_climb_staircases(int n, std::vector<int> & memo){
  if (n < 0)
    return 0;
  if (memo.at(n) == 0){
    int step1 = possibilities_to_climb_staircases(n-1, memo);
    int step2 = possibilities_to_climb_staircases(n-2, memo);
    int step3 = possibilities_to_climb_staircases(n-3, memo);
    memo.at(n) = step1 + step2 + step3;
  }
  return memo.at(n);
}

int staircases(int n){
  std::vector<int> memo(n+1, 0);
  memo.at(0)=1;
  return possibilities_to_climb_staircases(n, memo);
}


int main(){
  int n=0;
  std::cin >> n;
  for (int i = 0; i < n; i++){
    int v = 0;
    std::cin >> v;
    std::cout << staircases(v) << std::endl;
  }

  return 0;
}

