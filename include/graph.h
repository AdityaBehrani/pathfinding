// Copyright 2024 Aditya Behrani
#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_

#include <unordered_map>
#include <utility>
#include <set>
#include <vector>

class Graph
{
private:
  int _size;
  std::unordered_map<int, std::vector<std::pair<int, int>>> _adjList;

public:
  Graph();
  Graph(std::string filename);
  void addNode(int node);
  void addEdge(int src, int dest, int weight);
  int size();
  std::unordered_map<int, std::vector<std::pair<int, int>>> edgeList();
  std::vector<std::pair<int, int>> edges(int node);
  std::set<std::pair<int, int>> uniqueEdges();
};
#endif // INCLUDE_GRAPH_H_
