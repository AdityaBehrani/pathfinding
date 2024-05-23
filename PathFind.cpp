// Copyright 2024 Aditya Behrani
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include "src/graph.cpp"
#include "src/bfs.cpp"
// #include "src/dfs.cpp"
// #include "src/dijkstra.cpp"

std::vector<std::vector<int>>* getEdgeList(
    std::string filename,
    std::vector<std::vector<int>>* weights
) {
    std::fstream infile(filename);
    if (!infile) {
        std::cerr << "Unable to open " << filename << "\n";
        return NULL;
    }

    //  init edgeList
    std::vector<std::vector<int>>* edgeList = \
        new std::vector<std::vector<int>>();

    //  get number of nodes and allocate mem for a list for each node
    int N;
    infile >> N;
    for (int i = 0; i < N; i++) {
        edgeList->push_back(std::vector<int>());
    }

    //  allocate mem for weight matrix
    for (int i = 0; i < N; i++) {
        weights->push_back(std::vector<int>(N, NULL));
    }

    //  add edges to the list
    int edges;
    int u, v, w;
    infile >> edges;

    std::string line;
    for (int i = 0; i < edges; i++) {
        infile >> u >> v >> w;
        //  edges
        edgeList->at(u).push_back(v);
        edgeList->at(v).push_back(u);
        
        //  weigths
        weights->at(v).at(u) = w;
        weights->at(u).at(v) = w;
    }

    infile.close();
    return edgeList;
}

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
        // std::vector<bool>* visited = new std::vector<bool>(g->size, false);
        // DFS::dfs(g, START, GOAL, visited, path);
        // delete visited;
    } else if (selection == 2) {
        path = BFS::bfs(g, START, GOAL);
    } else if (selection == 3) {
        //DIJKSTRA::get_path_dijkstra(edgeList, START, GOAL, weights, path);
    } else {
        std::cout << "Not a valid option\n";
        return 0;
    }

    printPath(path);


    // cleanup
    delete path;
    delete g;

    return 0;
}
