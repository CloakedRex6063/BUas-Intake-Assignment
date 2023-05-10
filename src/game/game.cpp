#include "game.h"
#include "../engine/audio manager/audioManager.h"
#include "../engine/main/main.h"
#include "../engine/save file/saveFile.h"
#include "scenes/ui/main menu/mainMenuScene.h"
#include "scenes/ui/options menu/optionsMenuScene.h"
#include "scenes/ui/game victory/victoryScene.h"
#include "scenes/ui/pause menu/pauseMenuScene.h"
#include "scenes/ui/shop menu/shopMenuScene.h"
#include "scenes/levels/levelScene.h"

#pragma region Static Initialisation

sf::Texture* Game::player1Tex = new sf::Texture();
sf::Texture* Game::player2Tex = new sf::Texture();
sf::Texture* Game::player3Tex = new sf::Texture();
sf::Texture* Game::player4Tex = new sf::Texture();
sf::Texture* Game::planeTex = new sf::Texture();

bool Game::bShowFPS = false;

int Game::coins = 0;
int Game::usedCoins = 0;

#pragma endregion 

#pragma region Required

#pragma region Save

void Game::LoadSavedVars() const
{
    LoadSettings();
    LoadData();
    LoadButtonState();
}

void Game::LoadSettings() const
{
    float soundVolume;
    float musicVolume;
    bool bVsync;
    bool bFps;
    SaveFile::LoadSettings(soundVolume,musicVolume,bVsync,bFps);
    
    AudioManager::SetSoundVolume(soundVolume);
    optionsMenu->GetSliderList()[0].SetSliderValue(AudioManager::GetSoundVolume());
    
    AudioManager::SetMusicVolume(musicVolume);
    optionsMenu->GetSliderList()[1].SetSliderValue(AudioManager::GetMusicVolume());

    Main::SetVsync(bVsync);
    GetWindow()->setVerticalSyncEnabled(bVsync);
    optionsMenu->GetButtonList()[1].SetTexture(bVsync ? tickTex : unTickTex);

    SetShowFPS(bFps);
    optionsMenu->GetButtonList()[2].SetTexture(bFps ? tickTex : unTickTex);
}

void Game::LoadData() const
{
    int playerTex;
    SaveFile::LoadData(coins,usedCoins, playerTex);
    Player::SetTex(static_cast<PlayerTex>(playerTex));
    shopMenu->GetSprite().setTexture(Player::GetTex());
}

void Game::LoadButtonState() const
{
    bool b1;
    bool b2;
    bool b3;
    SaveFile::LoadButtonState(b1,b2,b3);
    auto col = sf::Color::White;
    col.a = b1 ? 100 : 255;
    shopMenu->GetButtonList()[2].SetColor(col);
    shopMenu->GetButtonList()[2].bLocked = b1;
    shopMenu->GetButtonList()[3].SetColor(col);
    shopMenu->GetButtonList()[3].bLocked = b2;
    shopMenu->GetButtonList()[4].SetColor(col);
    shopMenu->GetButtonList()[4].bLocked = b3;
}

#pragma endregion 

void Game::Init()
{
    InitText();
    CreateTextures();
    bgSprite.setTexture(*bgTex);
    CreateBaseScenes();
    AudioManager::Init();
    ChangeState(MainMenu_State);
    LoadSavedVars();
}

void Game::Tick(float deltaTime)
{
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
    case Victory_State:
        gameVictory->Tick(deltaTime);
        break;
    case Shop_State:
        shopMenu->Tick(deltaTime);
        break;
    case Options_State:
        optionsMenu->Tick(deltaTime);
        break;
    case Restart_State: break;
    }
    const auto fpsString = "FPS:" + std::to_string(Main::GetFPS());
    fpsText->SetText(bShowFPS ? fpsString : "");
    fpsText->Tick(deltaTime);
}

void Game::PhysicsTick(float fixedDeltaTime)
{
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
    case Victory_State:
        gameVictory->PhysicsTick(fixedDeltaTime);
        break;
    case Shop_State:
        shopMenu->PhysicsTick(fixedDeltaTime);
        break;
    case Options_State:
        optionsMenu->PhysicsTick(fixedDeltaTime);
        break;
    case Restart_State: break;
    }
    fpsText->PhysicsTick(fixedDeltaTime);
}

void Game::Render()
{
    GetWindow()->setView(*GetParallaxView());
    GetWindow()->draw(bgSprite);
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
    case Victory_State:
        gameVictory->Render();
        break;
    case Shop_State:
        shopMenu->Render();
        break;
    case Options_State:
        optionsMenu->Render();
        break;
    case Restart_State: break;
    }
    GetWindow()->setView(*GetFixedView());
    fpsText->Render();
}

#pragma endregion

#pragma region Scenes

void Game::CreateBaseScenes()
{
    mainMenu = new MainMenuScene();
    mainMenu->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    mainMenu->SetGame(*this);
    mainMenu->Init();
    
    gameVictory = new VictoryScene();
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
    const auto windowSize = sf::Vector2f(GetWindow()->getSize());
    GetParallaxView()->reset(sf::FloatRect(0,0, windowSize.x,windowSize.y));
    GetGameView()->reset(sf::FloatRect(0,0, windowSize.x,windowSize.y));
    
    level = nullptr;
    level = new LevelScene();
    level->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    level->SetGame(*this);
    level->Init();
}

#pragma endregion

#pragma region Textures

void Game::CreateTextures() const
{
    player1Tex->loadFromFile("Assets/Textures/Player1.png");
    player2Tex->loadFromFile("Assets/Textures/Player2.png");
    player3Tex->loadFromFile("Assets/Textures/Player3.png");
    player4Tex->loadFromFile("Assets/Textures/Player4.png");
    planeTex->loadFromFile("Assets/Textures/Plane.png");
    
    playTex->loadFromFile("Assets/Textures/PlayButton.png");
    pauseTex->loadFromFile("Assets/Textures/PauseButton.png");
    menuTex->loadFromFile("Assets/Textures/MainMenu.png");
    restartTex->loadFromFile("Assets/Textures/Restart.png");
    backTex->loadFromFile("Assets/Textures/Back.png");
    shopTex->loadFromFile("Assets/Textures/Shop.png");
    optionsTex->loadFromFile("Assets/Textures/Options.png");
    tickTex->loadFromFile("Assets/Textures/Tick.png");
    unTickTex->loadFromFile("Assets/Textures/UnTick.png");

    winPortalTex->loadFromFile("Assets/Textures/WinPortal.png");
    flyPortalTex->loadFromFile("Assets/Textures/FlyPortal.png");
    coinTex->loadFromFile("Assets/Textures/Coin.png");
    checkPointTex->loadFromFile("Assets/Textures/Checkpoint.png");
    
    floor1Tex->loadFromFile("Assets/Textures/Floor1.png");
    floor2Tex->loadFromFile("Assets/Textures/Floor2.png");

    bgTex->loadFromFile("Assets/Textures/ParallaxBG.png");
}

#pragma endregion 

#pragma region GameStates

void Game::ChangeState(GameStates newState)
{
    switch (newState)
    {
    case MainMenu_State:
        if(currentGameState != Options_State && currentGameState != Shop_State)
        {
            AudioManager::StopMusic();
            AudioManager::PlayMusic(MenuMusic_Type);
        }
        break;
    case Gameplay_State:
        if (currentGameState == Pause_State)
        {
            AudioManager::ResumeMusic();
        }
        else
        {
            AudioManager::PlayMusic(LevelMusic_Type);
        }
        break;
    case Pause_State:
        AudioManager::PauseMusic();
        break;
    case Victory_State:
        AudioManager::StopMusic();
        break;
    case Shop_State: break;
    case Options_State: break;
    case Restart_State: break;
    }
    currentGameState = newState;
}

#pragma endregion 

#pragma region Text

void Game::InitText()
{
    font.loadFromFile("Assets/Fonts/Roboto.ttf");
    SetFont(font);
    const auto fpsPos = sf::Vector2f(25.f,0.f);
    fpsText = new Text(fpsPos,GetFont(),50," ");
    fpsText->Init();
    fpsText->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
}

#pragma endregion 

#pragma region RestartGame

void Game::RestartGame()
{
    AudioManager::StopMusic();
    SetAttempts(GetAttempts() + 1);
    CreateLevel();
    ChangeState(Gameplay_State);
}

#pragma endregion 





