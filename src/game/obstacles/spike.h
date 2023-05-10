#pragma once
#include "../../engine/object.h"

class Spike final : public Object
{
#pragma region Required
    
public:
    Spike(sf::Vector2f pos, float radius);
    void Init() override;
    void Render() override;

#pragma endregion 

#pragma region Sprite Properties
    
private:
    sf::CircleShape sprite;
    sf::Texture tex;
    sf::Vector2f pos;
    float radius = 0;

public:
    sf::CircleShape& GetSprite() { return sprite; }
    sf::FloatRect GetCollider() const;

#pragma endregion 
};
