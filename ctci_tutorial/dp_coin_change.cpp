#include <iostream>
#include <vector>
#include <algorithm>

unsigned long long int compute_coins(int n, const std::vector<int> & coins,
                  std::vector<std::vector<unsigned long long int>> & memo,
                  int index){
  if (n < 0)
    return 0;
  if (memo.at(n).at(index) == 0){
    for (int i = 0; i < coins.size(); i++){
      unsigned long long int v = compute_coins(n-coins.at(i), coins, memo, i);
      memo.at(n).at(i) = (i==0 ? v : memo.at(n).at(i-1) + v);
    }
  }
  return memo.at(n).at(index);
}


unsigned long long int find_coins(int n, const std::vector<int> & coins){
  std::vector<std::vector<unsigned long long int>> memo(n+1, std::vector<unsigned long long int>(coins.size(), 0));
  for (int i = 0; i < coins.size(); i++){
    memo.at(0).at(i) = 1;
  }
  return compute_coins(n, coins, memo, coins.size()-1);
}


int main(){
  int n=0, qtc = 0;
  std::cin >> n >> qtc;
  std::vector<int> coins;
  std::sort(coins.begin(), coins.end());
  for (int i = 0; i < qtc; i++){
    int v = 0;
    std::cin >> v;
    coins.emplace_back(v);
  }

  std::cout << find_coins(n, coins) << std::endl;

  return 0;
}

