#include "winPortal.h"

WinPortal::WinPortal(sf::Vector2f pos, sf::Vector2f size, sf::Texture* tex)
{
    this->tex = tex;
    this->pos = pos;
    this->size = size;
}

void WinPortal::Init()
{
    sprite.setSize(size);
    sprite.setOrigin(size/2.f);
    sprite.setPosition(pos);
    sprite.setTexture(tex);
}

void WinPortal::Render()
{
    GetWindow().draw(sprite);
}

