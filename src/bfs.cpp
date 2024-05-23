// Copyright 2024 Aditya Behrani 
#include <queue> 
#include <vector> 
#include <iostream> 
#include "../include/bfs.h" 
 
std::vector<int>* BFS::bfs( 
    Graph *graph, 
    int start, 
    int goal 
) { 
    std::vector<int>* path = new std::vector<int>(); 
 
    int N = graph->size; 
    std::vector<int> parents(N, -1); 
    std::vector<bool> visited(N, false); 
    std::queue<int> q; 
 
    q.push(start); 
 
    int curr; 
    while (!q.empty()) { 
        curr = q.front(); 
        q.pop(); 
 
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
                q.push(next); 
                parents[next] = curr; 
            } 
        } 
    } 
    return NULL; 
} 
