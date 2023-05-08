#pragma once
#include "../../engine/object.h"

class FlyPortal final : public Object
{
public:
    FlyPortal(sf::Vector2f pos, sf::Vector2f size, bool bFly, sf::Texture* tex);
    void Init() override;
    void Render() override;
    sf::RectangleShape& GetSprite() {return sprite;}
    sf::FloatRect GetCollider() const {return sprite.getGlobalBounds();}

private:
    sf::RectangleShape sprite;
    sf::Texture* tex = nullptr;
    sf::Vector2f pos;
    sf::Vector2f size;

public:
    bool bFly = false;
};
