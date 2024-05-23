// Copyright 2024 Aditya Behrani
#ifndef BFS_H
#define BFS_H

#include <vector>
#include "../include/graph.h"

class BFS {
    public:
        static std::vector<int>* bfs(
            Graph *graph,
            int start,
            int goal);
};
#endif  // BFS_H
