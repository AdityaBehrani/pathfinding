#ifndef INCLUDE_RENDER_H_
#define INCLUDE_RENDER_H_

#include <SFML/Graphics.hpp>
#include <set>

// Helper methods for Rendering graphs
class Render
{
private:
    // in degrees
    static double calculateAngle(const sf::Vector2f& pos1, const sf::Vector2f& pos2);
    static double calculateDist(const sf::Vector2f& pos1, const sf::Vector2f& pos2);
    static sf::Vector2f getNodeCenter(const sf::Vector2f& pos, float radius);

public:
    static void initNodes(const sf::RenderWindow &window,
                          std::vector<sf::CircleShape> &, int);

    static std::vector<sf::RectangleShape>
    calculateEdges(const std::vector<sf::CircleShape> & nodes,
                   const std::set<std::pair<int, int>> &adjList);

    static void renderNodes(const sf::RenderWindow &,
                            const std::vector<sf::CircleShape> &);

    static void renderEdges(const sf::RenderWindow &window,
                            const std::vector<sf::RectangleShape> &edges);
};

#endif // INCLUDE_RENDER_H_
