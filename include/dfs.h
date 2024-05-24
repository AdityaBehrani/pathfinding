// Copyright 2024 Aditya Behrani
#ifndef INCLUDE_Dfs_H_
#define INCLUDE_Dfs_H_

#include "graph.h"
#include "pathfinder.h"
#include <vector>

class Dfs : public Pathfinder {
public:
  void search(Graph &graph, int start, int goal,
              std::vector<int> &path) const override;
};
#endif // INCLUDE_Dfs_H_
