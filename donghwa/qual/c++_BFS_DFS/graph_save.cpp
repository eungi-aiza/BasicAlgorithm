#include <stdio.h>
#include <stdlib.h>
#include <string>

class Vertex{
    public :
        Vertex(std::string name);
        std::string GetName(void);
        std::vector<Vertex*> GetAdjacencyList(void);
        void AddToAdjacentList(Vertex* vertex);   

        std::string name_;
        std::vector<Vertex*> adjacency_list_;
     
};
/* Constructor */
Vertex::Vertex(std::string name){
    name_ = name;
}
/* Accessors */
std::string Vertex::GetName(void){
    return name_;
}
std::vector<Vertex*> Vertex::GetAdjacencyList(void){
    return adjacency_list_;
}
void Vertex::AddToAdjacentList(Vertex* vertex){
    adjacency_list_.push_back(vertex);
}


class Graph{
    public :
        Graph(void){};
        Vertex* GenVertex(std::string name);
        void GenEdge(Vertex* start, Vertex* end);

        std::vector<Vertex*> GetVertices(void);
        size_t GetNumVertices(void);
        void PrintGraph();

        std::vector<Vertex*> vertices_;
}


Vertex* Graph::GenVertex(std::string name){
    Vertex *newVertex = Vertex(name);
    vertices_.push_back(newVertex);
    return newVertex;
}

void Graph::GenEdge(Vertex* start, Vertex* end){
    start.adjacency_list_.push_back(end);
}

std::vector<Vertex*> Graph::GetVertices(void){
    return vertices_
}

size_t Graph::GetNumVertices(void){
    return vertices_.size();
}

void Graph::PrintGraph(void){
    size_t size = this->GetNumVertices();
    for (int i=0; i<size; i++){
        std::cout << vertices_[i].GetName() << '\n';
        std::vector<Vertex*> tmp = vertices_[i].GetAdjacencyList();

        for (int j=0; j<tmp.size(); j++){
            std::cout << tmp[i] << ' ';
        }
        std::cout << '\n';
    }
}