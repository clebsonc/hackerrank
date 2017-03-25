#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>


struct comparator{
  bool operator()(const int & a, const int & b){
    return a > b;
  }
};

void balance_queue(std::priority_queue<int, std::vector<int>, comparator> & min_pq,
                   std::priority_queue<int> & max_pq){
  int difference = min_pq.size() - max_pq.size();
  if (difference == -2){  // max_pq is bigger than min_pq
    min_pq.emplace(max_pq.top());
    max_pq.pop();
  }
  else if (difference == 2){  // min_pq is bigger
    max_pq.emplace(min_pq.top());
    min_pq.pop();
  }
}

void insert_value(std::priority_queue<int, std::vector<int>, comparator> & min_pq,
                  std::priority_queue<int> & max_pq, int value){
  if (max_pq.empty() || value > max_pq.top()){
    min_pq.emplace(value);
  } 
  else{
    max_pq.emplace(value);
  }
  balance_queue(min_pq, max_pq);
}

void print_median(std::priority_queue<int, std::vector<int>, comparator> & min_pq,
                  std::priority_queue<int> & max_pq){
  if (min_pq.size() == max_pq.size())
    std::cout << (min_pq.top() + max_pq.top()) / 2.0 << std::endl;
  else if (min_pq.size() > max_pq.size())
    std::cout << float(min_pq.top()) << std::endl;
  else
    std::cout << float(max_pq.top()) << std::endl;
}

void read_values(const int n){
  std::priority_queue<int> max_pq;
  std::priority_queue<int, std::vector<int>, comparator> min_pq;
  int value = 0;
  for (int i = 0; i < n; i++){
    std::cin >> value;
    insert_value(min_pq, max_pq, value);
    print_median(min_pq, max_pq);
  }
}


int main(){
  std::cout << std::fixed << std::setprecision(1);
  int n = 0;
  std::cin >> n;
  read_values(n);

  return 0;
}
