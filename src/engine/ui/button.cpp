#include "button.h"
#include "../audio manager/audioManager.h"

#pragma region Required

Button::Button(sf::Vector2f pos, sf::Vector2f size, float thickness, sf::Texture* tex)
{
    this->thickness = thickness;
    this->size = size;
    this->pos = pos;
    this->tex = tex;
}

void Button::Init()
{
    CreateButton();
}

void Button::Tick(float deltaTime)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && bCanPress && !bHeld)
    {
        bHeld = true;
        AudioManager::PlaySound(ClickSound_Type);
        onButtonPressed();
    }
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        bHeld = false;
    }
    const auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*GetWindow()));
    if (sprite.getGlobalBounds().contains(mousePos))
    {
        sprite.setOutlineColor(sf::Color::White);
        bCanPress = true;
        if(!bHovered)
        {
            AudioManager::PlaySound(HoverSound_Type);
            bHovered = true;
        }
    }
    else
    {
        sprite.setOutlineColor(sf::Color::Transparent);
        bCanPress = false;
        bHovered = false;
    }
}

void Button::Render()
{
    GetWindow()->draw(sprite);
}

#pragma endregion

#pragma region ButtonProperties

void Button::CreateButton()
{
    sprite.setSize(size);
    sprite.setOrigin(size/2.f);
    sprite.setPosition(pos);
    sprite.setTexture(tex);
    sprite.setOutlineThickness(5.f);
    sprite.setOutlineColor(sf::Color::Transparent);
}

#pragma endregion 

