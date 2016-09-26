#include <iostream>
#include <queue>
#include <stack>
#include <string>


class Solution{
  private:
    std::queue<char> queue;
    std::stack<char> stack;

  public:
    void pushCharacter(char ch);
    void enqueueCharacter(char ch);
    
    char popCharacter();
    char dequeueCharacter();
};

void Solution::pushCharacter(const char ch){
  this->stack.push(ch);
}

void Solution::enqueueCharacter(const char ch){
  this->queue.push(ch);
}

char Solution::popCharacter(){
  char c = stack.top();
  stack.pop();
  return c;
}

char Solution::dequeueCharacter(){
  char c = queue.front();
  queue.pop();
  return c;
}

int main() {
    // read the string s.
    std::string s;
    std::getline(std::cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        std::cout << "The word, " << s << ", is a palindrome.";
    } else {
        std::cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}
