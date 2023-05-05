#pragma once
#include "../../base/baseScene.h"

class OptionsMenuScene : public BaseScene
{
    
private:
    std::function<void()> back;
    std::function<void(float value)> soundVolume;
    std::function<void(float value)> musicVolume;
    
    void CreateButtons() override;
    void BindButtons() override;
    void CreateText() override;

    void CreateSliders() override;
    void BindSliders() override;
};
