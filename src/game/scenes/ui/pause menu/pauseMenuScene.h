#pragma once
#include "../../base/baseScene.h"

class PauseMenuScene : public BaseScene
{
    std::function<void()> resumeGame;
    std::function<void()> mainMenu;
    
    void CreateButtons() override;
    void BindButtons() override;
    
    void CreateText() override;
};
