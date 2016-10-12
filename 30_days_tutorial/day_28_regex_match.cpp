#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>

int main(){
  int n = 0;
  std::cin >> n;
  std::string name, email;
  std::vector<std::string> people;
  std::regex re("(.*)@gmail.com$");
  for(int i=0; i<n; i++){
    std::cin >> name >> email;
    if(std::regex_match(email, re))
      people.push_back(name);
  }
  
  std::sort(people.begin(), people.end());

  for(int i = 0; i<people.size(); i++)
    std::cout << people.at(i) << std::endl;

  return 0;
}
