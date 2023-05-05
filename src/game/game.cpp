#include "game.h"
#include <iostream>
#include "../engine/audio manager/audioManager.h"
#include "../engine/main/main.h"
#include "../engine/save file/saveFile.h"
#include "scenes/ui/main menu/mainMenuScene.h"
#include "scenes/ui/game over/gameOverScene.h"
#include "scenes/ui/options menu/optionsMenuScene.h"
#include "scenes/ui/game victory/gameVictoryScene.h"
#include "scenes/ui/pause menu/pauseMenuScene.h"
#include "scenes/ui/shop menu/shopMenuScene.h"
#include "scenes/levels/levelScene.h"

int Game::score = 0;
bool Game::bShowFPS = false;
sf::Color Game::colors[4] = {sf::Color::Yellow, sf::Color::Cyan, sf::Color::Green, sf::Color::Magenta}; 

void Game::LoadSavedVars()
{
    float soundVolume;
    float musicVolume;
    bool bVsync;
    bool bFps;
    SaveFile::LoadData(soundVolume,musicVolume,bVsync,bFps);
    
    AudioManager::SetSoundVolume(soundVolume);
    optionsMenu->GetSliderList()[0].SetSliderValue(AudioManager::GetSoundVolume());
    
    AudioManager::SetMusicVolume(musicVolume);
    optionsMenu->GetSliderList()[1].SetSliderValue(AudioManager::GetMusicVolume());

    Main::SetVsync(bVsync);
    GetWindow().setVerticalSyncEnabled(bVsync);
    optionsMenu->GetButtonList()[1].SetTexture(bVsync ? tickTex : unTickTex);

    SetShowFPS(bFps);
    optionsMenu->GetButtonList()[2].SetTexture(bFps ? tickTex : unTickTex);
}

#pragma region Inherited functions

void Game::Init()
{
    InitText();
    CreateTextures();
    Player::tex = playerTex;
    CreateBaseScenes();
    AudioManager::Init();
    LoadSavedVars();
    ChangeState(MainMenu_State);
}

void Game::Tick(float deltaTime)
{
    fpsText->SetText(bShowFPS ? std::to_string(Main::GetFPS()) : "");
    fpsText->Tick(deltaTime);
    switch (currentGameState)
    {
    case MainMenu_State:
        mainMenu->Tick(deltaTime);
        break;
    case Gameplay_State:
        level->Tick(deltaTime);
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
    fpsText->PhysicsTick(fixedDeltaTime);
    switch (currentGameState)
    {
    case MainMenu_State:
        mainMenu->PhysicsTick(fixedDeltaTime);
        break;
    case Gameplay_State:
        level->PhysicsTick(fixedDeltaTime);
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
    fpsText->Render();
    switch (currentGameState)
    {
    case MainMenu_State:
        mainMenu->Render();
        break;
    case Gameplay_State:
        level->Render();
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
    
    delete level;
    level = new LevelScene();
    level->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    level->SetGame(*this);
    level->Init();
}

void Game::CreateTextures()
{
    playerTex = new sf::Texture();
    playerTex->loadFromFile("Assets/Textures/Player2.png");
    playTex = new sf::Texture();
    playTex->loadFromFile("Assets/Textures/PlayButton.png");
    pauseTex = new sf::Texture();
    pauseTex->loadFromFile("Assets/Textures/PauseButton.png");
    menuTex = new sf::Texture();
    menuTex->loadFromFile("Assets/Textures/MainMenu.png");
    restartTex = new sf::Texture();
    restartTex->loadFromFile("Assets/Textures/Restart.png");
    backTex = new sf::Texture();
    backTex->loadFromFile("Assets/Textures/Back.png");
    shopTex = new sf::Texture();
    shopTex->loadFromFile("Assets/Textures/Shop.png");
    optionsTex = new sf::Texture();
    optionsTex->loadFromFile("Assets/Textures/MainMenu.png");
    tickTex = new sf::Texture();
    tickTex->loadFromFile("Assets/Textures/Tick.png");
    unTickTex = new sf::Texture();
    unTickTex->loadFromFile("Assets/Textures/UnTick.png");
}

#pragma region Helper

void Game::ChangeState(GameStates newState)
{
    switch (newState)
    {
    case MainMenu_State:
        if(currentGameState != Options_State && currentGameState != Shop_State)
        {
            AudioManager::StopMusic();
            AudioManager::PlayMusic(MenuMusic_Type,0);
        }
        break;
    case Gameplay_State:
        if (currentGameState == Pause_State)
        {
            AudioManager::ResumeMusic();
        }
        else
        {
            AudioManager::PlayMusic(LevelMusic_Type,1.f);
        }
        break;
    case Pause_State:
        AudioManager::PauseMusic();
        break;
    case GameOver_State:
        AudioManager::StopMusic();
        break;
    case GameVictory_State:
        AudioManager::StopMusic();
        break;
    default: break;
    }
    currentGameState = newState;
}

void Game::InitText()
{
    font.loadFromFile("Assets/Fonts/Cherry.ttf");
    SetFont(font);
    const auto fpsPos = sf::Vector2f(25.f,0.f);
    fpsText = new Text(fpsPos,GetFont(),50," ");
    fpsText->Init();
    fpsText->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
}

#pragma endregion 





