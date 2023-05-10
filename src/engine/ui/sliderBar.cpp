#include "sliderBar.h"

#pragma region Required

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
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && bAdjustable)
    {
        const auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*GetWindow()));
        if(outlineBar.getGlobalBounds().contains(mousePos))
        {
            auto value = std::min((mousePos.x - outlineBar.getPosition().x) / outlineBar.getSize().x,1.f);
            if(value < 0.f)
            {
                value = 0.f;
            }
            SetSliderValue(value); 
        }
    }
}

void SliderBar::Render()
{
    GetWindow()->draw(outlineBar);
    GetWindow()->draw(fillBar);
}

#pragma endregion

#pragma region SliderProperties

void SliderBar::SetSliderValue(float newValue)
{
    fillBar.setSize(sf::Vector2f(newValue * size.x,size.y));
    if (bAdjustable)
    {
        onValueChanged(newValue);
    }
}

#pragma endregion  