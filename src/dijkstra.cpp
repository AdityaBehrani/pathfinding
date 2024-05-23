// Copyright 2024 Aditya Behrani 
#include <iostream> 
#include <queue> 
#include <vector> 
#include <cmath> 
#include "../include/dijkstra.h" 
 
std::vector<int>* DIJKSTRA::dijkstra( 
    Graph *graph, 
    int start, 
    int goal 
) { 
    std::vector<int>* path = new std::vector<int>(); 
 
    int N = graph->size; 
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
                path->push_back(curr); 
                curr = parents[curr]; 
            } 
            path->push_back(start); 
            std::reverse(path->begin(), path->end()); 
 
            return path; 
        } 
 
        visited[curr] = true; 
 
        int totCost; 
        for (auto& [next, weight] : graph->adjList[curr]) { 
            if (!visited[next]) { 
                totCost = cost - weight; 
 
                if (totCost > costVec[next] || 1 == costVec[next] ) { 
                    pq.push(std::make_tuple(totCost, next)); 
                    parents[next] = curr; 
                    costVec[next] = totCost; 
                } 
            } 
        } 
    } 
    return NULL; 
} 
