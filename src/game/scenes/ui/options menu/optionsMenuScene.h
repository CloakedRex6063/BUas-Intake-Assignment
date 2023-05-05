#pragma once
#include "../../base/baseScene.h"

class OptionsMenuScene : public BaseScene
{
    std::function<void()> back;
    std::function<void(float value)> soundVolume;
    std::function<void(float value)> musicVolume;
    std::function<void()> vsync;
    std::function<void()> fps;
    
    void CreateButtons() override;
    void BindButtons() override;
    void CreateText() override;

    void CreateSliders() override;
    void BindSliders() override;
};
