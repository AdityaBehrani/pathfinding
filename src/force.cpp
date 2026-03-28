// Copyright 2024 Aditya Behrani
#include "../include/force.h"
#include <cmath>
#include <queue>
#include <vector>
#include <cmath>

Force::Force(float g, Eigen::Vector2f _dims)
{
    _gravityForce = g;
    _dims = dims;
}

void Force::calculateIdealLength(int N)
{
   _idealLength = sqrt(_dims.x() * _dims.y() / N);
}

void updateCooling(float mult) {
    _cooling *= mult;
}
float getPrevMaxForce() {
    return _previousMaxForce;
}
Eigen::Vector2f Force::totalGravity(Eigen::Vector2f node, Eigen::Vector2f center)
{
    Eigen::Vector2f gravityVector = _gravityForce * (center - node);
    return gravityVector;
}

Eigen::Vector2f Force::totalRepulsion(int node, std::vector<Eigen::Vector2f> nodes)
{
    Eigen::Vector2f totalRep(0.f, 0.f);
    Eigen::Vector2f unitVector;
    Eigen::Vector2f forceVector;

    float idealLengthSquared = pow(_idealLength, 2);

    for (auto neighbor : nodes) {
        float magnitude = (nodes[node] - neighbor).norm();
        unitVector = (nodes[node] - neighbor).normalized();
        forceVector = unitVector * (idealLengthSquared / magnitude);

        totalRep += forceVector;
    }

    return totalRep;
}

    Eigen::Vector2f totalAttraction(int node, std::vector<Eigen::Vector2f> nodes, std::unordered_map<int, std::vector<std::pair<int, int>>> adjList);
{
    Eigen::Vector2f totalAttr(0.f, 0.f);
    Eigen::Vector2f unitVector;
    Eigen::Vector2f forceVector;

    for (auto &[neighbor, _] : adjList[node]) {
        float magnitude = (nodes[node] - neighbor).norm();

        unitVector = (neighbor - nodes[node]).normalized();
        forceVector = unitVector * (pow(magnitude, 2) / _idealLength);

        totalAttr += forceVector;
    }

    return totalAttr;
}