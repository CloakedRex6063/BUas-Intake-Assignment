#include "pickup.h"

#pragma region Required

Pickup::Pickup(sf::Vector2f pos, float radius, sf::Texture* tex)
{
    this->tex = tex;
    this->pos = pos;
    this->radius = radius;
}

void Pickup::Init()
{
    sprite.setRadius(radius);
    sprite.setOrigin(radius,radius);
    sprite.setPosition(pos);
    sprite.setTexture(tex);
}

void Pickup::Render()
{
    GetWindow()->draw(sprite);
}

#pragma endregion 


