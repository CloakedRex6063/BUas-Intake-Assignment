#pragma once

#include "../../base/baseScene.h"

class OptionsMenuScene : public BaseScene
{

#pragma region UI
    
#pragma region Buttons
    
    std::function<void()> back;
    std::function<void(float value)> soundVolume;
    std::function<void(float value)> musicVolume;
    std::function<void()> vsync;
    std::function<void()> fps;
    
    void CreateButtons() override;
    void BindButtons() override;

#pragma endregion

#pragma region Text
    
    void CreateText() override;

#pragma endregion

#pragma region Sliders
    
    void CreateSliders() override;
    void BindSliders() override;

#pragma endregion

#pragma endregion
    
};
