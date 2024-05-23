// Copyright 2024 Aditya Behrani
#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_

#include <unordered_map>
#include <vector>
#include <utility>

class Graph {
    public:
        int size;
        std::unordered_map<int, std::vector<std::pair<int, int>>> adjList;

        void addNode(int node);
        void addEdge(int src, int dest, int weight);
};
#endif  // INCLUDE_GRAPH_H_
