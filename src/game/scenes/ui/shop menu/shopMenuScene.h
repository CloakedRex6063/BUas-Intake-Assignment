#pragma once
#include "../../base/baseScene.h"

class ShopMenuScene : public BaseScene
{
public:
    void Init() override;
    void Tick(float deltaTime) override;
    void Render() override;
private:
    sf::RectangleShape sprite;

public:
    sf::RectangleShape& GetSprite() {return sprite;}
    
protected:
    void CreateButtons() override;
    void BindButtons() override;
    
private:
    std::function<void()> back;
    std::function<void()> type1;
    std::function<void()> type2;
    std::function<void()> type3;
    std::function<void()> type4;
    
protected:
    void CreateText() override;
    
private:
    int avCoins = 0;
};
