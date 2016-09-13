#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <climits>

int main(){
	int n=0, position=0, count=0;
	std::string s;
	std::set<char> unique;
  std::vector<int> gem_string(26, 0); // vector from each letter of the alphabet

	std::cin >> n;
  
  
	for(int i = 0; i < n; i++){
		std::cin >> s;
    int j = 0;
		for(j = 0; j < s.size(); j++){
			unique.insert(s.at(j));
		}
		for(std::set<char>::iterator it = unique.begin(); it!=unique.end(); it++){
			position = *it - 'a';
			gem_string.at(position)+=1;
		}
    unique.clear();
	}

	for(int i=0; i < 26; i++){
		if(gem_string.at(i) == n){
 			count++;
		}
	}
	std::cout << count << std::endl;
	return 0;
}
