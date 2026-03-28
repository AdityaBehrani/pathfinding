// used as a translation layer between SFML and Eigen
// Copyright 2024 Aditya Behrani
#ifndef INCLUDE_TRANSLATION_H_
#define INCLUDE_TRANSLATION_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include <Eigen/Dense>

class Translation
{
public:
  static std::vector<Eigen::Vector2f> convertToEigen(const std::vector<sf::CircleShape>& nodes)
  static std::vector<Eigen::Vector2f> convertToSFML(const std::vector<sf::CircleShape>& nodes)
};
#endif // INCLUDE_TRANSLATION_H_