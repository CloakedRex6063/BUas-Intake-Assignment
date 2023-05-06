#include "baseScene.h"

void BaseScene::Init()
{
    CreateButtons();
    BindButtons();
    CreateText();
    CreateSliders();
    BindSliders();
}

void BaseScene::Tick(float deltaTime)
{
    for (auto &but : buttonList)
    {
        but.Tick(deltaTime);
    }
    for (auto &text : textList)
    {
        text.Tick(deltaTime);
    }
    for (auto &slider : sliderList)
    {
        slider.Tick(deltaTime);
    }
}

void BaseScene::PhysicsTick(float fixedDeltaTime)
{
    for (auto &but : buttonList)
    {
        but.PhysicsTick(fixedDeltaTime);
    }
    for (auto &text : textList)
    {
        text.PhysicsTick(fixedDeltaTime);
    }
    for (auto &slider : sliderList)
    {
        slider.PhysicsTick(fixedDeltaTime);
    }
}

void BaseScene::Render()
{
    for (auto &but : buttonList)
    {
        but.Render();
    }
    for (auto &slider : sliderList)
    {
        slider.Render();
    }
    for (auto &text : textList)
    {
        if (text.bFixed)
        {
            text.Render();
        }
        else
        {
            GetWindow().setView(GetGameView());
            text.Render();
        }
    }
}

