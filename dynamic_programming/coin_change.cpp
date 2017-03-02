#include <iostream>
#include <vector>
#include <algorithm>


long unsigned int computeCoins(int n, const std::vector<int> & coins,
    std::vector<std::vector<long unsigned int>> & memoCoins, int index=0){
  if(n < 0){
    return 0;
  } else if (memoCoins.at(n).at(index) != -1){
    return memoCoins.at(n).at(index);
  } else {                                                                                                                                                                                                                                                                      
    for(int i = 0; i < coins.size(); i++){
      if(i == 0){
        memoCoins.at(n).at(i) = computeCoins(n-coins.at(i), coins, memoCoins, i);
      } else {
        long unsigned int prev = memoCoins.at(n).at(i-1);
        long unsigned int curr = computeCoins(n-coins.at(i), coins, memoCoins, i)+prev;
        memoCoins.at(n).at(i) = curr;
      }
    }
  }
  return memoCoins.at(n).at(index);
}

void print_table(const std::vector<std::vector<long unsigned int>> & table){
  for(int i = 0; i < table.size(); i++){
    for(int j = 0; j < table.at(i).size(); j++){
      std::cout << table.at(i).at(j) << "\t";
    }
    std::cout << "\n";
  }
}


long unsigned int count_coins(int n, const std::vector<int> & coins){
  std::vector<std::vector<long unsigned int>> memoCoins(n + 1,
      std::vector<long unsigned int>(coins.size(), -1));
  for(int i = 0; i < coins.size(); i++){
    memoCoins.at(0).at(i) = 1;
  }
  long unsigned int m = computeCoins(n, coins, memoCoins, coins.size()-1);
  return m;
}


int main(){
  int n, m;
  std::cin >> n >> m;
  std::vector<int> coins;

  for(int i = 0; i < m; i ++){
    int temp;
    std::cin >> temp;
    coins.emplace_back(temp);
  }
  std::sort(coins.begin(), coins.end());
  std::cout << count_coins(n, coins) << std::endl;

  return 0;
}
