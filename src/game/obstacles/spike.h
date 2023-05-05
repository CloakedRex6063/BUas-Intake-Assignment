#pragma once
#include "../../engine/object.h"

class Spike : public Object
{
public:
    Spike() {}
    Spike(sf::Vector2f pos, float radius);

    void Init() override;
    void Render() override;

    sf::CircleShape& GetSprite() { return sprite; }
    sf::FloatRect GetCollider() const;

private:
    sf::CircleShape sprite;
    sf::Texture tex;
    sf::Vector2f pos;
    float radius = 0;
};
