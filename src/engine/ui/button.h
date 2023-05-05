#pragma once
#include <functional>

#include "../../engine/object.h"
#include "..\..\engine\enums.h"

class Button : public Object
{
public:
    Button(sf::Vector2f pos,sf::Vector2f size, float thickness, sf::Texture* tex);
    void Init() override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    sf::Vector2f size;
    sf::Vector2f pos;
    float thickness;

    std::function<void()> onButtonPressed;
    
private:
    sf::RectangleShape sprite; 
    sf::Texture* tex = nullptr;
    bool bCanPress = false;
    bool bHeld = false;
    bool bHovered = false;
    void CreateButton();
};


