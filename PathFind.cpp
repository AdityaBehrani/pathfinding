// Copyright 2024 Aditya Behrani
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include "src/graph.cpp"
#include "src/bfs.cpp"
#include "src/dfs.cpp"
#include "src/dijkstra.cpp"

int START, GOAL;

Graph* buildGraph(std::string filename) {
    Graph *g = new Graph();

    std::fstream infile(filename);
    if (!infile) {
        std::cerr << "Unable to open " << filename << "\n";
        return NULL;
    }

    int N;
    infile >> N;
    for (int i = 0; i < N; i++) {
        g->addNode(i);
    }

     //  add edges to the list
    int edges;
    int u, v, w;
    infile >> edges;

    std::string line;
    for (int i = 0; i < edges; i++) {
        infile >> u >> v >> w;
        g->addEdge(u, v, w);
        g->addEdge(v, u, w);
    }

    infile.close();
    return g;
}

void promptInputs(
    std::string &filename
) {
    std::cout << "What data file: ";
    std::cin >> filename;

    std::cout << "Starting Node: ";
    std::cin >> START;

    std::cout << "Goal Node: ";
    std::cin >> GOAL;
}

void printPath(
    std::vector<int>* path
) {
    if (path == NULL) {
        std::cout << "No path exists\n";
    } else if (path->size() > 0) {
        for (int i = 0; i < path->size(); i++) {
            std::cout << "Node " << i << ": " << path->at(i) << "\n";
        }
    }
}

int main() {
    std::string filename;
    promptInputs(filename);

    Graph *g = buildGraph(filename);
    // invalid file
    if (g == NULL) {
        return 1;
    }

    int selection;
    std::cout << "Select your Algorithm:\n1: DFS\n2: BFS\n3: Dijkstra's\nSelection: ";
    std::cin >> selection;
    std::cout << "\n";

    std::vector<int>* path = NULL;

    if (selection == 1) {
        path = DFS::dfs(g, START, GOAL);
    } else if (selection == 2) {
        path = BFS::bfs(g, START, GOAL);
    } else if (selection == 3) {
        path = DIJKSTRA::dijkstra(g, START, GOAL);
    } else {
        std::cout << "Not a valid option\n";
        delete path;
        delete g;
        return 0;
    }

    printPath(path);

    // cleanup
    delete path;
    delete g;

    return 0;
}
