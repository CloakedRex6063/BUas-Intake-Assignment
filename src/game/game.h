#pragma once
#include "../engine/object.h"
#include "../engine/enums/enums.h"
#include "../engine/ui/text.h"

class PauseMenuScene;
class MainMenuScene;
class OptionsMenuScene;
class GameOverScene;
class GameVictoryScene;
class ShopMenuScene;
class BaseLevelScene;
class LevelScene;

class Game final : public Object
{
private:
    void LoadSavedVars();
    
public:
    void Init() override;
    void Tick(float deltaTime) override;
    void PhysicsTick(float fixedDeltaTime) override;
    void Render() override;

#pragma region Scenes
    
private:
    MainMenuScene* mainMenu = nullptr;
    OptionsMenuScene* optionsMenu = nullptr;
    GameOverScene* gameOver = nullptr;
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

#pragma endregion 

#pragma region Score
    
private:
    static int score;

public:
    static int GetScore() {return score;}
    static void IncreaseScore(int bonus) {score += bonus;}

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

public:
    static sf::Color colors[4];
};

