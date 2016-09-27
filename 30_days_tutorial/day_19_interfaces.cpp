#include <iostream>
#include <new>

using namespace std;

class AdvancedArithmetic{
	public:
		virtual int divisorSum(int n)=0;
};

class Calculator:public AdvancedArithmetic{
	public:
		int divisorSum(int n){
			int s=0;
			for(int i = 1; i <= n; i++){
				if(n%i == 0){
					s+=i;
				}
			}
			return s;
		}
};

int main(){
	int n;
	cin >> n;
	AdvancedArithmetic *myCalculator = new Calculator();
	int sum = myCalculator->divisorSum(n);
	cout << "I implemented: AdvancedArithmetic\n" << sum;

	delete myCalculator;
	return 0;
}
