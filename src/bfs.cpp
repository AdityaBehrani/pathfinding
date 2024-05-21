// Copyright 2024 Aditya Behrani
#include <queue>
#include <vector>
#include "../include/bfs.h"

void BFS::get_path_bfs(
    std::vector<std::vector<int>>* edgeList,
    int start,
    int end,
    std::vector<int>* path
) {
    bfs(edgeList, start, end, path);
}

bool BFS::bfs(
    std::vector<std::vector<int>>* edgeList,
    int start,
    int end,
    std::vector<int>* path
) {
    int N = edgeList->size();
    std::vector<int> parents(N, -1);
    std::vector<bool> visited(N, false);

    std::queue<int> q;
    q.push(start);

    int curr;
    while (!q.empty()) {
        curr = q.front();
        q.pop();

        if (curr == end) {
            // reconstruct path
            while (parents[curr] != -1) {
                path->push_back(curr);
                curr = parents[curr];
            }
            path->push_back(start);
            std::reverse(path->begin(), path->end());

            return true;
        }

        visited[curr] = true;

        for (int next : edgeList->at(curr)) {
            if (!visited[next] && parents[next] == -1) {
                q.push(next);
                parents[next] = curr;
            }
        }
    }
    return false;
}
