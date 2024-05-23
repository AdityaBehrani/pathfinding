// Copyright 2024 Aditya Behrani
#include <vector>
#include "../include/dfs.h"

bool DFS::dfs(
    Graph *g,
    int start,
    int goal,
    std::vector<bool>* visited,
    std::vector<int>* path
) {
    (*visited)[start] = true;
    path->push_back(start);

    if (start == goal) {
        return true;
    }

    for (auto& [next, _] : g->adjList[start]) {

        if (!(*visited)[next]) {
            if (dfs(g, next, goal, visited, path)) {
                return true;
            }
        }
    }

    path->pop_back();
    return false;
}
