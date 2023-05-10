#pragma once

#include "../engine/object.h"
#include "../engine/enums/enums.h"
#include "../engine/ui/text.h"
#include "checkpoint/checkPoint.h"

class Player;
class PauseMenuScene;
class MainMenuScene;
class OptionsMenuScene;
class VictoryScene;
class ShopMenuScene;
class BaseLevelScene;
class LevelScene;

class Game final : public Object
{
    
#pragma region Required

#pragma region Save
    
    void LoadSavedVars() const;
    void LoadSettings() const;
    void LoadData() const;
    void LoadButtonState() const;

#pragma endregion 
    
public:
    void Init() override;
    void Tick(float deltaTime) override;
    void PhysicsTick(float fixedDeltaTime) override;
    void Render() override;

#pragma endregion  

#pragma region Scenes
    
private:
    MainMenuScene* mainMenu = nullptr;
    OptionsMenuScene* optionsMenu = nullptr;
    VictoryScene* gameVictory = nullptr;
    PauseMenuScene* pauseMenu = nullptr;
    ShopMenuScene* shopMenu = nullptr;
    void CreateBaseScenes();

    LevelScene* level = nullptr;

public:
    void CreateLevel();

#pragma endregion 

#pragma region Background
    
    sf::Sprite bgSprite;
    
#pragma endregion 
    
#pragma region Textures

private:
    void CreateTextures() const;

public:
    static sf::Texture* player1Tex;
    static sf::Texture* player2Tex;
    static sf::Texture* player3Tex;
    static sf::Texture* player4Tex;
    static sf::Texture* planeTex;
    
    sf::Texture* playTex = new sf::Texture();
    sf::Texture* pauseTex = new sf::Texture();
    sf::Texture* menuTex = new sf::Texture();
    sf::Texture* restartTex = new sf::Texture();
    sf::Texture* backTex = new sf::Texture();
    sf::Texture* shopTex = new sf::Texture();
    sf::Texture* optionsTex = new sf::Texture();
    sf::Texture* tickTex = new sf::Texture();
    sf::Texture* unTickTex = new sf::Texture();

    sf::Texture* winPortalTex = new sf::Texture();
    sf::Texture* flyPortalTex = new sf::Texture();
    sf::Texture* coinTex = new sf::Texture();
    sf::Texture* checkPointTex = new sf::Texture();
    
    sf::Texture* floor1Tex = new sf::Texture();
    sf::Texture* floor2Tex = new sf::Texture();
    
    sf::Texture* bgTex = new sf::Texture();

#pragma endregion 

#pragma region Score
    
private:
    static int usedCoins;
    static int coins;

public:
    static int GetUsedCoins() {return usedCoins;}
    static void SetUsedCoins(int newCoins) {usedCoins = newCoins;}

    static int GetCoins() {return coins;}
    static void SetCoins(int newCoins) {coins = newCoins;}

#pragma endregion 

#pragma region GameStates
    
private:
    GameStates currentGameState = {};
    
public:
    void ChangeState(GameStates newState);

#pragma endregion 

#pragma region FPS
    
private:
    static bool bShowFPS;

public:
    static bool GetShowFPS() {return bShowFPS;}
    static void SetShowFPS(bool bShow) {bShowFPS = bShow;}

#pragma endregion

#pragma region Text

private:
    void InitText();
    Text* fpsText = nullptr;
    sf::Font font;
    void SetFont(const sf::Font& newFont) {font = newFont;}
    
public:
    sf::Font& GetFont() {return font;}
    
#pragma endregion

#pragma region Attempts

private:
    int attempts = 0;

public:
    int GetAttempts() const {return attempts;}
    void SetAttempts(int newAttempts) {attempts = newAttempts;}

    CheckPoint* currentCheckPoint = nullptr;
    
#pragma endregion

#pragma region Restart
    
    void RestartGame();
    
#pragma endregion 
    
};

