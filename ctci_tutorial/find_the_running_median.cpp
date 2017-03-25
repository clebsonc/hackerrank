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

void print_queue(std::priority_queue<int, std::vector<int>, comparator> pq){
  while (!pq.empty()){
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << std::endl;
}

void transfer_elements_queue(std::priority_queue<int> & max_pq, 
    std::priority_queue<int, std::vector<int>, comparator> & min_pq,
    int qt_elements){
  for (int i = 0; i <= qt_elements; i++){
    int value = max_pq.top();
    max_pq.pop();
    min_pq.emplace(value);
  }
}

void print_median(std::priority_queue<int> max_pq){
  std::priority_queue<int, std::vector<int>, comparator> min_pq;
  int mid = max_pq.size()/2;
  bool odd = max_pq.size() % 2 ? true : false;
  float median = 0.0;
  if (odd){
    transfer_elements_queue(max_pq, min_pq, mid);
    median = min_pq.top();
  } 
  else{  // it's an even number
    transfer_elements_queue(max_pq, min_pq, mid-1);
    median = (max_pq.top() + min_pq.top()) / 2.;
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << median << std::endl;
}


void read_values(const int n){
  std::priority_queue<int> max_pq;
  int value;
  for (int i = 0; i < n; i++){
    std::cin >> value;
    max_pq.emplace(value);
    print_median(max_pq);
  }
}


int main(){
  int n = 0;
  std::cin >> n;
  read_values(n);

  return 0;
}
