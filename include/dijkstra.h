// Copyright 2024 Aditya Behrani
#ifndef INCLUDE_Dijkstra_H_
#define INCLUDE_Dijkstra_H_

#include "graph.h"
#include "pathfinder.h"
#include <vector>

class Dijkstra : public Pathfinder {
public:
  void search(Graph &graph, int start, int goal,
              std::vector<int> &path) const override;
};
#endif // INCLUDE_Dijkstra_H_
