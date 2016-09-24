#include <iostream>
#include <new>

int read_values(int * p, const int n){
	int sum = 0;
  
  for(int i = 0; i < n; i++){
    std::cin >> *(p+i);
    sum += *(p+i);
  }
	return sum;
}

void print_values(int * p, int n){
  for(int i = 0; i<n; i++){
    std::cout << *(p+i) << " ";
  }
}

bool is_left_equal_right_given_middle(int * p, int n, int sum){
	int left = 0, right=sum;
	for(int m = 0; m < n; m++){
		left = sum - right;
		right = right - *(p+m);
		if(left == right){
			return true;
 		}
 	}
	return false;
}

int main(){
	int t=0, n=0, sum = 0;
	int * p = nullptr;  // hold the array of integers
	std::cin >> t;
	for(int i = 0; i < t; i++){
		std::cin >> n;
    p = new int [n];
		sum = read_values(p, n);
		if(sum!=0){
			std::cout << (is_left_equal_right_given_middle(p, n, sum) ?"Yes":"No") << std::endl;
			delete [] p;
			p = nullptr;
		}
	}
	return 0;
}
