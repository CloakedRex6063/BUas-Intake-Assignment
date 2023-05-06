#include "floor.h"

#include <iostream>

Floor::Floor(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f texMultiplier, sf::Texture* tex)
{
    this->pos = pos;
    this->size = size;
    this->texMultiplier = texMultiplier;
    this->tex = tex;
}

void Floor::Init()
{
    sprite.setSize(size);
    sprite.setOrigin(0.f,size.y/2.f);
    sprite.setPosition(pos);
    tex->setRepeated(true);
    sprite.setTexture(tex);
    sprite.setTextureRect(sf::IntRect(0,0,texMultiplier.x,texMultiplier.y));
}

void Floor::Render()
{
    GetWindow().draw(sprite);
}



