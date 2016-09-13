#include <iostream>
#include <string>
#include <map>
#include <climits>

int main(){
  int n=0;
  std::string name="", phone="";
  std::map<std::string, std::string> contacts;
  
  std::cin >> n;
  for(int i = 0; i < n; i++){
    std::cin >> name >> phone;
    contacts.insert(std::pair<std::string,std::string>(name, phone));
  }
  while(std::cin >> name){
    try{
      std::cout << name << "=" << contacts.at(name)<<std::endl;
    } catch(const std::out_of_range&  oor){
      std::cout << "Not found" << std::endl;
    }
  }

  return 0;
}
