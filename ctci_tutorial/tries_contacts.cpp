#include <iostream>
#include <unordered_map>
#include <string>


class Node{
  public:
    std::unordered_map<char, Node*> trie;
    bool end_word;
      
    Node(){}

    void add_word(std::string s){
      std::unordered_map<char, Node*> * n = &trie;
      for (char c : s){
        std::unordered_map<char, Node*>::iterator it = 
        if (n->empty() || ){
          n->emplace(c, new Node());
        }
        else if (
      }
    }
};

int main(){
  Node a;
  a.add_word("abc");

  return 0;
}

