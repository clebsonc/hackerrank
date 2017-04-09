#include <iostream>
#include <vector>

void copy_val(std::vector<int> & nval, std::vector<int> & oval, int i, int j){
  for (i; i <= j; i++){
    nval.emplace_back(oval.at(i));
  }
}

void combine(std::vector<int> & values, int lindex, int middle, int rindex){
  std::vector<int> left_values;
  std::vector<int> right_values;
  
  copy_val(left_values, values, lindex, middle); //TODO: implement function
  copy_val(right_values, values, middle+1, rindex);
  
  int idx_left = 0, idx_right = 0, idx_or = lindex;
  while (idx_left < left_values.size() && idx_right < right_values.size()){
    if (left_values.at(idx_left) <= right_values.at(idx_right)){
      values.at(idx_or) = left_values.at(idx_left);
      idx_left++;
      idx_or++;
    } else {
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
}

void merge_sort(std::vector<int> & values, int lindex, int rindex){
  if (lindex < rindex){
    int middle = (lindex + rindex)/2;
    merge_sort(values, lindex, middle);
    merge_sort(values, middle+1, rindex);
    combine(values, lindex, middle, rindex);
  }
}



int main(){
  std::vector<int> values = {20, 11, 33, 10, 24, 34, 2, 1, 4, };
  merge_sort(values, 0, values.size()-1);
  
  for (int v : values)
    std::cout << v << " ";
  std::cout << std::endl;

  return 0;
}

