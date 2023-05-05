#include "baseScene.h"

#include <iostream>

void BaseScene::Init()
{
    font.loadFromFile("Assets/Fonts/Cherry.ttf");
    SetFont(font);
    CreateTextures();
    CreateButtons();
    BindButtons();
    CreateText();
    CreateSliders();
    BindSliders();
}

void BaseScene::Tick(float deltaTime)
{
    for (auto &but : buttonList)
    {
        but.Tick(deltaTime);
    }
    for (auto &text : textList)
    {
        text.Tick(deltaTime);
    }
    for (auto &slider : sliderList)
    {
        slider.Tick(deltaTime);
    }
}

void BaseScene::PhysicsTick(float fixedDeltaTime)
{
    for (auto &but : buttonList)
    {
        but.PhysicsTick(fixedDeltaTime);
    }
    for (auto &text : textList)
    {
        text.PhysicsTick(fixedDeltaTime);
    }
    for (auto &slider : sliderList)
    {
        slider.PhysicsTick(fixedDeltaTime);
    }
}

void BaseScene::Render()
{
    for (auto &but : buttonList)
    {
        but.Render();
    }
    for (auto &text : textList)
    {
        text.Render();
    }
    for (auto &slider : sliderList)
    {
        slider.Render();
    }
}

void BaseScene::CreateTextures()
{
    playTex = new sf::Texture();
    playTex->loadFromFile("Assets/Textures/PlayButton.png");
    pauseTex = new sf::Texture();
    pauseTex->loadFromFile("Assets/Textures/PauseButton.png");
    menuTex = new sf::Texture();
    menuTex->loadFromFile("Assets/Textures/MainMenu.png");
    restartTex = new sf::Texture();
    restartTex->loadFromFile("Assets/Textures/Restart.png");
    backTex = new sf::Texture();
    backTex->loadFromFile("Assets/Textures/Back.png");
    shopTex = new sf::Texture();
    shopTex->loadFromFile("Assets/Textures/Shop.png");
    optionsTex = new sf::Texture();
    optionsTex->loadFromFile("Assets/Textures/MainMenu.png");
}

