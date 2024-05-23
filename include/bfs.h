// Copyright 2024 Aditya Behrani
#ifndef BFS_H
#define BFS_H

#include <vector>

class BFS {
    private:
        static bool bfs(
            std::vector<std::vector<int>>* edgeList,
            std::vector<int>* path);

    public:
        static void get_path_bfs(
            std::vector<std::vector<int>>* edgeList,
            std::vector<int>* path);
};
#endif  // BFS_H
