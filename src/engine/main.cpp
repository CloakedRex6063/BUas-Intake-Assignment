#include "main.h"
#include <iostream>

#include "audioManager.h"
#include "../game/game.h"

float Main::deltaSeconds = 0.f;
float Main::fixedDeltaSeconds = 0.f;

Main::Main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    fixedDeltaSeconds = fixedDeltaTime.asSeconds();
    CreateWindow();
}

void Main::CreateWindow()
{
    videoMode = sf::VideoMode(1600,800);
    window.create(videoMode, title, sf::Style::Close);
    const auto windowSize = sf::Vector2f(window.getSize());
    gameView = sf::View(sf::FloatRect(0,0, windowSize.x,windowSize.y));
    fixedView = sf::View(sf::FloatRect(0,0, windowSize.x,windowSize.y));
    parallaxView = sf::View(sf::FloatRect(0,0, windowSize.x,windowSize.y));
    game.SetTarget(window,gameView,fixedView,parallaxView);
    game.Init();
    if(!bgTex.loadFromFile("Assets/Textures/ParallaxBG.png"))
    {
        std::cout << "Failed to load Assets/Textures/ParallaxBG.png";
    }
    bgSprite.setTexture(bgTex);
}

void Main::GameLoop()
{
    while (window.isOpen())
    {
        PollEvent();
        RunTick();
    }
}

void Main::PollEvent()
{
    while (window.pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            AudioManager::StopMusic();
            window.close();
            break;
        default:
            break;
        }
    }
}

void Main::RunTick()
{
    deltaTime = tickClock.restart();
    lastPhysTickTime += deltaTime;
    lastFpsTime += deltaTime;
    deltaSeconds = deltaTime.asSeconds();
    fps = 1.f / deltaSeconds;
    while (lastPhysTickTime >= fixedDeltaTime)
    {
        game.PhysicsTick(fixedDeltaTime.asSeconds());
        lastPhysTickTime -= fixedDeltaTime;
    }
    while (lastFpsTime >= fpsTime)
    {
        window.setTitle(title + std::to_string(static_cast<int>(fps)));
        lastFpsTime -= fpsTime;
    }
    game.Tick(deltaTime.asSeconds());
    window.clear();
    window.setView(parallaxView);
    window.draw(bgSprite);
    window.setView(fixedView);
    game.Render();
    window.display();
}

float Main::GetDeltaSeconds()
{
    return deltaSeconds;
}

float Main::GetFixedDeltaSeconds()
{
    return fixedDeltaSeconds;
}

int main()
{
    Main main;
    main.GameLoop();
    return 0;
}
