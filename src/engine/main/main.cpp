#include "main.h"
#include "../audio manager/audioManager.h"
#include "../../game/game.h"

#pragma region Static Initialisation

float Main::deltaSeconds = 0.f;
float Main::fixedDeltaSeconds = 0.f;
bool Main::vsync = false;
int Main::fps = 0;

#pragma endregion 

#pragma region Required

int WinMain()
{
    Main main;
    main.GameLoop();
    return 0;
}

Main::Main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    fixedDeltaSeconds = fixedDeltaTime.asSeconds();
    
    CreateWindow();
    CreateViews();
    
    game.SetTarget(window,gameView,fixedView,parallaxView);
    game.Init();
}

Main::~Main()
{
    delete window;
    delete fixedView;
    delete gameView;
    delete parallaxView;
}

void Main::GameLoop()
{
    while (window->isOpen())
    {
        PollEvent();
        RunTick();
    }
}

#pragma endregion 

#pragma region Window

void Main::CreateWindow()
{
    videoMode = sf::VideoMode(1600,800);
    window = new sf::RenderWindow();
    window->create(videoMode, title, sf::Style::Close);
    auto windowIcon = sf::Image();
    windowIcon.loadFromFile("Assets/Textures/Player1.png");
    window->setIcon(100,100,windowIcon.getPixelsPtr());
}

void Main::CreateViews()
{
    const auto windowSize = sf::Vector2f(window->getSize());
    gameView = new sf::View(sf::FloatRect(0,0,windowSize.x,windowSize.y));
    fixedView = new sf::View(sf::FloatRect(0,0,windowSize.x,windowSize.y));
    parallaxView = new sf::View(sf::FloatRect(0,0,windowSize.x,windowSize.y));
}

#pragma endregion

#pragma region Event

void Main::PollEvent()
{
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            AudioManager::OnClose();
            window->close();
            break;
        default:
            break;
        }
    }
}

#pragma endregion

#pragma region Tick

void Main::RunTick()
{
    deltaTime = tickClock.restart();
    lastPhysTickTime += deltaTime;
    lastFpsTime += deltaTime;
    deltaSeconds = deltaTime.asSeconds();
    while (lastPhysTickTime >= fixedDeltaTime)
    {
        game.PhysicsTick(fixedDeltaTime.asSeconds());
        lastPhysTickTime -= fixedDeltaTime;
    }
    while (lastFpsTime >= fpsTime)
    {
        fps = static_cast<int>(1.f / deltaSeconds);
        lastFpsTime -= fpsTime;
    }
    game.Tick(deltaTime.asSeconds());
    window->clear();
    game.Render();
    window->display();
}

#pragma endregion
