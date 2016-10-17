#include <iostream>
#include <string>
#include <sstream>
#include <climits>

bool is_balanced(std::string expression){
  int i = 0, j = (int) expression.size()-1;
  while(i < j){
    if( (expression.at(i)=='{' && expression.at(j)=='}') || 
        (expression.at(i)=='[' && expression.at(j)==']') ||  
        (expression.at(i)=='(' && expression.at(j)==')') ) {
      i++;
      j--;
    } else {
      return false;
    }
  }
  return true;
}

int main(){
  int t;
  std::cin >> t;
  std::cin.ignore(INT_MAX, '\n');
  std::cin.clear();
  
  for(int r = 0; r < t; r++){
    std::string expression;
    std::getline(std::cin, expression);
    bool balanced = is_balanced(expression);

    std::cout << (balanced? "YES" : "NO") << std::endl;
  }

  return 0;
}

