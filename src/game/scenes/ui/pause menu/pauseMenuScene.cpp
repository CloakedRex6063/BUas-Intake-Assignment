#include "pauseMenuScene.h"

#include <iostream>

void PauseMenuScene::CreateButtons()
{
    const auto resumePos = sf::Vector2f(GetWindow().getSize().x/2.f,GetWindow().getSize().y/2.f);
    const auto resumeBut = Button(resumePos,sf::Vector2f(100.f,100.f),5.f,playTex);
    const auto mainPos = sf::Vector2f(GetWindow().getSize().x/2.f - 200.f,GetWindow().getSize().y/2.f);
    const auto mainBut = Button(mainPos,sf::Vector2f(100.f,100.f),5.f,menuTex);
    const auto restartPos = sf::Vector2f(GetWindow().getSize().x/2.f + 200.f,GetWindow().getSize().y/2.f);
    const auto restartBut = Button(restartPos,sf::Vector2f(100.f,100.f),5.f,restartTex);
    buttonList.emplace_back(resumeBut);
    buttonList.emplace_back(mainBut);
    buttonList.emplace_back(restartBut);
    for (auto &but : buttonList)
    {
        but.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        but.Init();
    }
}

void PauseMenuScene::BindButtons()
{
    resumeGame = [&]
    {
        GetGame().ChangeState(Gameplay_State);
    };

    mainMenu = [&]
    {
        GetGame().ChangeState(MainMenu_State);
    };

    restartGame = [&]
    {
        GetGame().CreateLevel();
        GetGame().ChangeState(Gameplay_State);
    };
    
    buttonList[0].onButtonPressed = resumeGame;
    buttonList[1].onButtonPressed = mainMenu;
    buttonList[2].onButtonPressed = restartGame;
}

void PauseMenuScene::CreateText()
{
    const auto mainPos = sf::Vector2f(static_cast<float>(GetWindow().getSize().x) /2.f,50.f);
    const auto mainText = Text(mainPos,getFont(),50,"Paused");
    textList.emplace_back(mainText);
    for (auto &text : textList)
    {
        text.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        text.Init();
    }
}
