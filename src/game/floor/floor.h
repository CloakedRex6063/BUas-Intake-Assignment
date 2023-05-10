#pragma once
#include "../../engine/object.h"

class Floor final : public Object
{
#pragma region Required
    
public:
    Floor(sf::Vector2f pos, sf::Vector2f size, sf::Vector2i texMultiplier, sf::Texture* tex);
    void Init() override;
    void Render() override;

#pragma endregion 

#pragma region FloorProperties
    
    sf::Vector2f size;
    sf::Vector2i texMultiplier;
    sf::Vector2f pos;
    sf::Texture* tex{};
    sf::RectangleShape sprite;

    sf::RectangleShape GetSprite() {return sprite;}
    sf::FloatRect GetCollider() const {return sprite.getGlobalBounds();}

#pragma endregion 
};
