#pragma once

#include "object.h"
#include "../game/game.h"

class Main
{
public:
    Main();

    void CreateWindow();
    void GameLoop();
    void PollEvent();
    void RunTick();
    static float GetDeltaSeconds();
    static float GetFixedDeltaSeconds();
    
private:
    
    /*
     * Window Related
     */
    
    sf::RenderWindow window;
    sf::VideoMode videoMode;
    sf::String title{"Dash -- FPS: "};
    sf::View gameView;
    sf::View fixedView;
    sf::View parallaxView;
    
    sf::Sprite bgSprite;
    sf::Texture bgTex;

    /*
     * Handles events
     */
    
    sf::Event ev{};

    /*
     *  Tick Related
     */
    
    sf::Clock tickClock;
    sf::Time lastPhysTickTime = sf::Time::Zero;
    sf::Time lastFpsTime = sf::Time::Zero;
    sf::Time deltaTime;
    sf::Time fpsTime = sf::seconds(0.2f);
    sf::Time fixedDeltaTime = sf::seconds(0.01f);
    float fps;

    static float deltaSeconds;
    static float fixedDeltaSeconds;
    
    Game game;
};


