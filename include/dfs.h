// Copyright 2024 Aditya Behrani
#ifndef DFS_H
#define DFS_H

#include <vector>
#include "../include/graph.h"

class DFS {
    public:
        static std::vector<int>* dfs(
            Graph *graph,
            int start,
            int goal);
};
#endif  // DFS_H

