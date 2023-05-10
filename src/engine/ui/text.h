#pragma once

#include <SFML/Graphics/Text.hpp>
#include "../../engine/object.h"

class Text final : public Object
{
    
#pragma region Required
public:
    Text(const sf::Vector2f& pos, const sf::Font& font, int size, const std::string& newText, const sf::Color& textColor = sf::Color::White);
    void Init() override;
    void Render() override;

    bool bFixed = true;

#pragma endregion

#pragma region TextProperties
    
private:
    sf::CircleShape shape;
    
    std::string newText;
    sf::Font font;
    sf::Text text;
    
    sf::Vector2f pos;
    int size;
    sf::Color textColor;
    
public:
    void SetText(const std::string& newText);
    sf::Text GetText() {return text;}

#pragma endregion
    
};
