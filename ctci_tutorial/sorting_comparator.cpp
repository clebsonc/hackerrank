#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Player{
  private:
    std::string name;
    int score;

  public:
    /**
    * Constructors
    */
    Player(){};

    Player(std::string name, int score):name{name}, score{score}{}

    void setName(const std::string & name){
      this->name = name;
    }

    void setScore(const int & score){
      this->score = score;
    }

    std::string getName() const {
      return this->name;
    }

    int const getScore() const{
      return this->score;
    }

    bool operator<(const Player & p){
      if (this->score == p.getScore()){
        bool a = !(this->name < p.getName());
        return a;
      }
      return this->score < p.getScore();
    }
};

int main(){
  std::vector<Player> players;
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++){
    std::string s = "";
    int v = 0;
    std::cin >> s >> v;
    players.emplace_back(Player(s, v));
  }
  std::sort(players.rbegin(), players.rend());
  for (Player a : players){
    std::cout << a.getName() << " " << a.getScore() << std::endl;
  }

  return 0;
}

