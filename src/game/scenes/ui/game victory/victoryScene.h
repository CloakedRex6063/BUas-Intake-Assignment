#pragma once
#include "../../base/baseScene.h"

class VictoryScene : public BaseScene
{
    std::function<void()> mainMenu;
    std::function<void()> restart;
    
    void CreateButtons() override;
    void BindButtons() override;
    void CreateText() override;
};
