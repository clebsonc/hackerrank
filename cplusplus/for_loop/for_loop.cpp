#include <iostream>
#include <vector>

void printNumbersInRange(int a, int b){
	std::vector<std::string> names = {
		"one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"
	};
	for (int i=a; i<=b; i++){
		if (i>9){
		 	if(i%2 == 0){
				std::cout << "even" << std::endl;
			}
			else{
				std::cout << "odd" << std::endl;
			}
		}
		else{
			std::cout << names.at(i-1) << std::endl;
		}
	}
}

int main(){
	int a, b;
	std::cin >> a >> b;
	printNumbersInRange(a, b);

	return 0;
}
