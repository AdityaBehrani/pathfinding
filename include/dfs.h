// Copyright 2024 Aditya Behrani
#ifndef DFS_H
#define DFS_H

#include <vector>

class DFS {
    public:
        static bool dfs(
            Graph *graph,
            int start,
            int goal,
            std::vector<bool>* visited,
            std::vector<int>* path);
};
#endif  // DFS_H
