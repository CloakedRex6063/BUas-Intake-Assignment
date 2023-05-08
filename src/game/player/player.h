#pragma once
#include "../../engine/object.h"
#include "../../engine/enums/enums.h"


class Player final : public Object
{
public:
    Player(sf::Vector2f pos,sf::Vector2f size, float moveSpeed,float jumpForce, float gravity);
    void Init() override;
    void Tick(float deltaTime) override;
    void PhysicsTick(float fixedDeltaTime) override;
    void Render() override;
    
    bool bGravity = false;
    bool bCanJump = true;
    bool bFly = false;
    float terminalVel = 1000.f;

    sf::RectangleShape& GetSprite() {return sprite;}
    sf::FloatRect GetCollider() const { return sprite.getGlobalBounds();}
    
private:
    /*
     * Sprite Properties
     */
    
    sf::RectangleShape sprite;
    sf::Vector2f size;
    sf::Vector2f pos;

    /*
     * Movement
     */
    float moveSpeed;
    float jumpForce;
    float gravity;
    sf::Vector2f velocity;

    void Move(float fixedDeltaTime);
    void Rotate(float fixedDeltaTime);
    void ApplyForce();

public:
    static sf::Texture* GetTex() {return tex;}
    static int GetTexIndex();
    static void SetTex(PlayerTex newTex);
private:
    static sf::Texture* tex;
};
