#include <iostream>
#include <climits>

int main(){
  int t=0;
  int student=0, threshold=0, counter=0, on_time=0;
  std::cin >> t;
  

  for(int i = 0; i<t; i++){
    std::cin.clear();
    std::cin.ignore(INT_MAX,'\n');
    on_time = 0;
    counter=0;
    std::cin >> student >> threshold;
    for(int j = 0; j < student; j++){
      std::cin >> on_time;
      if(on_time <= 0)
        counter++;    
    }
    if(counter >= threshold)
      std::cout << "NO" << std::endl;
    else
      std::cout << "YES" << std::endl;
  }

  return 0;
}
