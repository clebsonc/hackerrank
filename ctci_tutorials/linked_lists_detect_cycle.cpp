#include <iostream>

struct Node{
  int data;
  struct Node *next;
};

bool has_cycle(Node *head) {
  Node *aux1 = head;
  Node *aux2 = head->next;
  while(aux2!=NULL){
    if(aux2->next != NULL && aux2->next->next != NULL){
      aux1 = aux1->next;
      aux2 = aux2->next->next;
      if(aux1 == aux2)
        return true;
    } else{
      return false;
    }
  }
  return false;
}

int main(){
  //Simple test, initializing the structure
  Node * h = new Node;
  h->data = 1;
  h->next = new Node;

  h->next->data = 2;
  h->next->next = new Node;

  h->next->next->data = 3;
  h->next->next->next = NULL;

  //testing if the structure has a cycle
  bool cycle = has_cycle(h);
	if(cycle)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;

  clean_list(h);

  return 0;
}

