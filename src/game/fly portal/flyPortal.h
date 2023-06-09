#pragma once
#include "../../engine/object.h"

class FlyPortal final : public Object
{
#pragma region Required
    
public:
    FlyPortal(sf::Vector2f pos, sf::Vector2f size, bool bFly, sf::Texture* tex);
    void Init() override;
    void Render() override;

#pragma endregion 

#pragma region Sprite Properties
    
    sf::RectangleShape& GetSprite() {return sprite;}
    sf::FloatRect GetCollider() const {return sprite.getGlobalBounds();}

private:
    sf::RectangleShape sprite;
    sf::Texture* tex = nullptr;
    sf::Vector2f pos;
    sf::Vector2f size;

#pragma endregion 

#pragma region Modifiers
    
public:
    bool bFly = false;

#pragma endregion 
};
