#pragma once
#include "../../engine/object.h"

class WinPortal : public Object
{
public:
    WinPortal(sf::Vector2f pos, sf::Vector2f size);
    void Init() override;
    void Render() override;
    sf::RectangleShape& GetSprite() {return sprite;}
    sf::FloatRect GetCollider() const {return sprite.getGlobalBounds();}

private:
    sf::RectangleShape sprite;
    sf::Vector2f pos;
    sf::Vector2f size;
};
