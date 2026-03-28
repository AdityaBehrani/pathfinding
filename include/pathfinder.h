#ifndef INCLUDE_PATHFINDER_H_
#define INCLUDE_PATHFINDER_H_

#include "graph.h"
#include <vector>

// Interface for algorithms
class Pathfinder {
public:
  virtual void
  search(Graph &g, int start, int goal,
         std::vector<int> &path) const = 0; // Pure virtual function

  virtual ~Pathfinder(){}; // Virtual destructor
};

#endif // INCLUDE_PATHFINDER_H_
