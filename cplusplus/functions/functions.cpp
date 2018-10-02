#include <iostream>

int max_of_four(int a, int b, int c, int d){
	int max;
	if (a>b){
		if (a>c){
			if (a>d){
				return a;
			}
			else{
				return d;
			}
		}
		else{
			if (c > d){
				return c;
			}
			else{
				return d;
			}
		}
	}
	else{
		if(b>c){
			if(b>d){
				return b;
			}
			else{
				return d;
			}
		}
		else{
			if (c>d){
				return c;
			}
			else{
				return d;
			}
		}
	}
}

int main(){
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	int max = max_of_four(a, b, c, d);
	std::cout << max << std::endl;
	return 0;
}

