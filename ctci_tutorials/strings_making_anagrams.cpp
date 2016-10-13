#include <iostream>
#include <string>
#include <cmath>

#define letters 26


void initialize(int * const s1c){
  for(int i = 0; i < letters; i++){
    s1c[i] = 0;
  }
}

void print_quantity(const int * const s1c){
  for(int i  = 0; i < letters; i++){
    std::cout << s1c[i] << " ";
  }
  std::cout << std::endl;
}

void count_chars(const std::string & s, int * const p){
  for(int i = 0; i < s.size(); i++){
    int pos = s.at(i) - 'a';
    p[pos] = p[pos]+1;
  }
}

int find_deletions(int * p1, int * p2){
  int count = 0;
  for(int i = 0; i < letters; i++){
    count += std::abs(p1[i] - p2[i]);
  }
  return count;
}

int main(){
  std::string s1, s2;
  std::cin >> s1 >> s2;
  int s1c[letters], s2c[letters];

  initialize(s1c);
  initialize(s2c);

  count_chars(s1, s1c);
  count_chars(s2, s2c);
  
  int deletions = find_deletions(s1c, s2c);
  std::cout << deletions << std::endl;

  return 0;
}
