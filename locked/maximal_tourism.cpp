#include <unordered_map>
#include <vector>
#include <iostream>

class Node{
  private:
    int index;
    bool visited;
    int dt;
    int ft;
    int pd;
    std::vector<int> adj_list;

  public:
    Node(){}

    Node(int n):index{n}{
      this->visited = false;
      this->dt = 0;
      this->ft = 0;
      int pd = -1;
    }

    int getIndex(){ return this->index;}
    bool wasVisited(){ return this->visited; }
    int getDt(){ return this->dt; }
    int getFt(){ return this->ft; }
    int getPd(){ return this->pd; }

    void setIndex(int i){ this->index = i;}
    void setVisit(bool v){ this->visited = v; }
    void setDt(int dt){this->dt = dt; }
    void setFt(int ft){this->ft = ft; }
    void setPd(int pd){this->pd = pd; }
    
    void addNeighbor(int n){ this->adj_list.emplace_back(n); }

    std::vector<int> getNeighbors() const { return this->adj_list; }
};

class Graph{
  private:
    std::unordered_map<int, Node> g;

  public:
    Graph(){}
    
    void addNode(int n){
      g.emplace(n, Node(n));
    }

    void addEdge(int u, int v){
      auto uit = g.find(u);
      auto vit = g.find(v);
      if (uit != g.end() && vit != g.end()){
        // nodes exists
        uit->second.addNeighbor(v);
        vit->second.addNeighbor(u);
      }
    }

    void printGraph() const{
      for (auto uit = g.begin(); uit != g.end(); uit++){
        std::vector<int> n = uit->second.getNeighbors();
        std::cout << uit->first << ": ";
        for (auto i : n){
          std::cout << i << ", ";
        }
        std::cout << std::endl;
      }
    }

    void dfsVisit(std::unordered_map<int, Node>::iterator u, int & time, int & compSize){
      time++;
      compSize++;
      u->second.setDt(time);
      u->second.setVisit(true);
      
      std::vector<int> neighbors = u->second.getNeighbors();
      for (int idx : neighbors){
        auto v = g.find(idx);
        if (!v->second.wasVisited()){
          v->second.setPd(u->first);
          dfsVisit(v, time, compSize);
        }
      }
      time++;
      u->second.setFt(time);
    }

    int getMaximumDistanceDFS(){
      int time = 0;
      int componenteSize = 0;
      std::unordered_map<int, Node>::iterator u = g.begin();
      for (u; u != g.end(); u++){
        int currCompSize = 0;
        if (!u->second.wasVisited()){
          dfsVisit(u, time, currCompSize);
          componenteSize = currCompSize > componenteSize ? currCompSize : componenteSize;
        }
      }
      return componenteSize;
    }
};


int main(){
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph g;
  for (int i = 1; i <= n; i++){
    g.addNode(i);
  }
  for (int i = 1; i <= m; i++){
    int u = 0, v = 0;
    std::cin >> u >> v;
    g.addEdge(u, v);
  }
  std::cout << g.getMaximumDistanceDFS() << std::endl;
  

  return 0;
}

