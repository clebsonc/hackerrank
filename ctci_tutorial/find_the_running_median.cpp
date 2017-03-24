#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct comparator{
  bool operator()(const int & a, const int & b){
    return a > b;
  }
};

void print_queue(std::priority_queue<int, std::vector<int>, comparator> pq){
  while (!pq.empty()){
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << std::endl;
}

void read_values(std::priority_queue<int, std::vector<int>, comparator> & pq, const int n){
  int value;
  for (int i = 0; i < n; i++){
    std::cin >> value;
    pq.emplace(value);
    print_queue(pq);
  }
}


int main(){
  int n = 0;
  std::cin >> n;
  std::priority_queue<int, std::vector<int>, comparator> pq;
  read_values(pq, n);

  return 0;
}
