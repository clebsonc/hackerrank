#include <iostream>

int solveMeFirst(int a, int b){
	return a + b;
}


int main(){
	int a, b;
	std::cin >> a >> b;
	int c = solveMeFirst(a, b);
	std::cout << c << std::endl;
	return 0;
}
