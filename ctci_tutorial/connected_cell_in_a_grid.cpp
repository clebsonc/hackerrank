#include <iostream>
#include <vector>
#include <unordered_map>


enum class Color{
  kWhite,
  kGray,
  kBlack,
};

class Node{
  private:
    int index;
    int line;
    int column;
    int pred;
    Color color;
    int Dt;
    int Ft;
    std::vector<int> neighbors;

  public:
    Node(){index = 0; line = -1, column = -1;}

    Node(int i, int l, int c): index{i}, line{l}, column{c}{}

    void setIndex(int i){this->index = i;}
    void setLine(int l){this->line = l;}
    void setColumn(int c){this->column = c;}
    void setPredecessor(int p){this->pred = p;}
    void setDt(int dt){this->Dt = dt;}
    void setFt(int ft){this->Ft = ft;}
    void setColor(Color c){this->color = c;}

    int getIndex() const {return index;}
    int getLine() const {return line;}
    int getColumn() const{return column;}
    int getPredecessor() const {return this->pred;}
    int getDt() const {return Dt;}
    int getFt() const {return Ft;}
    Color getColor() const {return this->color;}

    void addNeighbor(int n){ neighbors.emplace_back(n); }
    const std::vector<int> & getNeighbors() const{return this->neighbors; }

    bool operator==(const Node & n) const {return this->index == n.getIndex(); }
};

class Graph{
  private:
    std::unordered_map<int, Node> adj_list;

  public:
    Graph(){}
    
		void insertNode(const Node & n){
      adj_list.emplace(n.getIndex(), n);
    }

		void insertEdge(const Node & i, const Node & j){
			auto it = adj_list.find(i.getIndex());
			it->second.addNeighbor(j.getIndex());
		}
    
    void initialize(){
      for (std::unordered_map<int, Node>::iterator it = adj_list.begin(); 
           it != adj_list.end(); it++){
        it->second.setPredecessor(-1);
        it->second.setColor(Color::kWhite);
        it->second.setDt(0);
        it->second.setFt(0);
      }
    }

    void DFSTraversal(std::unordered_map<int, Node>::iterator & u, 
                      int & time, int & compSize){
      u->second.setColor(Color::kGray);
      u->second.setDt(time);
      time++;
      compSize++;
      std::vector<int> neighbors = u->second.getNeighbors();

      for (auto & indexv : u->second.getNeighbors()){
        auto v = adj_list.find(indexv);
        if (v->second.getColor() == Color::kWhite){
          v->second.setPredecessor(u->second.getIndex());
          DFSTraversal(v, time, compSize);
        }
      }
      time++;
      u->second.setColor(Color::kBlack);
      u->second.setFt(time);
    }

    int DFSMaxComponent(){
      initialize();
      auto u = adj_list.begin();
      int time = 1;
      int maxComp = 1;
      while (u != adj_list.end()){
        if (u->second.getColor() == Color::kWhite){
          int compSize = 0;
          DFSTraversal(u, time, compSize);
          maxComp = compSize > maxComp ? compSize : maxComp;
        }
        u++;
      }
      return maxComp;
    }

    void print_graph() const {
      for (auto & it : adj_list){
        std::cout << it.first << ": ";
        for (auto & v : it.second.getNeighbors()){
          std::cout << v << ", ";
        }
        std::cout << std::endl;
      }
    }
};





int main(){
  int r = 0, c = 0;
  std::cin >> r >> c;
  Graph g;
  std::vector<std::vector<Node>> matrix(r, std::vector<Node>(c, Node()));
  int index = 1;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      int v = 0;
      std::cin >> v;
      if (v > 0){
        matrix.at(i).at(j).setIndex(index);
        matrix.at(i).at(j).setLine(i);
        matrix.at(i).at(j).setColumn(j);
        g.insertNode(matrix.at(i).at(j));
      }
      index++;
    }
  }
  
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      if (matrix.at(i).at(j).getIndex()){
        if (i == 0 && j == 0){
          if(matrix.at(i).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j+1));
          if(matrix.at(i+1).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j+1));
          if(matrix.at(i+1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j));
        } 
        else if (i == 0 && j == c-1){
          if(matrix.at(i).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j-1));
          if(matrix.at(i+1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j));
          if(matrix.at(i+1).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j-1));
        }
        else if (i == r-1 && j == 0){
          if(matrix.at(i-1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j));
          if(matrix.at(i-1).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j+1));
          if(matrix.at(i).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j+1));
        }
        else if (i == r-1 && j == c-1){
          if(matrix.at(i).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j-1));
          if(matrix.at(i-1).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j-1));
          if(matrix.at(i-1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j));
        } else if (i == 0){
          if(matrix.at(i).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j-1));
          if(matrix.at(i).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j+1));
          if(matrix.at(i+1).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j-1));
          if(matrix.at(i+1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j));
          if(matrix.at(i+1).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j+1));
        } else if (i == r-1){
          if(matrix.at(i).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j-1));
          if(matrix.at(i).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j+1));
          if(matrix.at(i-1).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j-1));
          if(matrix.at(i-1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j));
          if(matrix.at(i-1).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j+1));
        } else if (j == 0){
          if(matrix.at(i-1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j));
          if(matrix.at(i+1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j));
          if(matrix.at(i-1).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j+1));
          if(matrix.at(i).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j+1));
          if(matrix.at(i+1).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j+1));
        } else if (j == c-1){
          if(matrix.at(i-1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j));
          if(matrix.at(i+1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j));
          if(matrix.at(i-1).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j-1));
          if(matrix.at(i).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j-1));
          if(matrix.at(i+1).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j-1));
        } else {
          if(matrix.at(i-1).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j-1));
          if(matrix.at(i-1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j));
          if(matrix.at(i-1).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i-1).at(j+1));
          if(matrix.at(i).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j-1));
          if(matrix.at(i).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i).at(j+1));
          if(matrix.at(i+1).at(j-1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j-1));
          if(matrix.at(i+1).at(j).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j));
          if(matrix.at(i+1).at(j+1).getIndex())
            g.insertEdge(matrix.at(i).at(j), matrix.at(i+1).at(j+1));
        }
      } // end if
    }
  }
  
  //g.print_graph();

  int max_comp = g.DFSMaxComponent();
  std::cout << max_comp << std::endl;

  return 0;
}
