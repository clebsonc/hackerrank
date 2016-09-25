#include <iostream>
#include <vector>
#include <algorithm>

class IceCream{
  private:
    int id;
    int price;
  public:
    IceCream(int, int);
    const int getId() const;
    const int getPrice() const;
    void setId(int);
    void setPrice(int);
    bool operator<(const IceCream & ic) const;
};

IceCream::IceCream(int id, int price): id{id}, price{price}{
}

const int IceCream::getId() const {
  return this->id;
}

const int IceCream::getPrice() const{
  return this->price;
}

void IceCream::setId(int id){
  this->id = id;
}

void IceCream::setPrice(int p){
  this->price = p;
}

bool IceCream::operator<(const IceCream & ic) const{
  return price < ic.getPrice();
}

void read_values(std::vector<IceCream> & icv, int n){
  int p;
  for(int i = 0; i < n; i++){
    std::cin >> p;
    IceCream ic(i+1, p);
    icv.push_back(ic);
  }
}

void print_values(const std::vector<IceCream> & icv){
  std::vector<IceCream>::const_iterator ci = icv.cbegin();
  while(ci != icv.cend()){
    std::cout << "id: " << ci->getId() << " price: " << ci->getPrice() << std::endl;
    ci++;
  }
}

void find_match(std::vector<IceCream> & icv, const int m){
  int i = 0, j = icv.size()-1;
  std::sort(icv.begin(), icv.end());
  while(i<j){
    if((icv.at(i).getPrice() + icv.at(j).getPrice()) == m){
      if(icv.at(i).getId() < icv.at(j).getId())
        std::cout << icv.at(i).getId() << " " << icv.at(j).getId() << std::endl;
      else
        std::cout << icv.at(j).getId() << " " << icv.at(i).getId() << std::endl;
      break;
    }
    else if(icv.at(i).getPrice() + icv.at(j).getPrice() > m)
      j--;
    else if(icv.at(i).getPrice() + icv.at(j).getPrice() < m)
      i++;
  }
}

int main(){
  int m=0, n=0, t=0;
  std::vector<IceCream> icv;
  std::cin >> t;
  for(int i = 0; i < t; i++){
    std::cin >> m >> n;
    read_values(icv, n);
    find_match(icv, m);
    icv.clear();
  }

  return 0;
}

