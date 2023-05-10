#pragma once
#include "../../base/baseScene.h"

class VictoryScene : public BaseScene
{

#pragma region UI
    
#pragma region Buttons
    
    std::function<void()> mainMenu;
    std::function<void()> restart;
    
    void CreateButtons() override;
    void BindButtons() override;

#pragma endregion 

#pragma region Text
    
    void CreateText() override;

#pragma endregion

#pragma endregion 
    
};
