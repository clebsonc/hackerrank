#include <iostream>
#include <exception>
#include <limits>
#include <cmath>
#include <vector>
#include <algorithm>

int getMinAbsoluteDifference(const std::vector<long int> & vector){
  long int difference = std::numeric_limits<long int>::max();
  for (long unsigned int i = 0; i < vector.size()-1; i++){
    int diff = std::abs(vector.at(i) - vector.at(i+1));
    if (diff < difference)
      difference = diff;
    else if (diff == 0)
      return diff;
  }
  return difference;
}

int main(){
  std::ios::sync_with_stdio(false);
  long int n;
  std::cin >> n;
  std::vector<long int> vector;
  for (long int i = 0; i < n; i++){
    long int v;
    std::cin >> v;
    vector.emplace_back(v);
  }
  std::sort(vector.begin(), vector.end());
  std::cout << getMinAbsoluteDifference(vector) << std::endl;

  return 0;
}

