#pragma once
#include "../engine/object.h"
#include "../engine/enums.h"

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
public:
    void Init() override;
    void Tick(float deltaTime) override;
    void PhysicsTick(float fixedDeltaTime) override;
    void Render() override;

private:
    MainMenuScene* mainMenu = nullptr;
    OptionsMenuScene* optionsMenu = nullptr;
    GameOverScene* gameOver = nullptr;
    GameVictoryScene* gameVictory = nullptr;
    PauseMenuScene* pauseMenu = nullptr;
    ShopMenuScene* shopMenu = nullptr;
    LevelScene* level1 = nullptr;

    void CreateBaseScenes();
public:
    void CreateLevel();
    
private:
    static int score;
    GameStates currentGameState = {};

public:
    void ChangeState(GameStates newState);
    
    static sf::Color colors[4];
    static int GetScore();
    static void IncreaseScore(int bonus);
};

