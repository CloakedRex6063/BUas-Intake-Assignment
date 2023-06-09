﻿#include "text.h"

#pragma region Required

Text::Text(const sf::Vector2f& pos, const sf::Font& font, int size, const std::string& newText,const sf::Color& textColor)
{
    this->font = font;
    this->pos = pos;
    this->size = size;
    this->newText = newText;
    this->textColor = textColor;
}

void Text::Init()
{
    text.setFont(font);
    text.setFillColor(textColor);
    text.setCharacterSize(size);
    text.setString(newText);
    const sf::FloatRect rc = text.getLocalBounds();
    text.setOrigin(rc.width/2, rc.height/2);
    text.setPosition(pos);
}

void Text::Render()
{
    GetWindow()->draw(text);
}

#pragma endregion 

#pragma region TextProperties

void Text::SetText(const std::string& newText)
{
    text.setString(newText);
}

#pragma endregion 
