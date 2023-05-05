#pragma once
#include "../../engine/object.h"

class Pickup : public Object
{
public:
    Pickup(sf::Vector2f pos,float radius, float moveSpeed);
    void Init() override;
    void Render() override;
    sf::CircleShape& GetSprite() {return sprite;}
    sf::FloatRect GetCollider() const {return sprite.getGlobalBounds();}

    sf::CircleShape sprite;
    float radius;
    float rotateSpeed;
    sf::Vector2f pos;
    sf::Texture tex;
};
