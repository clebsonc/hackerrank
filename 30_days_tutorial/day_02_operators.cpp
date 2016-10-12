#include <iostream>
#include <iomanip>
#include <cmath>

float compute_total(float cost, int tip, int tax){
  return cost + cost*tip/100 + cost*tax/100;
}


int main(){
  float cost;
  int tip, tax;

  std::cin >> cost >> tip >> tax;
  cost = round(compute_total(cost, tip, tax));
  std::cout << "The total meal cost is " << cost << " dollars.";
  return 0;
}

