#include <iostream>
#include <unordered_map>
#include <string>


class Node{
  public:
    std::unordered_map<char, Node*> hash;
    bool end_word;
      
    Node():end_word{false}{}

    ~Node(){
      for (auto it = hash.begin(); it != hash.end(); it++){
        delete it->second;
      }
    }

};


class Trie{
  private:
    Node root;
  public:
    void add_word(const std::string & s){
      Node * aux = &root;
      for (int i=0; i < s.size(); i++){
        char c = s.at(i);
        std::unordered_map<char, Node*>::iterator it = aux->hash.find(c);
        if (it != aux->hash.end()){
          aux = it->second;
        }
        else {
          aux->hash.emplace(c, new Node());
          it = aux->hash.find(c);
          aux = it->second;
        }
        if (i==s.size()-1){
          aux->end_word = true;
        }
      }
    }
    
    void count_end_words(Node * aux, int & counter){
      if (aux->hash.empty()){
        return;
      }
      
      for(auto it = aux->hash.begin(); it!= aux->hash.end(); it++){
        if (it->second->end_word)
          counter++;
        count_end_words(it->second, counter);
      }
    }

    int count_words_starting_with(const std::string &s){
      Node * aux = &root;
      for (const char c : s){
        std::unordered_map<char, Node*>::iterator it = aux->hash.find(c);
        if (it == aux->hash.end()){
          /**letter does not exist in the current branch, therefore, 
          * the word does not exist in the trie */
          return 0;
        }
        aux = it->second;
      }
      int count = 0;
      if (aux->end_word)
        count++;
      count_end_words(aux, count);
      return count;
    }
};

int main(){
  int n;
  std::cin >> n;
  Trie trie;
  for(int i = 0; i < n; i++){
    std::string s;
    std::cin >> s;
    if(!s.compare("add")){
      std::cin >> s;
      trie.add_word(s);
    } else {
      std::cin >> s;
      std::cout << trie.count_words_starting_with(s) << std::endl;
    }
  }

  return 0;
}

