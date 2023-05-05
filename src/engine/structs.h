#pragma once
#include <SFML/System/Vector2.hpp>

struct ObstacleData
{
    sf::Vector2f position;
    float radius;
};

struct FloorData
{
    sf::Vector2f position;
    sf::Vector2f size;
};

