// Copyright 2024 Aditya Behrani
#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_

#include <unordered_map>
#include <utility>
#include <vector>

class Graph {
private:
  int size;
  std::unordered_map<int, std::vector<std::pair<int, int>>> adjList;

public:
  Graph();
  int build(std::string filename);
  void addNode(int node);
  void addEdge(int src, int dest, int weight);
  int getSize();
  std::vector<std::pair<int, int>> getEdges(int node);
};
#endif // INCLUDE_GRAPH_H_
