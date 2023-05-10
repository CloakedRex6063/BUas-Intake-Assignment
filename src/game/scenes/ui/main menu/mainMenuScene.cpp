#include "mainMenuScene.h"

#pragma region UI

#pragma region Buttons

void MainMenuScene::CreateButtons()
{
    const auto windowSize = sf::Vector2f(GetWindow()->getSize());
    const auto playPos = sf::Vector2f(windowSize.x/2.f,windowSize.y/2.f);
    const auto playBut = Button(playPos,sf::Vector2f(200.f,200.f),5.f,GetGame().playTex);
    const auto shopPos = sf::Vector2f(windowSize.x - 100.f,windowSize.y - 100.f);
    const auto shopBut = Button(shopPos,sf::Vector2f(100.f,100.f),5.f,GetGame().shopTex);
    const auto optionsPos = sf::Vector2f(windowSize.x - 100.f,100.f);
    const auto optionsBut = Button(optionsPos,sf::Vector2f(100.f,100.f),5.f,GetGame().optionsTex);
    buttonList.emplace_back(playBut);
    buttonList.emplace_back(shopBut);
    buttonList.emplace_back(optionsBut);
}

void MainMenuScene::BindButtons()
{
    playGame = [&]
    {
        GetGame().SetAttempts(1);
        GetGame().CreateLevel();
        GetGame().ChangeState(Gameplay_State);
    };

    shop = [&]
    {
        GetGame().ChangeState(Shop_State);
    };

    options = [&]
    {
        GetGame().ChangeState(Options_State);
    };
    
    buttonList[0].onButtonPressed = playGame;
    buttonList[1].onButtonPressed = shop;
    buttonList[2].onButtonPressed = options;
}

#pragma endregion 

#pragma region Text

void MainMenuScene::CreateText()
{
    const auto windowSize = sf::Vector2f(GetWindow()->getSize());
    const auto mainPos = sf::Vector2f(static_cast<float>(windowSize.x) /2.f,50.f);
    const auto mainText = Text(mainPos,GetGame().GetFont(),50,"Dash");
    textList.emplace_back(mainText);
}

#pragma endregion

#pragma endregion 
