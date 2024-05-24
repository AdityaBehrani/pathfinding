// Copyright 2024 Aditya Behrani
#include "include/algorithm.h"
#include "include/pathfinder.h"
#include "src/bfs.cpp"
#include "src/dfs.cpp"
#include "src/dijkstra.cpp"
#include "src/graph.cpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <vector>

void printPath(std::vector<int> &path) {
  if (path.size() == 0) {
    std::cout << "No path exists\n";
  } else if (path.size() > 0) {
    for (int i = 0; i < path.size(); i++) {
      std::cout << "Node " << i << ": " << path.at(i) << "\n";
    }
  }
}

int main(int argc, char *argv[]) {
  std::string filename = argv[1];
  int start = std::stoi(argv[2]), goal = std::stoi(argv[3]);
  int selection = std::stoi(argv[4]);

  Graph g = Graph();
  int res = g.build(filename);
  if (res != 0) {
    return 1;
  }

  auto path = std::vector<int>();
  std::unique_ptr<Pathfinder> pathfinder;

  switch (static_cast<Algorithm>(selection)) {
  case Algorithm::Dfs:
    pathfinder = std::make_unique<Dfs>();
    break;
  case Algorithm::Bfs:
    pathfinder = std::make_unique<Bfs>();
    break;
  case Algorithm::Dijkstra:
    pathfinder = std::make_unique<Dijkstra>();
    break;
  default:
    std::cerr << "Invalid selection\n";
    return 1;
  }

  pathfinder->search(g, start, goal, path);

  printPath(path);
  return 0;
}
