#include "floor.h"

#include <iostream>

Floor::Floor(sf::Vector2f pos, sf::Vector2f size)
{
    this->pos = pos;
    this-> size = size;
}

void Floor::Init()
{
    sprite.setSize(size);
    sprite.setOrigin(0.f,size.y/2.f);
    sprite.setPosition(pos);
    if(!tex.loadFromFile("Assets/Textures/Floor.png"))
    {
        std::cout << "Failed to load Assets/Textures/Floor.png";
    }
    sprite.setTexture(&tex);
}

void Floor::Render()
{
    GetWindow().draw(sprite);
}



