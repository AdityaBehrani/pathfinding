#ifndef INCLUDE_FORCE_H_
#define INCLUDE_FORCE_H_

#include "graph.h"
#include <vector>
#include <Eigen/Dense>

// Class for Force-Directed Algorithm Based on Fruchterman and Reingold
class Force {
private:
    totalRepulsion();
    totalAttraction();
    totalGravity();
public:
    std::vector<sf::Vector2f> calculateNext();
};

#endif // INCLUDE_FORCE_H_