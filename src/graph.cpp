// Copyright 2024 Aditya Behrani
#include "../include/graph.h"
#include <fstream>
#include <set>
#include <stdexcept>

Graph::Graph()
{
  _size = 0;
  _adjList = std::unordered_map<int, std::vector<std::pair<int, int>>>();
}

Graph::Graph(std::string filename)
{
  _size = 0;
  _adjList = std::unordered_map<int, std::vector<std::pair<int, int>>>();

  std::fstream infile(filename);
  if (!infile)
  {
    throw std::runtime_error("Error: File cannot be opened.\n");
  }

  //  add edges to the list
  int N, edges;
  int u, v, w;
  infile >> N >> edges;

  std::string line;
  for (int i = 0; i < edges; i++)
  {
    infile >> u >> v >> w;
    addEdge(u, v, w);
    addEdge(v, u, w);
  }

  infile.close();
}

void Graph::addNode(int node)
{
  if (_adjList.find(node) == _adjList.end())
  {
    _adjList[node] = std::vector<std::pair<int, int>>();
    _size++;
  }
}

void Graph::addEdge(int src, int dest, int weight)
{
  // ensures both dest and src exist
  addNode(src);
  addNode(dest);

  _adjList[src].push_back({dest, weight});
}

int Graph::size() { return _size; }

std::unordered_map<int, std::vector<std::pair<int, int>>> Graph::edgeList() { return _adjList; }

std::vector<std::pair<int, int>> Graph::edges(int node)
{
  if (_adjList.find(node) != _adjList.end())
  {
    return _adjList[node];
  }

  return std::vector<std::pair<int, int>>();
}


std::set<std::pair<int, int>> Graph::uniqueEdges() {
    std::set<std::pair<int, int>> edges;

    for (const auto& [node, neighbors] : _adjList) {
        for (const auto& [neighbor, _] : neighbors) {
            std::pair<int, int> edge = std::minmax(node, neighbor);
            edges.insert(edge);
        }
    }

    return edges;
}