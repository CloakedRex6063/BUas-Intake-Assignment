#pragma once
#include "../../engine/object.h"
#include "../../engine/enums/enums.h"

class Game;

class Player final : public Object
{
    
#pragma region Required
    
public:
    Player(sf::Vector2f pos,sf::Vector2f size, float moveSpeed,float jumpForce, float gravity);
    void Init() override;
    void Tick(float deltaTime) override;
    void PhysicsTick(float fixedDeltaTime) override;
    void Render() override;

#pragma endregion

#pragma region SpriteProperties
    
private:
    sf::RectangleShape sprite;
    sf::RectangleShape planeSprite;
    sf::Vector2f size;
    sf::Vector2f pos;

public:
    sf::RectangleShape& GetSprite() {return sprite;}
    sf::FloatRect GetCollider() const { return sprite.getGlobalBounds();}

private:
    static sf::Texture* tex;
    
public:
    static sf::Texture* GetTex() {return tex;}
    static int GetTexIndex();
    static void SetTex(PlayerTex newTex);

#pragma endregion

#pragma region Movement

private:
    float moveSpeed;
    float jumpForce;
    float gravity;
    sf::Vector2f velocity;
    float terminalVel = 1000.f;

public:
    bool bGravity = false;
    bool bCanJump = true;
    bool bFly = false;

private:
    void Move(float fixedDeltaTime);
    void Rotate(float fixedDeltaTime);
    void ApplyForce();

#pragma endregion 
};
