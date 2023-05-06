#pragma once
#include "../engine/object.h"
#include "../engine/enums/enums.h"
#include "../engine/ui/text.h"

class Player;
class PauseMenuScene;
class MainMenuScene;
class OptionsMenuScene;
class GameVictoryScene;
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
    GameVictoryScene* gameVictory = nullptr;
    PauseMenuScene* pauseMenu = nullptr;
    ShopMenuScene* shopMenu = nullptr;
    void CreateBaseScenes();

    LevelScene* level = nullptr;

public:
    void CreateLevel();

#pragma endregion 
    
#pragma region Textures

private:
    void CreateTextures();

public:
    sf::Texture* playerTex = nullptr;
    
    sf::Texture* playTex = nullptr;
    sf::Texture* pauseTex = nullptr;
    sf::Texture* menuTex = nullptr;
    sf::Texture* restartTex = nullptr;
    sf::Texture* backTex = nullptr;
    sf::Texture* shopTex = nullptr;
    sf::Texture* optionsTex = nullptr;
    sf::Texture* tickTex = nullptr;
    sf::Texture* unTickTex = nullptr;
    
    sf::Texture* floor1Tex = nullptr;
    sf::Texture* floor2Tex = nullptr;

#pragma endregion 

#pragma region Score
    
private:
    int score = 0;

public:
    int GetScore() const {return score;}
    void SetScore(int newScore) {score = newScore;}

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

