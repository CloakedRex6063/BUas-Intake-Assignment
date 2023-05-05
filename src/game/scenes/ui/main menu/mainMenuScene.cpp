#include "mainMenuScene.h"

void MainMenuScene::CreateButtons()
{
    const auto playPos = sf::Vector2f(GetWindow().getSize().x/2.f,GetWindow().getSize().y/2.f);
    const auto playBut = Button(playPos,sf::Vector2f(200.f,200.f),5.f,GetGame().playTex);
    const auto shopPos = sf::Vector2f(GetWindow().getSize().x - 100.f,GetWindow().getSize().y - 100.f);
    const auto shopBut = Button(shopPos,sf::Vector2f(100.f,100.f),5.f,GetGame().shopTex);
    const auto optionsPos = sf::Vector2f(GetWindow().getSize().x - 100.f,100.f);
    const auto optionsBut = Button(optionsPos,sf::Vector2f(100.f,100.f),5.f,GetGame().optionsTex);
    buttonList.emplace_back(playBut);
    buttonList.emplace_back(shopBut);
    buttonList.emplace_back(optionsBut);
    for (auto &but : buttonList)
    {
        but.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        but.Init();
    }
}

void MainMenuScene::BindButtons()
{
    playGame = [&]
    {
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

void MainMenuScene::CreateText()
{
    const auto mainPos = sf::Vector2f(static_cast<float>(GetWindow().getSize().x) /2.f,50.f);
    const auto mainText = Text(mainPos,GetGame().GetFont(),50,"Dash");
    textList.emplace_back(mainText);
    for (auto &text : textList)
    {
        text.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        text.Init();
    }
}
