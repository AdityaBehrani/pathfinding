// Copyright 2024 Aditya Behrani
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

class DIJKSTRA {
    private:
        static bool dijkstra(
            std::vector<std::vector<int>>* edgeList,
            std::vector<std::vector<int>>* weights,
            std::vector<int>* path);

    public:
        static void get_path_dijkstra(
            std::vector<std::vector<int>>* edgeList,
            std::vector<std::vector<int>>* weights,
            std::vector<int>* path);
};
#endif  // DIJKSTRA_H