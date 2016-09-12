#include <iostream>
#include <climits>

int main(){
  int n=0, count=0, i=0;
  std::string values;

  std::cin >> n;
  std::cin.clear();
  std::cin.ignore(INT_MAX, '\n');

  std::getline(std::cin, values);

  while((n-i) >= 3){
    if(values.at(i)== '0' && values.at(i+1) == '1' && values.at(i+2) == '0'){
      values.at(i+2) = '1';
      count++;
    }
    i++;
  }

  std::cout << count << std::endl;
  return 0;
}
