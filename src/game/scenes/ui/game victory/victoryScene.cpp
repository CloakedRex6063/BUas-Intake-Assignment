#include "victoryScene.h"

#pragma region UI

#pragma region Buttons

void VictoryScene::CreateButtons()
{
    const auto windowSize = static_cast<sf::Vector2f>(GetWindow()->getSize());
    const auto mainPos = sf::Vector2f(windowSize.x/2.f - 200.f,windowSize.y/2.f);
    const auto mainBut = Button(mainPos,sf::Vector2f(100.f,100.f),5.f,GetGame().menuTex);
    const auto restartPos = sf::Vector2f(windowSize.x/2.f + 200.f,windowSize.y/2.f);
    const auto restartBut = Button(restartPos,sf::Vector2f(100.f,100.f),5.f,GetGame().restartTex);
    buttonList.emplace_back(mainBut);
    buttonList.emplace_back(restartBut);
}

void VictoryScene::BindButtons()
{
    mainMenu = [&]
    {
        GetGame().currentCheckPoint = nullptr;
        GetGame().ChangeState(MainMenu_State);
    };
    
    restart = [&]
    {
        GetGame().currentCheckPoint = nullptr;
        GetGame().SetAttempts(1);
        GetGame().CreateLevel();
        GetGame().ChangeState(Gameplay_State);
    };
    
    buttonList[0].onButtonPressed = mainMenu;
    buttonList[1].onButtonPressed = restart;
}

#pragma endregion

#pragma region Text

void VictoryScene::CreateText()
{
    const auto mainPos = sf::Vector2f(static_cast<float>(GetWindow()->getSize().x) /2.f,50.f);
    const auto mainText = Text(mainPos,GetGame().GetFont(),50,"You win !!!");
    textList.emplace_back(mainText);
}

#pragma endregion

#pragma endregion 
