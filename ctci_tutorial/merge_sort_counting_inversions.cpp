#include <iostream>
#include <vector>

void copy_val(std::vector<int> & nval, std::vector<int> & oval, int i, int j){
  for (i; i <= j; i++){
    nval.emplace_back(oval.at(i));
  }
}

unsigned long long combine(std::vector<int> & values, int lindex, int middle, int rindex){
  std::vector<int> left_values;
  std::vector<int> right_values;
  
  copy_val(left_values, values, lindex, middle); //TODO: implement function
  copy_val(right_values, values, middle+1, rindex);
  
  int idx_left = 0, idx_right = 0, idx_or = lindex;
  unsigned long long inversions = 0;
  while (idx_left < left_values.size() && idx_right < right_values.size()){
    if (left_values.at(idx_left) <= right_values.at(idx_right)){
      values.at(idx_or) = left_values.at(idx_left);
      idx_left++;
      idx_or++;
    } else {
      inversions += left_values.size() - idx_left;
      values.at(idx_or) = right_values.at(idx_right);
      idx_right++;
      idx_or++;
    }
  }
  while (idx_left < left_values.size()){
    values.at(idx_or) = left_values.at(idx_left);
    idx_left++;
    idx_or++;
  }
  while (idx_right < right_values.size()){
    values.at(idx_or) = right_values.at(idx_right);
    idx_right++;
    idx_or++;
  }
  return inversions;
}

unsigned long merge_sort(std::vector<int> & values, int lindex, int rindex){
  if (lindex < rindex){
    int middle = (lindex + rindex)/2;
    unsigned long long inv_left = merge_sort(values, lindex, middle);
    unsigned long long inv_right = merge_sort(values, middle+1, rindex);
    unsigned long long inv_combine = combine(values, lindex, middle, rindex);
    return inv_left + inv_right + inv_combine;
  }
  return 0;
}



int main(){
  int d = 0;
  std::cin >> d;
  for (int i = 0; i < d; i++){
    int qtd = 0;
    std::cin >> qtd;
    std::vector<int> values;
    for (int j = 0; j < qtd; j++){
      int value = 0;
      std::cin >> value;
      values.emplace_back(value);
    }
    unsigned long long inversions = merge_sort(values, 0, values.size()-1);
    std::cout << inversions << std::endl;
  }

  return 0;
}

