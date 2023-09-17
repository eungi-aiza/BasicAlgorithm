#include "graph.h"
#include "search.h"
#include <cstdlib>
#include <iostream>

void ShowcaseGraph() {
  // generate graph instance that manages vertices and edges
  Graph graph;

  // generate vertices
  Vertex* vertex_u = graph.GenVertex("u");
  Vertex* vertex_v = graph.GenVertex("v");
  Vertex* vertex_w = graph.GenVertex("w");
  Vertex* vertex_x = graph.GenVertex("x");
  Vertex* vertex_y = graph.GenVertex("y");
  Vertex* vertex_z = graph.GenVertex("z");

  // generate edges
  graph.GenEdge(vertex_u, vertex_v);
  graph.GenEdge(vertex_u, vertex_x);
  graph.GenEdge(vertex_v, vertex_y);
  graph.GenEdge(vertex_w, vertex_y);
  graph.GenEdge(vertex_w, vertex_z);
  graph.GenEdge(vertex_x, vertex_v);
  graph.GenEdge(vertex_y, vertex_x);
  graph.GenEdge(vertex_z, vertex_z);

  // print all vertices and its their adjacency lists
  graph.PrintGraph();
}

void ShowcaseBFS() {
  // generate graph instance that manages vertices and edges
  Graph graph;

  // generate vertices
  Vertex* vertex_r = graph.GenVertex("r");
  Vertex* vertex_s = graph.GenVertex("s");
  Vertex* vertex_t = graph.GenVertex("t");
  Vertex* vertex_u = graph.GenVertex("u");
  Vertex* vertex_v = graph.GenVertex("v");
  Vertex* vertex_w = graph.GenVertex("w");
  Vertex* vertex_x = graph.GenVertex("x");
  Vertex* vertex_y = graph.GenVertex("y");

  // generate edges
  graph.GenEdge(vertex_r, vertex_s); graph.GenEdge(vertex_s, vertex_r);
  graph.GenEdge(vertex_r, vertex_v); graph.GenEdge(vertex_v, vertex_r);
  graph.GenEdge(vertex_s, vertex_w); graph.GenEdge(vertex_w, vertex_s);
  graph.GenEdge(vertex_t, vertex_w); graph.GenEdge(vertex_w, vertex_t);
  graph.GenEdge(vertex_t, vertex_x); graph.GenEdge(vertex_x, vertex_t);
  graph.GenEdge(vertex_t, vertex_u); graph.GenEdge(vertex_u, vertex_t);
  graph.GenEdge(vertex_u, vertex_x); graph.GenEdge(vertex_x, vertex_u);
  graph.GenEdge(vertex_u, vertex_y); graph.GenEdge(vertex_y, vertex_u);
  graph.GenEdge(vertex_w, vertex_x); graph.GenEdge(vertex_x, vertex_w);
  graph.GenEdge(vertex_x, vertex_y); graph.GenEdge(vertex_y, vertex_x);

  // print all vertices and its their adjacency lists
  graph.PrintGraph();

  // do breadth-first search
  {
    // container that stores distance for each vertex
    std::map<Vertex*, unsigned int> distance;

    // compute distance from vertex_s
    BFS(vertex_s, distance);

    // print computed distance
    std::cout << "=============== BFS Result ===============" << std::endl;
    for (auto vertex : graph.GetVertices()) {
      std::cout << "Vertex " << vertex->GetName() << ", ";
      std::cout << "Distance: " << distance[vertex] << std::endl;
    }
  }
}

void ShowcaseDFS() {
  // generate graph instance that manages vertices and edges
  Graph graph;

  // generate vertices
  Vertex* vertex_u = graph.GenVertex("u");
  Vertex* vertex_v = graph.GenVertex("v");
  Vertex* vertex_w = graph.GenVertex("w");
  Vertex* vertex_x = graph.GenVertex("x");
  Vertex* vertex_y = graph.GenVertex("y");
  Vertex* vertex_z = graph.GenVertex("z");

  // generate edges
  graph.GenEdge(vertex_u, vertex_v);
  graph.GenEdge(vertex_u, vertex_x);
  graph.GenEdge(vertex_v, vertex_y);
  graph.GenEdge(vertex_w, vertex_y);
  graph.GenEdge(vertex_w, vertex_z);
  graph.GenEdge(vertex_x, vertex_v);
  graph.GenEdge(vertex_y, vertex_x);
  graph.GenEdge(vertex_z, vertex_z);

  // print all vertices and its their adjacency lists
  graph.PrintGraph();

  // do depth-first search
  {
    // initial timestamp starts from zero
    unsigned int timestamp = 0;

    // container that stores discovery time of each vertex
    std::map<Vertex*, unsigned int> discovery_time;

    // container that stores finishing time of each vertex
    std::map<Vertex*, unsigned int> finishing_time;

    // do DFS for all vertices in the graph
    for (auto vertex : graph.GetVertices()) {
      // call DFS only when the vertex is not discovered once
      if (discovery_time.find(vertex) == discovery_time.end()) {
        DFS(vertex, timestamp, discovery_time, finishing_time);
      }
    }

    // print discovery time and finishing time of vertices
    std::cout << "=============== DFS Result ===============" << std::endl;
    for (auto vertex : graph.GetVertices()) {
      std::cout << "Vertex " << vertex->GetName() << ", ";
      std::cout << "Discovery time: " << discovery_time[vertex] << ", ";
      std::cout << "Finishing time: " << finishing_time[vertex] << std::endl;
    }
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " [selector]" << std::endl;
    std::cout << "Selector 0: Showcase graph" << std::endl;
    std::cout << "Selector 1: Showcase Breadth-First Search" << std::endl;
    std::cout << "Selector 2: Showcase Depth-First Search" << std::endl;
    return EXIT_FAILURE;
  }

  int selector = atoi(argv[1]);
  switch (selector) {
  case 0: ShowcaseGraph(); break;
  case 1: ShowcaseBFS(); break;
  case 2: ShowcaseDFS(); break;
  }

  return EXIT_SUCCESS;
}
