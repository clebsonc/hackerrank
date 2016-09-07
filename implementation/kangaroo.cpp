#include <iostream>

int main(){
  int x1=0, x2=0, v1=0, v2=0, a=0, b=0;
  std::cin >> x1 >> v1 >> x2 >> v2;
  a = (x1-x2);
  b = (v2-v1);
  if(b == 0 || a/b <= 0)
    std::cout << "NO";
  else if(a%b==0)
    std::cout << "YES";
  else
    std::cout << "NO";


  return 0;
}
