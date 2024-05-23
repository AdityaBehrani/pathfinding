// Copyright 2024 Aditya Behrani
#ifndef INCLUDE_DIJKSTRA_H_
#define INCLUDE_DIJKSTRA_H_

#include <vector>
#include "../include/graph.h"

class DIJKSTRA {
    public:
        static std::vector<int>* dijkstra(
            Graph *graph,
            int start,
            int goal);
};
#endif  // INCLUDE_DIJKSTRA_H_
