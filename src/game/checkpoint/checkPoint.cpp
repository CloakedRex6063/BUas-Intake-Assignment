#include "checkPoint.h"

#pragma region Required

CheckPoint::CheckPoint(sf::Vector2f pos, sf::Vector2f size, sf::Texture* tex)
{
    this->tex = tex;
    this->pos = pos;
    this->size = size;
}

void CheckPoint::Init()
{
    sprite.setSize(size);
    sprite.setOrigin(size/2.f);
    sprite.setPosition(pos);
    sprite.setTexture(tex);
}

void CheckPoint::Render()
{
    GetWindow()->draw(sprite);
}

#pragma endregion 