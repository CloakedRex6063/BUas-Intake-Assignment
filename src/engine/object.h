﻿#pragma once

#include "SFML/Graphics.hpp"

class Object  
{

#pragma region Required
    
public:
    virtual void Init() {}
    virtual void Tick(float deltaTime) {}
    virtual void PhysicsTick(float fixedDeltaTime) {}
    virtual void Render() {}

#pragma endregion 

#pragma region Window
    
    void SetTarget(sf::RenderWindow* window, sf::View* gameView, sf::View* fixedView, sf::View* parallaxView)
    {this->window = window;this->gameView = gameView;this->fixedView = fixedView;this->parallaxView = parallaxView;}
    sf::RenderWindow* GetWindow() const {return window;}
    sf::View* GetGameView() const {return gameView;}
    sf::View* GetFixedView() const {return fixedView;}
    sf::View* GetParallaxView() const {return parallaxView;}

private:
    sf::RenderWindow* window = nullptr;
    sf::View* gameView = nullptr;
    sf::View* fixedView = nullptr;
    sf::View* parallaxView = nullptr;

#pragma endregion 
    
};
