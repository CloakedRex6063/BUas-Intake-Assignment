#pragma once
#include "../../base/baseScene.h"

class ShopMenuScene : public BaseScene
{
public:
    void Init() override;
    void Render() override;
protected:
    void CreateButtons() override;
    void BindButtons() override;
    void CreateText() override;
private:
    sf::RectangleShape sprite;
    std::function<void()> back;
};
