#include <iostream>
#include <unordered_map>
#include <string>


class Node{
  public:
    std::unordered_map<char, Node*> values;
    bool end_word;
      
    Node():end_word{true}{}
};


class Trie{
  private:
    Node root;
    Node * current;

  public:
    void add_word(const std::string & s){
      for (char c : s){
        if (root.
      }
    }
};

int main(){
  Trie a;
  a.add_word("abc");

  return 0;
}

