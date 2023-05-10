#pragma once

#include "../object.h"
#include "../../game/game.h"

class Main final
{
   
#pragma region Required
    
public:
    Main();
    ~Main(); 
    void GameLoop();
    
private:
    Game game;

#pragma endregion 

#pragma region Window
    
    void CreateWindow();
    sf::RenderWindow* window = nullptr;
    sf::VideoMode videoMode;
    sf::String title{"Dash"};
    
    void CreateViews();
    sf::View* gameView = nullptr;
    sf::View* fixedView = nullptr;
    sf::View* parallaxView = nullptr;

#pragma endregion 

#pragma region Event
    
    sf::Event ev{};
    void PollEvent();

#pragma endregion

#pragma region Tick
    
    sf::Clock tickClock;
    
    sf::Time deltaTime;
    static float deltaSeconds;
    sf::Time fixedDeltaTime = sf::seconds(0.01f);
    sf::Time lastPhysTickTime = sf::Time::Zero;
    static float fixedDeltaSeconds;

    void RunTick();
    
public:
    static float GetDeltaSeconds() {return deltaSeconds;}
    static float GetFixedDeltaSeconds() {return fixedDeltaSeconds;}

#pragma endregion 

#pragma region FPS
    
private:
    sf::Time lastFpsTime = sf::Time::Zero;
    sf::Time fpsTime = sf::seconds(0.2f);
    static int fps;
public:
    static int GetFPS() {return fps;}

#pragma endregion 

#pragma region Vsync
    
private:
    static bool vsync;
public:
    static bool GetVsync() {return vsync;}
    static void SetVsync(bool value) {vsync = value;}

#pragma endregion
    
};


