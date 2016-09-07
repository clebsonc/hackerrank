#include <iostream>

int main(){
    int n;
    std::cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = i; j<(n-1); j++)
            std::cout << " ";
        for(int j = (n-i); j<=n; j++)
            std::cout << "#";
        std::cout << "\n";
    }
    return 0;
}

