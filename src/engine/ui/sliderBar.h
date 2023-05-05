#pragma once
#include <functional>
#include "../../engine/object.h"

class SliderBar : public Object
{
public:
    SliderBar(sf::Vector2f pos, sf::Vector2f size, float outThickness);

    void Init() override;
    void Tick(float deltaTime) override;
    void Render() override;
    
    void SetSliderValue(float newValue);
    float GetSliderValue() const {return sliderValue;}

    std::function<void(float sliderValue)> onValueChanged;
    
private:
    float sliderValue = 1.f;
    sf::RectangleShape outlineBar;
    sf::RectangleShape fillBar;
    sf::Vector2f pos;
    sf::Vector2f size;
    float outThickness;
};
