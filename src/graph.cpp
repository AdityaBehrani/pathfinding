// Copyright 2024 Aditya Behrani
#include "../include/graph.h"

void Graph::addNode(int node) {
    if (adjList.find(node) == adjList.end()) {
        adjList[node] = std::vector<std::pair<int, int>>();
        this->size++;
    }
}

void Graph::addEdge(int src, int dest, int weight) {
    adjList[src].push_back({dest, weight});
}
