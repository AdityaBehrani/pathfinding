// Copyright 2024 Aditya Behrani
#include "../include/render.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>

#define PI 3.14159265
static double calculateAngle(const sf::Vector2f& pos1, const sf::Vector2f& pos2)
{
    double dx = pos2.x - pos1.x;
    double dy = pos2.y - pos1.y;
    double angle_in_radians = atan2(dy, dx);

    double angle_in_degrees = angle_in_radians * 180.0 / PI;

    if (angle_in_degrees < 0) {
        angle_in_degrees += 360;
    }

    return angle_in_degrees;
}

static double calculateDist(const sf::Vector2f& pos1, const sf::Vector2f& pos2) {
    double dx = abs(pos2.x - pos1.x);
    double dy = abs(pos2.y - pos1.y);

    return sqrt(pow(dx, 2) + pow(dy, 2));
}
static sf::Vector2f getNodeCenter(const sf::Vector2f& pos, float radius) {
    return sf::Vector2f(pos.x + radius, pos.y + radius);
}

static void initNodes(sf::RenderWindow &window, std::vector<sf::CircleShape> &nodes, int N)
{
    int WIDTH = window.getSize().x;
    int HEIGHT = window.getSize().y;

    int COLS = ceil(sqrt(N));
    int BOX_DIM = floor(HEIGHT * 0.9);
    int VERT_SPACE = HEIGHT * (1 - (0.1 + (COLS - 1) * 0.02));

    float radius = floor(VERT_SPACE / (2 * COLS));
    float xStart = floor(((WIDTH - BOX_DIM) / 2));
    float yStart = floor(HEIGHT * 0.05);
    // 2 * r + 2% of height
    float offset = floor(HEIGHT * 0.02 + 2 * radius);

    int curr = 0;
    for (int i = 0; i < N; i++)
    {
        int col = curr % COLS;
        int row = curr / COLS;

        sf::CircleShape newShape(radius, 100);
        newShape.setFillColor(sf::Color::Green);
        newShape.setPosition(xStart + (col * offset), yStart + (row * offset));
        nodes.push_back(newShape);

        curr++;
    }

    return;
}
static std::vector<sf::RectangleShape> calculateEdges(
    const std::vector<sf::CircleShape> &nodes, 
    const std::set<std::pair<int, int>> &adjList
)
{
    auto edgeList = std::vector<sf::RectangleShape>();

    for (const auto& [val1, val2] : adjList) {
        sf::CircleShape node1 = nodes[val1];
        sf::CircleShape node2 = nodes[val2];

        sf::Vector2f center = getNodeCenter(node1.getPosition(), node1.getRadius());
        double length = calculateDist(node1.getPosition(), node2.getPosition());
        double angle = calculateAngle(node1.getPosition(), node2.getPosition());
        
        sf::RectangleShape rect(sf::Vector2f(length, 5));
        rect.setFillColor(sf::Color::Red);
        rect.setRotation(angle);
        rect.setPosition(center.x, center.y);
        edgeList.push_back(rect);
    }
    return edgeList; 
}

static void renderNodes(sf::RenderWindow &window, std::vector<sf::CircleShape> &nodes)
{
    if (window.isOpen())
    {
        for (auto node : nodes)
        {
            window.draw(node);
        }
    }
}

static void renderEdges(sf::RenderWindow &window, std::vector<sf::RectangleShape> &edges)
{
    if (window.isOpen())
    {
        for (auto edge : edges)
        {
            window.draw(edge);
        }
    }
}
