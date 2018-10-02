#include <iostream>

void print_pos_name(int value){
	if(value == 1){
		std::cout << "one" << std::endl;
	}
	else if (value == 2){
		std::cout << "two" << std::endl;
	}
	else if (value == 3){
		std::cout << "three" << std::endl;
	}
	else if (value == 4){
		std::cout << "four" << std::endl;
	}
	else if (value == 5){
		std::cout << "five" << std::endl;
	}
	else if (value == 6){
		std::cout << "six" << std::endl;
	}
	else if (value == 7){
		std::cout << "seven" << std::endl;
	}
	else if (value == 8){
		std::cout << "eight" << std::endl;
	}
	else if (value == 9){
		std::cout << "nine" << std::endl;
	}
	else{
		std::cout << "Greater than 9" << std::endl;
	}
}


int main(){
	int pos;
	std::cin >> pos;
	print_pos_name(pos);
	return 0;
}
