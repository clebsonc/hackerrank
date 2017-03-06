#include <iostream>
#include <stack>


class MyStackQueue{
  private:
    std::stack<int> s1; // stack used to insert elements
    std::stack<int> s2;  // stack used to remove and print elements
  public:
    MyStackQueue(){}
    
    MyStackQueue(int n){
      s1.emplace(n);
    }

    void enqueue(const int value){
      s1.emplace(value);
    }

    void dequeue(){
      if(s2.empty()){
        while(!s1.empty()){
          s2.emplace(s1.top());
          s1.pop();
        }
      }
      s2.pop();
    }

    int front(){
      if(s2.empty()){
        while(!s1.empty()){
          s2.emplace(s1.top());
          s1.pop();
        }
      }
      return s2.top();
    }
};


int main(){
  int qn = 0;
  std::cin >> qn;

  MyStackQueue queue;

  int val = 0;
  for (int i = 0; i < qn; i++){
    std::cin >> val;
    if (val == 1){
       std::cin >> val;
       queue.enqueue(val);
    }
    else if(val == 2){
      queue.dequeue();
    }
    else{
      std::cout << queue.front() << std::endl;
    }
  }

  return 0;
}

