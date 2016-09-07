#include <vector>
#include <iostream>

int sum(std::vector<int> arr){
  std::vector<int>::iterator it = arr.begin();
  int s = 0;
  while(it != arr.end()){
    s += *it;
    it++;
  }
  return s;
}

int main(){
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for(int arr_i = 0; arr_i < n; arr_i++){
     std::cin >> arr[arr_i];
  }
  std::cout << sum(arr);
  
  return 0;
}

