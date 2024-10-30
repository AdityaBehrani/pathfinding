#include <SFML/Graphics.hpp>
#include "src/render.cpp"
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include "src/graph.cpp"
#include <Eigen/Dense>

int main(int argc, char *argv[])
{
    int FRAMELIMIT = 120;

    Graph g;
    std::string filename = argv[1];

    try
    {
        g = Graph(filename);
    }
    catch (std::runtime_error ex)
    {
        std::cerr << ex.what();
        return 1;
    }

    auto edgeList = g.uniqueEdges();

    auto nodes = std::vector<sf::CircleShape>();

    int WIDTH = 1512;
    int HEIGHT = 982;
    int N = g.size();

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    window.setFramerateLimit(FRAMELIMIT);
    initNodes(window, nodes, N);
    auto edges = calculateEdges(nodes, edgeList);
    std::cout << "Starting Program\n";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        renderEdges(window, edges);
        renderNodes(window, nodes);
        window.display();
        // Updates nodes' position based on Force-Directed
    }

    return 0;
}
