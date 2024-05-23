// Copyright 2024 Aditya Behrani
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include "../include/dijkstra.h"

void DIJKSTRA::get_path_dijkstra(
    std::vector<std::vector<int>>* edgeList,
    int start,
    int end,
    std::vector<std::vector<int>>* weights,
    std::vector<int>* path
) {

    dijkstra(edgeList, start, end, weights, path);
}

bool DIJKSTRA::dijkstra(
    std::vector<std::vector<int>>* edgeList,
    int start,
    int end,
    std::vector<std::vector<int>>* weights,
    std::vector<int>* path
) {
    int N = edgeList->size();
    std::vector<int> parents(N, -1);
    std::vector<int> costVec(N, 1);
    std::vector<bool> visited(N, false);

    std::priority_queue<std::tuple<int, int>> pq;
    pq.push(std::make_tuple(0, start));

    int cost, node;
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        cost = std::get<0>(curr);
        node = std::get<1>(curr);

        if (node == end) {
            std::cout << "Total cost is: " << -cost << '\n';
            // reconstruct path
            while (parents[node] != -1) {
                path->push_back(node);
                node = parents[node];
            }
            path->push_back(start);
            std::reverse(path->begin(), path->end());

            return true;
        }

        visited[node] = true;

        int totCost;
        for (int next : edgeList->at(node)) {
            if (!visited[next]) {
                totCost = cost - weights->at(node).at(next);

                if (totCost > costVec[next] || 1 == costVec[next] ) {
                    pq.push(std::make_tuple(totCost, next));
                    parents[next] = node;
                    costVec[next] = totCost;
                }
            }
        }
    }
    return false;
}
