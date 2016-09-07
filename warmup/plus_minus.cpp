#include <iostream>
#include <iomanip>

int main(){
    float n=0.0; 
    int positive=0, negative=0, zeroes = 0;
    int value;
    std::cin >> n;
    std::cout << std::setprecision(6) << std::fixed;
    
    for(int i = 0; i < n; i++){
        std::cin >> value;
        if(value > 0)
            positive++;
        else if(value < 0)
            negative++;
        else
            zeroes++;
    }
    std::cout << positive/n << std::endl;
    std::cout << negative/n << std::endl;
    std::cout << zeroes/n;

    return 0;
}

