// Copyright 2024 Aditya Behrani
#include "../include/graph.h"

Graph::Graph() {
    size = 0;
    adjList = std::unordered_map<int, std::vector<std::pair<int, int>>>();
}

int Graph::build(std::string filename) {
    std::fstream infile(filename);
    if (!infile) {
        std::cerr << "Unable to open "<< filename << ".\n";
        return 1;
    }

    //  add edges to the list
    int N, edges;
    int u, v, w;
    infile >> N >> edges;

    std::string line;
    for (int i = 0; i < edges; i++) {
        infile >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    infile.close();
    return 0;
}

void Graph::addNode(int node) {
    if (adjList.find(node) == adjList.end()) {
        adjList[node] = std::vector<std::pair<int, int>>();
        size++;
    }
}

void Graph::addEdge(int src, int dest, int weight) {
    // ensures both dest and src exist
    addNode(src);
    addNode(dest);

    adjList[src].push_back({dest, weight});
}

int Graph::getSize() {
    return size;
}

std::vector<std::pair<int, int>> Graph::getEdges(int node) {
    if (adjList.find(node) != adjList.end()) {
        return adjList[node];
    }
    
    return std::vector<std::pair<int, int>>();
}
