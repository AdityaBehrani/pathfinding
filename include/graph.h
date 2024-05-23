// Copyright 2024 Aditya Behrani
#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>

class Graph {
    private:
        std::unordered_map<int, std::vector<std::pair<int, int>>> adjList;
    
    public:
        void addNode(int node);
        void removeNode(int node);
        void addEdge(int src, int dest, int weight);
        void removeEdge(int src, int dest);
};
#endif  // GRAPH_H
