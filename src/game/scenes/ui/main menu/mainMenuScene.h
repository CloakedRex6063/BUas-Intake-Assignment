#pragma once
#include "../../base/baseScene.h"

class MainMenuScene : public BaseScene
{
    std::function<void()> playGame;
    std::function<void()> shop;
    std::function<void()> options;
    
    void CreateButtons() override;
    void BindButtons() override;
    void CreateText() override;
};
