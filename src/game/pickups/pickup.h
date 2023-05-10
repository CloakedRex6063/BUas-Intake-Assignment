#pragma once
#include "../../engine/object.h"

class Pickup final : public Object
{
    
#pragma region Required
    
public:
    Pickup(sf::Vector2f pos,float radius,sf::Texture* tex);
    void Init() override;
    void Render() override;

#pragma endregion 

#pragma region SpriteProperties
    
private:
    sf::CircleShape sprite;
    float radius;
    sf::Vector2f pos;
    sf::Texture* tex;

public:
    sf::CircleShape& GetSprite() {return sprite;}
    sf::FloatRect GetCollider() const {return sprite.getGlobalBounds();}

#pragma endregion
    
};
