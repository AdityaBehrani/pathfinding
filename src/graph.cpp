#include "../include/graph.h"

// Helper function to find and remove an edge from the adjacency list
void removeEdgeFromAdjList(std::vector<std::pair<int, int>>& neighbors, int node) {
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        if (it->first == node) {
            neighbors.erase(it);
            return;
        }
    }
}

void Graph::addNode(int node) {
    if (adjList.find(node) == adjList.end()) {
        adjList[node] = std::vector<std::pair<int, int>>();
    }
}

void Graph::removeNode(int node) {
    adjList.erase(node);
    for (auto& [key, neighbors] : adjList) {
        removeEdgeFromAdjList(neighbors, node);
    }
}

void Graph::addEdge(int src, int dest, int weight) {
    adjList[src].push_back({dest, weight});
}

void Graph::removeEdge(int src, int dest) {
    if (adjList.find(src) != adjList.end()) {
        removeEdgeFromAdjList(adjList[src], dest);
    }
}
