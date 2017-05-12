#include<iostream>
#include<algorithm>

int main(){
  int maxSum = 0;
  
  int scorek = 0;
  int runningSum = 0;

  int n = 0;
  std::cin >> n;
  std::vector<int> vector;
  for (int i = 0; i < n; i++){
    int v=0;
    std::cin >> v;
    vector.push_back(v);
  }
  std::sort(vector.begin(), vector.end());

  for (int i = 0; i < n; i++){
    scorek = runningSum % vector.at(i);
    runningSum = runningSum + vector.at(i);
    maxSum += scorek;
  }

  std::cout << maxSum<< std::endl;

  return 0;
}

