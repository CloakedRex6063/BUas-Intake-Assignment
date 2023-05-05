#pragma once
#include <SFML/Graphics/Text.hpp>

#include "../../engine/object.h"

class Text : public Object
{
public:
    void Init() override;
    void Render() override;

    bool bFixed = true;
    Text(const sf::Vector2f& pos, sf::Font font, unsigned size, const std::string& newText, const sf::Color& textColor = sf::Color::White);
    void SetText(const std::string& newText);
    sf::Text GetText() {return text;}
    
private:
    sf::Text text;
    sf::CircleShape shape;
    std::string newText;
    sf::Font font;
    sf::Vector2f pos;
    sf::Color textColor;
    unsigned size;
};
