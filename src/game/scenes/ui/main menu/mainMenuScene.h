#pragma once
#include "../../base/baseScene.h"

class MainMenuScene : public BaseScene
{

#pragma region UI
    
#pragma region Buttons
    
    std::function<void()> playGame;
    std::function<void()> shop;
    std::function<void()> options;
    
    void CreateButtons() override;
    void BindButtons() override;

#pragma endregion 

#pragma region Text
    
    void CreateText() override;

#pragma endregion

#pragma endregion 
    
};
