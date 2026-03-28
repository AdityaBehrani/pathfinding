#ifndef INCLUDE_FORCE_H_
#define INCLUDE_FORCE_H_

#include "graph.h"
#include <vector>
#include <unordered_map>
#include <Eigen/Dense>

// Class for Force-Directed Algorithm Based on Fruchterman and Reingold
class Force {
private:    
    float _cooling = 1;
    float _gravityForce;
    float _idealLength;
    float _previousMaxForce;
    Eigen::Vector2f _dims;

    void calculateIdealLength(int N);
    Eigen::Vector2f totalRepulsion(int node, std::vector<Eigen::Vector2f> nodes);
    Eigen::Vector2f totalAttraction(int node, std::vector<Eigen::Vector2f> nodes, std::unordered_map<int, std::vector<std::pair<int, int>>>);
    Eigen::Vector2f totalGravity(Eigen::Vector2f node, Eigen::Vector2f center);

public:
    void updateCooling(float mult);
    float getPrevMaxForce();
    Force(float g, float cooling, Eigen::Vector2f _dims);
    std::vector<Eigen::Vector2f> calculateNext(std::vector<Eigen::Vector2f> nodes, std::set<std::pair<int, int>> edges);
};

#endif // INCLUDE_FORCE_H_