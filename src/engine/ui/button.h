#pragma once
#include <functional>
#include "../../engine/object.h"

class Button final : public Object
{
    
#pragma region Required
    
public:
    Button(sf::Vector2f pos,sf::Vector2f size, float thickness, sf::Texture* tex);
    void Init() override;
    void Tick(float deltaTime) override;
    void Render() override;

#pragma endregion 

#pragma region ButtonProperties
    
private:
    void CreateButton();
    bool bCanPress = false;
    bool bHeld = false;
    bool bHovered = false;
    
    sf::RectangleShape sprite; 
    sf::Texture* tex = nullptr;

public:
    void SetTexture(sf::Texture* tex) {this->tex = tex; sprite.setTexture(this->tex);}
    void SetColor(sf::Color col) {sprite.setFillColor(col);}

private:
    sf::Vector2f size;
    sf::Vector2f pos;
    float thickness;

public:
    std::function<void()> onButtonPressed;
    bool bLocked = true;
#pragma endregion 
    
};


