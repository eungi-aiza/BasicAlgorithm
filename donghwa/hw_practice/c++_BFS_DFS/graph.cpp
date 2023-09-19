#include <iostream>
#include "graph.h"

void Vertex::AddToAdjacentList(Vertex* vertex) {
  // TODO: Add 'vertex' to adjacency list (class member)
  adjacency_list_.push_back(vertex);
}

Graph::~Graph() { // Destructor
  for (auto vertex : vertices_)
    delete vertex;
  vertices_.clear();
}

Vertex* Graph::GenVertex(std::string name) {
  Vertex* vertex = new Vertex(name);
  vertices_.push_back(vertex);
  return vertex;
}

void Graph::GenEdge(Vertex* start, Vertex* end) {
  // TODO: Add 'end' vertex to adjacency list of 'start' vertex
  // Hint: Call member function of 'start' vertex
  start->AddToAdjacentList(end);
}

void Graph::PrintGraph() {
  std::cout << "============== Defined Graph ==============" << std::endl;
  for (auto vertex : vertices_) {
    std::cout << "Vertex " << vertex->GetName() << ", Adjacency List: ";

    bool is_first = true;
    for (auto adjacent : vertex->GetAdjacencyList()) {
      if (is_first == false) {
        std::cout << ", ";
      }
      std::cout << "Vertex " << adjacent->GetName();
      is_first = false;
    }
    std::cout << std::endl;
  }
}
