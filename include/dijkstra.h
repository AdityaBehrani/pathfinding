// Copyright 2024 Aditya Behrani
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include "../include/graph.h"

class DIJKSTRA {
    public:
        static std::vector<int>* dijkstra(
            Graph *graph,
            int start,
            int goal);
};
#endif  // DIJKSTRA_H