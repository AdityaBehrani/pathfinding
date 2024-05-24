// Copyright 2024 Aditya Behrani
#ifndef INCLUDE_Bfs_H_
#define INCLUDE_Bfs_H_

#include "graph.h"
#include "pathfinder.h"
#include <vector>

class Bfs : public Pathfinder {
public:
  void search(Graph &graph, int start, int goal,
              std::vector<int> &path) const override;
};
#endif // INCLUDE_Bfs_H_
