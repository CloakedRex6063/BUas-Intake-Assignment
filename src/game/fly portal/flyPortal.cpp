#include "flyPortal.h"

#pragma region Required

FlyPortal::FlyPortal(sf::Vector2f pos, sf::Vector2f size, bool bFly, sf::Texture* tex)
{
    this->tex = tex;
    this->pos = pos;
    this->size = size;
    this->bFly = bFly;
}

void FlyPortal::Init()
{
    sprite.setSize(size);
    sprite.setOrigin(size/2.f);
    sprite.setPosition(pos);
    sprite.setTexture(tex);
}

void FlyPortal::Render()
{
    GetWindow()->draw(sprite);
}

#pragma endregion 
