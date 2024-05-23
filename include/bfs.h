// Copyright 2024 Aditya Behrani
#ifndef INCLUDE_BFS_H_
#define INCLUDE_BFS_H_

#include <vector>
#include "../include/graph.h"

class BFS {
    public:
        static std::vector<int>* bfs(
            Graph *graph,
            int start,
            int goal);
};
#endif  // INCLUDE_BFS_H_
