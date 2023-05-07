#pragma once
#include <functional>
#include "../../engine/object.h"
#include "../../engine/audio manager/audioManager.h"

class Button : public Object
{
public:
    Button(sf::Vector2f pos,sf::Vector2f size, float thickness, sf::Texture* tex);
    void Init() override;
    void Tick(float deltaTime) override;
    void Render() override;
    void SetTexture(sf::Texture* tex) {this->tex = tex; sprite.setTexture(this->tex);}
    void SetColor(sf::Color col) {sprite.setFillColor(col);}

    std::function<void()> onButtonPressed;
    bool bLocked = true;
protected:
    sf::Vector2f size;
    sf::Vector2f pos;
    float thickness;
    
    sf::RectangleShape sprite; 
    sf::Texture* tex = nullptr;
    bool bCanPress = false;
    bool bHeld = false;
    bool bHovered = false;
    void CreateButton();
};


