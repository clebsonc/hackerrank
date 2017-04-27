#include <iostream>
#include <vector>
#include <unordered_map>

class Node{
  public:
    long int index;
    bool visited;
    long int discovered;
    long int finished;
    long int predecessor;
    std::vector<long int> adj_list;

    Node(){}
    Node(long int i):index{i}{
      this->visited = false;
      this->discovered = 0;
      this->finished = 0;
      this->predecessor = -1;
    }
};

class Graph{
  public:
    std::unordered_map<long int, Node> g;

    void insertNode(long int node_name){ 
      this->g.emplace(node_name, Node(node_name));
    }

    void insertEdge(long int node_source, long int node_destine){
      auto u = this->g.find(node_source);
      auto v = this->g.find(node_destine);
      if (u != this->g.end() && v != this->g.end()){
        u->second.adj_list.emplace_back(node_destine);
      }
    }

    void print_graph() const{
      for (auto u : g){ // nodes in the hash
        std::cout << u.first << ": ";
        for (auto v : u.second.adj_list){ // adj list for each node
          std::cout << v << " ";
        }
        std::cout << std::endl;
      }
    }
    
    void initialize(){
      std::unordered_map<long int, Node>::iterator it = this->g.begin();
      while (it != this->g.end()){
        it->second.visited = false;
        it->second.discovered = 0;
        it->second.finished = 0;
        it->second.predecessor = -1;
        it++;
      }
    }

    void dfsVisit(std::unordered_map<long int, Node>::iterator & it, 
                  long int & time, long int & size){
      time++;
      size++;
      it->second.discovered = time;
      it->second.visited = true;
      for (long int neighbor : it->second.adj_list){
        auto v = g.find(neighbor);
        if (!v->second.visited){
          dfsVisit(v, time, size);
        }
      }
      time++;
      it->second.finished = time;
    }

    std::vector<long int> dfsComponentSize(){
      initialize();
      std::unordered_map<long int, Node>::iterator it = g.begin();
      long int time = 0;
      std::vector<long int> compSize;
      while (it != g.end()){
        long int size = 0;
        if (!it->second.visited){
          dfsVisit(it, time, size);
          compSize.emplace_back(size);
        }
        it++;
      }
      return compSize;
    }
};

int main(){
  std::ios::sync_with_stdio(false);
  long int n = 0, p = 0;
  std::cin >> n >> p;
  Graph g;
  for (long int i = 0; i < n; i++)
    g.insertNode(i);

  for (long int i = 0; i < p; i++){
    long int s = 0, d = 0;
    std::cin >> s >> d;
    g.insertEdge(s, d);
    g.insertEdge(d, s);
  }
  
  std::vector<long int> component_size = g.dfsComponentSize();
  long int max_combination = (n*(n-1))/2;
  for (long int value : component_size){
    max_combination -= (value*(value-1))/2;
  }


  std::cout << max_combination <<  std::endl;

  return 0;
}

