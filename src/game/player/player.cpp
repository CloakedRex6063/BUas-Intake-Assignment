#include "player.h"
#include "../game.h"

sf::Texture* Player::tex = nullptr;

Player::Player(sf::Vector2f pos, sf::Vector2f size, float moveSpeed, float jumpForce, float gravity)
{
    this->pos = pos;
    this->size = size;
    this->moveSpeed = moveSpeed;
    this->jumpForce = jumpForce;
    this->gravity = gravity;
}

void Player::Init()
{
    sprite.setSize(size);
    sprite.setOrigin(size/2.f);
    sprite.setPosition(pos);
    sprite.setTexture(tex);
}

void Player::Tick(float deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bCanJump)
    {
        ApplyForce();
    }
}

void Player::PhysicsTick(float fixedDeltaTime)
{
    Move(fixedDeltaTime);
    Rotate(fixedDeltaTime);
}

void Player::Render()
{
    GetWindow().draw(sprite);
}

void Player::Move(float deltaTime)
{
    velocity.x = moveSpeed;
    velocity.y += bGravity ? gravity : 0.f;
    if(velocity.y > terminalVel)
    {
        velocity.y = terminalVel;
    }
    sprite.move(velocity * deltaTime);
}

void Player::Rotate(float fixedDeltaTime)
{
    if(!bCanJump)
    {
        sprite.rotate(500 * fixedDeltaTime);
    }
    else
    {
        if (sprite.getRotation() > 45 && sprite.getRotation() < 135.f)
        {
            sprite.setRotation(90.f);
        }
        else if (sprite.getRotation() > 135 && sprite.getRotation() < 225.f)
        {
            sprite.setRotation(180.f);
        }
        else if (sprite.getRotation() >= 225.0f && sprite.getRotation() < 315.0f)
        {
            sprite.setRotation(270.f);
        }
        else
        {
            sprite.setRotation(0.f);
        }
    }
}

void Player::ApplyForce()
{
    velocity.y = jumpForce;
    bCanJump = false;
}


