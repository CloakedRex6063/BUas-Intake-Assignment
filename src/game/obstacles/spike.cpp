﻿#include "spike.h"

#pragma region Required

Spike::Spike(sf::Vector2f pos, float radius)
{
    this->pos = pos;
    this->radius = radius;
}

void Spike::Init()
{
    sprite.setFillColor(sf::Color::Blue);
    sprite.setPosition(pos);
    sprite.setOrigin(radius/2.f,radius/2.f);
    sprite.setRadius(radius);
    sprite.setPointCount(3);
}

void Spike::Render()
{
    GetWindow()->draw(sprite);
}

#pragma endregion

#pragma region SpriteProperties

sf::FloatRect Spike::GetCollider() const
{
    sf::FloatRect rect = sprite.getGlobalBounds(); 
    rect.width /= 2.f;
    rect.height /= 2.f;
    rect.left += rect.width/2.f;
    rect.top += rect.height/2.f;
    return rect;
}

#pragma endregion 

