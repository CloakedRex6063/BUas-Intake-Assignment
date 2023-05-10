#pragma once
#include "../../engine/object.h"

class WinPortal : public Object
{
    
#pragma region Required
    
public:
    WinPortal(sf::Vector2f pos, sf::Vector2f size,sf::Texture* tex);
    void Init() override;
    void Render() override;

#pragma endregion 
    
#pragma region SpriteProperties
    
    sf::RectangleShape& GetSprite() {return sprite;}
    sf::FloatRect GetCollider() const {return sprite.getGlobalBounds();}

private:
    sf::RectangleShape sprite;
    sf::Texture* tex;
    sf::Vector2f pos;
    sf::Vector2f size;

#pragma endregion
    
};
