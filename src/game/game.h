#pragma once
#include "../engine/object.h"
#include "../engine/enums/enums.h"
#include "../engine/ui/text.h"

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
private:
    void LoadSavedVars() const;
    
public:
    void Init() override;
    void Tick(float deltaTime) override;
    void PhysicsTick(float fixedDeltaTime) override;
    void Render() override;

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
    
#pragma region Textures

private:
    static void CreateTextures();

public:
    static sf::Texture* player1Tex;
    static sf::Texture* player2Tex;
    static sf::Texture* player3Tex;
    static sf::Texture* player4Tex;
    static sf::Texture* planeTex;
    
    static sf::Texture* playTex;
    static sf::Texture* pauseTex;
    static sf::Texture* menuTex;
    static sf::Texture* restartTex;
    static sf::Texture* backTex;
    static sf::Texture* shopTex;
    static sf::Texture* optionsTex;
    static sf::Texture* tickTex;
    static sf::Texture* unTickTex;

    static sf::Texture* winPortalTex;
    static sf::Texture* flyPortalTex;
    static sf::Texture* coinTex;
    
    static sf::Texture* floor1Tex;
    static sf::Texture* floor2Tex;

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
    
#pragma endregion

public:
    void RestartGame();
    
    static sf::Color colors[4];
};

