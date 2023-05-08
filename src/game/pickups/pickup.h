#pragma once
#include "../../engine/object.h"

class Pickup : public Object
{
public:
    Pickup(sf::Vector2f pos,float radius,sf::Texture* tex);
    void Init() override;
    void Render() override;
    sf::CircleShape& GetSprite() {return sprite;}
    sf::FloatRect GetCollider() const {return sprite.getGlobalBounds();}

    sf::CircleShape sprite;
    float radius;
    sf::Vector2f pos;
    sf::Texture* tex;
};
