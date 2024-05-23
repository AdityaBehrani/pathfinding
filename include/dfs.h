// Copyright 2024 Aditya Behrani
#ifndef INCLUDE_DFS_H_
#define INCLUDE_DFS_H_

#include <vector>
#include "../include/graph.h"

class DFS {
    public:
        static std::vector<int>* dfs(
            Graph *graph,
            int start,
            int goal);
};
#endif  // INCLUDE_DFS_H_

