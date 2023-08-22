#pragma once

#include "graph.h"
#include <map>

void BFS(Vertex* start,
    std::map<Vertex*, unsigned int> &distance);
void DFS(Vertex* vertex, unsigned int &timestamp,
    std::map<Vertex*, unsigned int> &discovery_time,
    std::map<Vertex*, unsigned int> &finishing_time);
