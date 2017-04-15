#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

class IceCream{
  private:
    int id;
    int price;

  public:
    IceCream();
    IceCream(int, int);
    
    int getId() const;
    int getPrice() const;

    bool operator<(const IceCream & ic) const;
};

IceCream::IceCream(){}
IceCream::IceCream(int id, int price):id{id}, price{price}{}

int IceCream::getId() const {
  return this->id;
}

int IceCream::getPrice() const {
  return this->price;
}

bool IceCream::operator<(const IceCream & ic) const{
  return this->price < ic.getPrice();
}


class Flavour{
  private:
    std::vector<IceCream> flavours;
    

  public:
    Flavour(){};

    void addFlavour(int a, int b){
      flavours.emplace_back(IceCream(a, b));
    }
    
    std::pair<int, int> binary_search(int price){
      std::pair<int, int> ids(-1, -1);
      for (int i = 0; i < flavours.size()-1; i++){
        int begin = i;
        int end = flavours.size()-1;
        int mid = (end + begin)/2;
        while (begin  <= end){
          if ((flavours.at(i).getPrice() + flavours.at(mid).getPrice()) == price){
            ids.first = flavours.at(i).getId();
            ids.second =  (i==mid ? flavours.at(mid+1).getId() : flavours.at(mid).getId());
            return ids;
          }
          if ((flavours.at(i).getPrice() + flavours.at(mid).getPrice()) > price){
            end = mid-1;
          } else {
            begin = mid+1;
          }
          mid = (end + begin)/2;
        }
      }
      return ids;
    }
    std::pair<int, int> get_ids_with_price(int price){
      std::sort(flavours.begin(), flavours.end());
      return binary_search(price);
    }

    void print_flavours() const{
      for (auto & e : flavours){
        std::cout << e.getPrice() << " " << e.getId() << std::endl;
      }
    }
};




int main(){
  int visits = 0;
  std::cin >> visits;
  for (int i = 0; i < visits; i++){
    int price;
    std::cin >> price;
    int n  = 0;
    std::cin >> n;
    Flavour f;
    for (int i = 1; i <= n; i++){
      int v = 0;
      std::cin >> v; 
      f.addFlavour(i, v);
    }
    std::pair<int, int> p =  f.get_ids_with_price(price);
    if (p.first!=-1){
      if ( p.first < p.second)
        std::cout << p.first << " " << p.second << std::endl;
      else
        std::cout << p.second << " " << p.first << std::endl;

    }
  }
  return 0;
}

