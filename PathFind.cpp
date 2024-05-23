// Copyright 2024 Aditya Behrani
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include "src/bfs.cpp"
#include "src/dfs.cpp"
#include "src/dijkstra.cpp"

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

void promptInputs(
    std::string &filename
) {
    std::cout << "What data file: ";
    std::cin >> filename;

    std::cout << "STARTing Node: ";
    std::cin >> START;

    std::cout << "Goal Node: ";
    std::cin >> GOAL;
}

void printPath(
    std::vector<int>* path
) {
    if (path->size() > 0) {
        for (int i = 0; i < path->size(); i++) {
            std::cout << "Node " << i << ": " << path->at(i) << "\n";
        }
    }
}

int main() {
    std::string filename;
    promptInputs(filename);

    std::vector<std::vector<int>>* weights = new std::vector<std::vector<int>>();
    std::vector<std::vector<int>>* edgeList = getEdgeList(filename, weights);

    // invalid file
    if (edgeList == NULL) {
        delete weights;
        return 1;
    }

    int selection;
    std::cout << "Select your Algorithm:\n1: DFS\n2: BFS\n3: Diijkstra's\nSelection: ";
    std::cin >> selection;
    std::cout << "\n";

    std::vector<int>* path = new std::vector<int>();
    if (selection == 1) {
        DFS::get_path_dfs(edgeList, START, GOAL, path);
    } else if (selection == 2) {
        BFS::get_path_bfs(edgeList, START, GOAL, path);
    } else if (selection == 3) {
        DIJKSTRA::get_path_dijkstra(edgeList, START, GOAL, weights, path);
    } else {
        std::cout << "Not a valid option\n";
        return 0;
    }

    printPath(path);


    // cleanup
    delete edgeList;
    delete path;
    delete weights;

    return 0;
}
