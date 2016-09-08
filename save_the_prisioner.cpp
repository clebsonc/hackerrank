#include <iostream>


int main(){
  int t = 0, n=0, m=0, s=0;
  int r = 0, last=0;
  std::cin >> t;

  for(int i = 0; i < t; i++){
    std::cin >> n >> m >> s;
    r = m%n;
    if(r == 0){
      if(s==1)
        std::cout << n << std::endl;
      else
        std::cout << s-1 << std::endl;
    } else{
      last = s+r-1;
      last = last <= n ? last : last-n;
      std::cout << last << std::endl;
    }
  }

  return 0;
}
