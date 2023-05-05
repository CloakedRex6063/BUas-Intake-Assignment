#include "sliderBar.h"

#include <iostream>

SliderBar::SliderBar(sf::Vector2f pos, sf::Vector2f size, float outThickness)
{
    this->pos = pos;
    this->size = size;
    this->outThickness = outThickness;
}

void SliderBar::Init()
{
    fillBar.setPosition(pos);
    fillBar.setFillColor(sf::Color::Green);
    outlineBar.setPosition(pos);
    outlineBar.setSize(size);
    outlineBar.setFillColor(sf::Color::Transparent);
    outlineBar.setOutlineThickness(outThickness);
    outlineBar.setOutlineColor(sf::Color::White);
}

void SliderBar::Tick(float deltaTime)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        const auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(GetWindow()));
        if(outlineBar.getGlobalBounds().contains(mousePos))
        {
            const float value = std::min(std::abs(mousePos.x - outlineBar.getPosition().x) / outlineBar.getSize().x,1.f);
            SetSliderValue(value); 
        }
    }
}

void SliderBar::Render()
{
    GetWindow().draw(outlineBar);
    GetWindow().draw(fillBar);
}

void SliderBar::SetSliderValue(float newValue)
{
    fillBar.setSize(sf::Vector2f(newValue * size.x,size.y));
    onValueChanged(newValue);
}
