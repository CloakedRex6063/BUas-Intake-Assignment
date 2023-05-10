#include "pauseMenuScene.h"

#pragma region UI

#pragma region Buttons

void PauseMenuScene::CreateButtons()
{
    const auto windowSize = sf::Vector2f(GetWindow()->getSize());
    const auto resumePos = sf::Vector2f(windowSize.x/2.f + 100.f,windowSize.y/2.f);
    const auto resumeBut = Button(resumePos,sf::Vector2f(100.f,100.f),5.f,GetGame().playTex);
    const auto mainPos = sf::Vector2f(windowSize.x/2.f - 100.f,windowSize.y/2.f);
    const auto mainBut = Button(mainPos,sf::Vector2f(100.f,100.f),5.f,GetGame().menuTex);
    buttonList.emplace_back(resumeBut);
    buttonList.emplace_back(mainBut);
}

void PauseMenuScene::BindButtons()
{
    resumeGame = [&]
    {
        GetGame().ChangeState(Gameplay_State);
    };

    mainMenu = [&]
    {
        GetGame().currentCheckPoint = nullptr;
        GetGame().ChangeState(MainMenu_State);
    };
    
    buttonList[0].onButtonPressed = resumeGame;
    buttonList[1].onButtonPressed = mainMenu;
}

#pragma endregion

#pragma region Text

void PauseMenuScene::CreateText()
{
    const auto windowSize = sf::Vector2f(GetWindow()->getSize());
    const auto mainPos = sf::Vector2f(static_cast<float>(windowSize.x) /2.f,50.f);
    const auto mainText = Text(mainPos,GetGame().GetFont(),50,"Paused");
    textList.emplace_back(mainText);
}

#pragma endregion

#pragma endregion 
