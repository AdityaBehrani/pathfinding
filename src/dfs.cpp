// Copyright 2024 Aditya Behrani
#include <vector>
#include "../include/dfs.h"

void DFS::get_path_dfs(
    std::vector<std::vector<int>>* edgeList,
    int start,
    int end,
    std::vector<int>* path
) {
    std::vector<bool>* visited = new std::vector<bool>(edgeList->size(), false);
    dfs(edgeList, start, end, visited, path);

    // cleanup
    delete visited;
}

bool DFS::dfs(
    std::vector<std::vector<int>>* edgeList,
    int start,
    int end,
    std::vector<bool>* visited,
    std::vector<int>* path
) {
    (*visited)[start] = true;
    path->push_back(start);

    if (start == end) {
        return true;
    }

    for (int neighbor : edgeList->at(start)) {
        if (!(*visited)[neighbor]) {
            if (dfs(edgeList, neighbor, end, visited, path)) {
                return true;
            }
        }
    }

    path->pop_back();
    return false;
}
