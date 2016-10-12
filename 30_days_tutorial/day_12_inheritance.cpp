#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}

};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:

		Student(string name, string last_name, int id, vector<int> scores):Person(name, last_name, id){
			testScores = scores;
		}

		char calculate(){
			vector<int>::const_iterator it = testScores.cbegin();
			float total=0.0;
			while(it != testScores.cend()){
				total += *it;
				*it++;
			}
			total /= testScores.size();
			if(total >= 90)
				return 'O';
			else if(total >= 80)
				return 'E';
			else if(total >= 70)
				return 'A';
			else if(total >= 55)
				return 'P';
			else if(total >= 40)
				return 'D';
			else
				return 'T';
		}
};

int main() {
	string firstName;
	string lastName;
	int id;
	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
	vector<int> scores;
	for(int i = 0; i < numScores; i++){
		int tmpScore;
		cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}
