#include "pickup.h"

#include <iostream>

Pickup::Pickup(sf::Vector2f pos, float radius, float moveSpeed)
{
    this->pos = pos;
    this->radius = radius;
    this->rotateSpeed = moveSpeed;
}

void Pickup::Init()
{
    sprite.setRadius(radius);
    sprite.setOrigin(radius,radius);
    sprite.setPosition(pos);
    if(!tex.loadFromFile("Assets/Textures/Pickup.png"))
    {
        std::cout << "Failed to load Assets/Textures/Pickup.png";
    }
    sprite.setTexture(&tex);
}

void Pickup::Render()
{
    GetWindow().draw(sprite);
}


