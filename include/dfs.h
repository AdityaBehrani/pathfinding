// Copyright 2024 Aditya Behrani
#ifndef DFS_H
#define DFS_H

#include <vector>

class DFS {
    private:
        static bool dfs(
            std::vector<std::vector<int>>* edgeList,
            int start,
            int end,
            std::vector<bool>* visited,
            std::vector<int>* path);

    public:
        static void get_path_dfs(
            std::vector<std::vector<int>>* edgeList,
            int start,
            int end,
            std::vector<int>* path);
};
#endif  // DFS_H
