// Copyright 2024 Aditya Behrani
#include "../include/translation.h"
#include <Eigen/Dense>

std::vector<Eigen::Vector2f> convertToEigen(const std::vector<sf::CircleShape>& nodes) {
    std::vector<Eigen::Vector2f> positions;

    for (const auto& node : nodes) {
        sf::Vector2f pos = node.getPosition();
        positions.emplace_back(pos.x, pos.y);
    }

    return positions;
}

std::vector<sf::Vector2f> convertToSFML(const std::vector<Eigen::Vector2f>& eigenVectors) {
    std::vector<sf::Vector2f> sfmlVectors;
    sfmlVectors.reserve(eigenVectors.size()); // Reserve space to improve efficiency

    for (const auto& vec : eigenVectors) {
        sfmlVectors.emplace_back(vec.x(), vec.y());
    }

    return sfmlVectors;
}