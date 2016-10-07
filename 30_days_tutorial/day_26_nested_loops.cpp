#include <iostream>

int main(){
  int return_date[3] = {0, 0, 0};
  int expected_date[3] = {0, 0, 0};
  
  for(int i = 0; i < 3; i++){
    std::cin >> return_date[i];
  }
  for(int i = 0; i < 3; i++){
    std::cin >> expected_date[i];
  }

  if((return_date[2] < expected_date[2]) ||
    (return_date[1] < expected_date[1] && return_date[2] == expected_date[2]) || 
    (return_date[0] < expected_date[0] && return_date[1] == expected_date[1] && return_date[2] == expected_date[2]))
    std::cout << 0 << std::endl;
  else if(return_date[0] > expected_date[0] &&
    return_date[1] == expected_date[1] && 
    return_date[2] == expected_date[2])
    std::cout << 15 * (return_date[0] - expected_date[0]);
  else if(return_date[1] > expected_date[1] &&
    return_date[2] == expected_date[2])
    std::cout << 500 * (return_date[1] - expected_date[1]);
  else
    std::cout << 10000 << std::endl;

  return 0;
}
