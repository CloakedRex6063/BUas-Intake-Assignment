#include "baseScene.h"

#pragma region Required

void BaseScene::Init()
{
    CreateButtons();
    BindButtons();
    CreateText();
    CreateSliders();
    BindSliders();
    
    for (auto &but : buttonList)
    {
        but.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        but.Init();
    }
    for (auto &text : textList)
    {
        text.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        text.Init();
    }
    for (auto &slider : sliderList)
    {
        slider.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        slider.Init();
    }
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
    GetWindow()->setView(*GetFixedView());
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
            GetWindow()->setView(*GetGameView());
            text.Render();
        }
    }
}

#pragma endregion 
