#pragma once
#include "../../engine/object.h"

class Floor : public Object
{
public:
    Floor() = default;
    Floor(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f texMultiplier, sf::Texture* tex);
    sf::Vector2f size;
    sf::Vector2f texMultiplier;
    sf::Vector2f pos;
    sf::Texture* tex{};
    sf::RectangleShape sprite;

    void Init() override;
    void Render() override;

    sf::RectangleShape GetSprite() {return sprite;}
    sf::FloatRect GetCollider() const {return sprite.getGlobalBounds();}
};
