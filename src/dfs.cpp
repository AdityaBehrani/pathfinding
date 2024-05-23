// Copyright 2024 Aditya Behrani
#include <vector>
#include <stack>
#include "../include/dfs.h"


std::vector<int>* DFS::dfs(
    Graph *graph,
    int start,
    int goal
) {
    std::vector<int>* path = new std::vector<int>();

    int N = graph->size;
    std::vector<int> parents(N, -1);
    std::vector<bool> visited(N, false);
    std::stack<int> s;

    s.push(start);

    int curr;
    while (!s.empty()) {
        curr = s.top();
        s.pop();

        if (curr == goal) {
            // reconstruct path
            while (parents[curr] != -1) {
                path->push_back(curr);
                curr = parents[curr];
            }
            path->push_back(start);
            std::reverse(path->begin(), path->end());

            return path;
        }

        visited[curr] = true;
        for (auto& [next, _] : graph->adjList[curr]) {
            if (!visited[next] && parents[next] == -1) {
                s.push(next);
                parents[next] = curr;
            }
        }
    }
    return NULL;
}
