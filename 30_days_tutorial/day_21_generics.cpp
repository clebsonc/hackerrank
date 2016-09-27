#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printArray(const vector<T> & tv){
	for(int i = 0; i < tv.size(); i++){
		cout << tv.at(i) << endl;
	}
}


int main() {
    vector<int> vInt{1, 2, 3};
    vector<string> vString{"Hello", "World"};
    
    printArray<int>(vInt);
    printArray<string>(vString);
    
    return 0;
}
