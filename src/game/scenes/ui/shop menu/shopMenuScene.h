#pragma once
#include "../../base/baseScene.h"

class ShopMenuScene : public BaseScene
{

#pragma region Required
    
public:
    void Init() override;
    void Tick(float deltaTime) override;
    void Render() override;

#pragma endregion

#pragma region Sprite
    
private:
    sf::RectangleShape sprite;

public:
    sf::RectangleShape& GetSprite() {return sprite;}

#pragma endregion

#pragma region UI
    
#pragma region Buttons
    
protected:
    void CreateButtons() override;
    void BindButtons() override;
    
private:
    std::function<void()> back;
    std::function<void()> type1;
    std::function<void()> type2;
    std::function<void()> type3;
    std::function<void()> type4;

#pragma endregion 

#pragma region Text
    
protected:
    void CreateText() override;

#pragma endregion

#pragma endregion 

#pragma region Coins
    
private:
    int avCoins = 0;

#pragma endregion
    
};
