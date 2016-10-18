#include <iostream>
#include <stack>
#include <climits>

bool is_balanced(std::string s){
  std::stack<char> exp;
  for(int i=0; i< (int) s.size(); i++){
    if(s.at(i) == '{' || s.at(i) == '(' || s.at(i) == '['){
      exp.push(s.at(i));
    } else if( !exp.empty() &&
                ((s.at(i) == '}' && exp.top() == '{')  ||
                (s.at(i) == ']' && exp.top() == '[')  ||
                (s.at(i) == ')' && exp.top() == '('))  ) {
      exp.pop();
    } else {
      return false;
    }
  }
  if(exp.empty())
    return true;
  return false;
}


int main(){
  int t=0;
  std::cin >> t;
  std::cin.ignore(INT_MAX, '\n');
  std::cin.clear();

  for(int i=0; i<t; i++){
    std::string expression;
    std::getline(std::cin, expression);
    bool balanced = is_balanced(expression);
    std::cout << (balanced ? "YES" : "NO") << std::endl;
  }

  return 0;
}
