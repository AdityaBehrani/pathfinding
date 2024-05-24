// Copyright 2024 Aditya Behrani
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include "../include/dijkstra.h"

void Dijkstra::search(
    Graph &graph,
    int start,
    int goal,
    std::vector<int> &path
) const {
    int N = graph.getSize();
    std::vector<int> parents(N, -1);
    std::vector<int> costVec(N, 1);
    std::vector<bool> visited(N, false);
    std::priority_queue<std::tuple<int, int>> pq;

    pq.push(std::make_tuple(0, start));

    int cost, curr;
    while (!pq.empty()) {
        auto pair = pq.top();
        pq.pop();

        cost = std::get<0>(pair);
        curr = std::get<1>(pair);

        if (curr == goal) {
            std::cout << "Total cost is: " << -cost << '\n';
            // reconstruct path
            while (parents[curr] != -1) {
                path.push_back(curr);
                curr = parents[curr];
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
        }

        visited[curr] = true;

        int totalCost;
        for (auto& [next, weight] : graph.getEdges(curr)) {
            if (!visited[next]) {
                totalCost = cost - weight;

                if (totalCost > costVec[next] || 1 == costVec[next]) {
                    pq.push(std::make_tuple(totalCost, next));
                    parents[next] = curr;
                    costVec[next] = totalCost;
                }
            }
        }
    }
}
