#pragma once
#include <functional>
#include "../../engine/object.h"

class SliderBar final : public Object
{

#pragma region Required
    
public:
    SliderBar(sf::Vector2f pos, sf::Vector2f size, float outThickness);
    void Init() override;
    void Tick(float deltaTime) override;
    void Render() override;

#pragma endregion

#pragma region SpriteProperties

private:
    
    sf::RectangleShape outlineBar;
    sf::RectangleShape fillBar;
    sf::Vector2f pos;
    sf::Vector2f size;
    float outThickness;

#pragma endregion 

#pragma region SliderProperties

    float sliderValue = 1.f;
    
public:
    void SetSliderValue(float newValue);
    float GetSliderValue() const {return sliderValue;}
    
    bool bAdjustable = false;

    std::function<void(float sliderValue)> onValueChanged;

#pragma endregion
    
};
