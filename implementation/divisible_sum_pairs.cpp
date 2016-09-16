#include <iostream>
#include <map>
#include <vector>


void print_hash_map(const std::map<int, std::vector<int>> & values, const int & k){
  for(int i = 0; i < k; i++){
    std::cout << i << ": [";
    try{
      std::vector<int>::const_iterator it = values.at(i).cbegin();
      while(it != values.at(i).cend()){
        std::cout << *it << " ";
        it++;
      }
    } catch(std::out_of_range oor){
      std::cout << "empty";
    }
    std::cout << "]" << std::endl;
  }
}

void fill_hash_map(std::map<int, std::vector<int>> & values, const int & n, const int & k){
  for(int i = 0; i < n; i++){
    int temp;
    try{
      std::cin >> temp;
      values.at(temp%k).push_back(temp);
    }catch(std::out_of_range oor){
      std::vector<int> t;
      t.push_back(temp);
      values.insert( std::pair<int, std::vector<int>>(temp%k, t) );
    }
  }
}

void print_set(const std::map<int, std::vector<int>> & values, const int & n, const int & k){
  int j = 0;
  std::vector<int>::const_iterator it;
  for(int i = 0; i <= k/2; i++){
    std::cout << "[";
    try{
      if(i == 0)
        std::cout << values.at(0).at(0);
      else{
        if((k - i) == i){
          std::cout <<values.at(i).at(0) << "]" << std::endl;
          continue;
        }
        if(values.count(i) == 1 && values.count(k-i) == 1){
          if(values.at(i).size() > values.at(k-i).size()){
            it = values.at(i).cbegin();
            j = i;
          }
          else{
            it = values.at(k-i).cbegin();
            j = k-i;
          }
        } else if(values.count(i) == 1){
            it = values.at(i).cbegin();
            j=i;
        } else if(values.count(k-i)==1){
            it = values.at(k-i).cbegin();
            j=k-i;
        }
        while(it!=values.at(j).cend()){
          std::cout << *it << " ";
          it++;
        }
      }
    } catch(std::out_of_range oor){
      std::cout << "empty";
    }
    std::cout << "]" << std::endl;
  }
}

void count_set(const std::map<int, std::vector<int>> & values, const int & n, const int & k){
  std::vector<int>::const_iterator it;
  int j = 0;
  int count= 0;
  for(int i = 0; i <= k/2; i++){
    try{
      if(i == 0 && values.count(0) == 1)
        count++;
      else{
        if((k - i) == i && values.count(i) == 1){
          count++;
          continue;
        }
        if(values.count(i) == 1 && values.count(k-i) == 1){
          if(values.at(i).size() > values.at(k-i).size()){
            it = values.at(i).cbegin();
            j = i;
          }
          else{
            it = values.at(k-i).cbegin();
            j = k-i;
          }
        } else if(values.count(i) == 1){
            it = values.at(i).cbegin();
            j=i;
        } else if(values.count(k-i)==1){
            it = values.at(k-i).cbegin();
            j=k-i;
        }

        while(it!=values.at(j).cend()){
          count++;
          it++;
        }
      }
    } catch(std::out_of_range oor){
    }
  }
  std::cout << count << std::endl;
}

int main(){
  int n=0, k=0;
  std::map<int, std::vector<int>> values;

  std::cin >> n >> k;
  fill_hash_map(values, n, k);

  //print_hash_map(values, k);

  //print_set(values, n, k);

  count_set(values, n, k);

  return 0;
}
