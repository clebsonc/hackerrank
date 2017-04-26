#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

enum class Color{
  kWhite, kGray, kBlack
};

class Edge{
  private:
    int destine;
    int weight;
  public:
    Edge(){}
    Edge(int d, int w):destine{d}, weight{w}{}

    void setDestine(int d){this->destine = d;}
    void setWeight(int w){this->weight = w;}
    int getDestine(){return this->destine;}
    int getWeight(){return this->weight;}
};

class Node{
  private:
    int name;
    std::unordered_map<int, Edge> adj_list;
    Color color;
    int discovered_distance;
    int predecessor;

  public:
    Node(){};
    Node(int n):name{n}{
      this->discovered_distance = -1;
      this->color = Color::kWhite;
    }
    
    void setName(int n){this->name = name;}
    void setPredecessor(int p){this->predecessor = p;}   
    void setColor(Color c){this->color = c;}
    void setDiscoveredDistance(int d){this->discovered_distance = d; }

    void increaseDistance(int d){
      this->discovered_distance = this->discovered_distance + d;
    }

    void insertEdge(int endPoint, int weight=1){
      this->adj_list.emplace(endPoint, Edge(endPoint, weight));
    }

    int getName(){return this->name;}
    int getPredecessor(){return this->predecessor;}
    std::unordered_map<int, Edge> getAdjList(){return this->adj_list;}
    Color getColor(){return this->color;}
    int getDiscoveredDistance(){return this->discovered_distance;}
};

class Graph{
  private:
    std::unordered_map<int, Node> g;
    int source;

  public:
    // Build an empty graph
    Graph(){}
    
    void insertNode(int n){g.emplace(n, Node(n));}
    
    void insertEdge(int s, int d, int weight=1){
      auto u = g.find(s); // source
      auto v = g.find(d); // destine
      if(u != g.end() && v != g.end()){
        u->second.insertEdge(d, weight);
      }
    }

    void print_graph(){
      for (auto mindex : g){
        std::cout << mindex.first << ": ";
        for (auto medge : mindex.second.getAdjList()){
          std::cout << medge.first << ", ";
        }
        std::cout << std::endl;
      }
    }
    
    void initialize(){
      for(auto it = g.begin(); it != g.end(); it++){
        it->second.setColor(Color::kWhite);
        it->second.setPredecessor(-1);
        it->second.setDiscoveredDistance(0);
      }
    }

    void printDiscoveredTime(){
      for (int i = 1; i <= g.size(); i++){
        if ( i != this->source){
          auto v = g.find(i);
          if (v->second.getDiscoveredDistance())
            std::cout << v->second.getDiscoveredDistance() << " ";
          else
            std::cout << -1 << " ";
        }
      }
    }

    void bfs(int source) {
      this->source = source;
      auto s = g.find(source);
      if (s != g.end()){ // the source exists
        initialize();
        std::queue<std::unordered_map<int, Node>::iterator> q;
        q.emplace(s);
        while (!q.empty()){
          auto u = q.front();
          q.pop();
          u->second.setColor(Color::kGray);
          for (auto nedge : u->second.getAdjList()){ // neighbor edge
            auto v = g.find(nedge.second.getDestine()); // reference to node
            if (v->second.getColor() == Color::kWhite){
              v->second.setColor(Color::kGray);
              int ndis =  u->second.getDiscoveredDistance() + nedge.second.getWeight();
              v->second.increaseDistance(ndis);
              v->second.setPredecessor(u->second.getName());
              q.emplace(v);
            }
          }
          u->second.setColor(Color::kBlack);
        }
      }
    }
};


int main(){
  int qtd = 0;
  std::cin >> qtd;
  for (int i = 0; i < qtd; i++){
    int n = 0, e = 0;
    std::cin >> n >> e;
    Graph g; // build an empty graph
    for (int j = 1; j <= n; j++)
      g.insertNode(j);
    
    for (int j = 0; j < e; j++){
      int s = 0, d = 0;
      std::cin >> s >> d;
      g.insertEdge(s, d, 6);
      g.insertEdge(d, s, 6);
    }
    int start = 1;
    std::cin >> start;
    g.bfs(start);
    //g.print_graph();
    g.printDiscoveredTime();
    std::cout << std::endl;
  }
  
  return 0;
}

