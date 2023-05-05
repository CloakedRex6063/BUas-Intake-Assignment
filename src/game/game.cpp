#include "game.h"
#include <iostream>
#include "../engine/audioManager.h"
#include "scenes/ui/main menu/mainMenuScene.h"
#include "scenes/ui/game over/gameOverScene.h"
#include "scenes/ui/options menu/optionsMenuScene.h"
#include "scenes/ui/game victory/gameVictoryScene.h"
#include "scenes/ui/pause menu/pauseMenuScene.h"
#include "scenes/ui/shop menu/shopMenuScene.h"
#include "scenes/levels/levelScene.h"

int Game::score = 0;
sf::Color Game::colors[4] = {sf::Color::Yellow, sf::Color::Cyan, sf::Color::Green, sf::Color::Magenta}; 

#pragma region Inherited functions

void Game::Init()
{
    auto* tex = new sf::Texture();
    tex->loadFromFile("Assets/Textures/Player2.png");
    Player::tex = tex;
    CreateBaseScenes();
    AudioManager::Init();
    ChangeState(MainMenu_State);
    AudioManager::SetSoundVolume(100.f);
    AudioManager::SetMusicVolume(100.f);
    optionsMenu->GetSliderList()[0].SetSliderValue(AudioManager::GetSoundVolume()/100.f);
    optionsMenu->GetSliderList()[1].SetSliderValue(AudioManager::GetMusicVolume()/100.f);
}

void Game::Tick(float deltaTime)
{
    switch (currentGameState)
    {
    case MainMenu_State:
        mainMenu->Tick(deltaTime);
        break;
    case Gameplay_State:
        level1->Tick(deltaTime);
        break;
    case Pause_State:
        pauseMenu->Tick(deltaTime);
        break;
    case GameOver_State:
        gameOver->Tick(deltaTime);
        break;
    case GameVictory_State:
        gameVictory->Tick(deltaTime);
        break;
    case Shop_State:
        shopMenu->Tick(deltaTime);
        break;
    case Options_State:
        optionsMenu->Tick(deltaTime);
        break;
    }
}

void Game::PhysicsTick(float fixedDeltaTime)
{
    switch (currentGameState)
    {
    case MainMenu_State:
        mainMenu->PhysicsTick(fixedDeltaTime);
        break;
    case Gameplay_State:
        level1->PhysicsTick(fixedDeltaTime);
        break;
    case Pause_State:
        pauseMenu->PhysicsTick(fixedDeltaTime);
        break;
    case GameOver_State:
        gameOver->PhysicsTick(fixedDeltaTime);
        break;
    case GameVictory_State:
        gameVictory->PhysicsTick(fixedDeltaTime);
        break;
    case Shop_State:
        shopMenu->PhysicsTick(fixedDeltaTime);
        break;
    case Options_State:
        optionsMenu->PhysicsTick(fixedDeltaTime);
        break;
    }
}

void Game::Render()
{
    switch (currentGameState)
    {
    case MainMenu_State:
        mainMenu->Render();
        break;
    case Gameplay_State:
        level1->Render();
        break;
    case Pause_State:
        pauseMenu->Render();
        break;
    case GameOver_State:
        gameOver->Render();
        break;
    case GameVictory_State:
        gameVictory->Render();
        break;
    case Shop_State:
        shopMenu->Render();
        break;
    case Options_State:
        optionsMenu->Render();
        break; 
    }
}

#pragma endregion

void Game::CreateBaseScenes()
{
    mainMenu = new MainMenuScene();
    mainMenu->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    mainMenu->SetGame(*this);
    mainMenu->Init();
    
    gameOver = new GameOverScene();
    gameOver->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    gameOver->SetGame(*this);
    gameOver->Init();
    
    gameVictory = new GameVictoryScene();
    gameVictory->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    gameVictory->SetGame(*this);
    gameVictory->Init();
    
    pauseMenu = new PauseMenuScene();
    pauseMenu->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    pauseMenu->SetGame(*this);
    pauseMenu->Init();

    shopMenu = new ShopMenuScene();
    shopMenu->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    shopMenu->SetGame(*this);
    shopMenu->Init();

    optionsMenu = new OptionsMenuScene();
    optionsMenu->SetTarget(GetWindow(), GetGameView(), GetFixedView(), GetParallaxView());
    optionsMenu->SetGame(*this);
    optionsMenu->Init();
}

void Game::CreateLevel()
{
    const auto windowSize = sf::Vector2f(GetWindow().getSize());
    GetParallaxView().reset(sf::FloatRect(0,0, windowSize.x,windowSize.y));
    GetGameView().reset(sf::FloatRect(0,0, windowSize.x,windowSize.y));
    delete level1;
    level1 = new LevelScene();
    level1->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    level1->SetGame(*this);
    level1->Init();
}

#pragma region Helper

int Game::GetScore()
{
    return score;
}

void Game::IncreaseScore(int bonus)
{
    score+= bonus;
}

void Game::ChangeState(GameStates newState)
{
    currentGameState = newState;
    if (newState == Gameplay_State)
    {
        AudioManager::PlayMusic(Level1Music_Type,1.f);
    }
}

#pragma endregion 





