// Copyright 2024 Aditya Behrani
#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>

class Graph {
    public:
        int size;
        std::unordered_map<int, std::vector<std::pair<int, int>>> adjList;

        void addNode(int node);
        void addEdge(int src, int dest, int weight);
};
#endif  // GRAPH_H
 
