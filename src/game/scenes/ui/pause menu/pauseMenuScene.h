#pragma once
#include "../../base/baseScene.h"

class PauseMenuScene : public BaseScene
{

#pragma region Buttons
    
    std::function<void()> resumeGame;
    std::function<void()> mainMenu;
    
    void CreateButtons() override;
    void BindButtons() override;

#pragma endregion

#pragma region Text
    
    void CreateText() override;

#pragma endregion
    
};
