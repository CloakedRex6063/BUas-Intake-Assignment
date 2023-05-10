#include "player.h"
#include "../game.h"

#pragma region Static Initialisation

sf::Texture* Player::tex = new sf::Texture();

#pragma endregion 

#pragma region Required

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
    planeSprite.setSize(size);
    planeSprite.setOrigin(size/2.f);
    planeSprite.setPosition(pos);
    planeSprite.setTexture(Game::planeTex);
    sprite.setSize(size);
    sprite.setOrigin(size/2.f);
    sprite.setPosition(pos);
    sprite.setTexture(tex);
}

void Player::Tick(float deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (bCanJump || bFly))
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
    GetWindow()->draw(bFly ? planeSprite : sprite);
}

#pragma endregion

#pragma region SpriteProperties

int Player::GetTexIndex()
{
    if (tex == Game::player1Tex)
    {
        return 0;
    }
    if (tex == Game::player2Tex)
    {
        return 1;
    }
    if (tex == Game::player3Tex)
    {
        return 2;
    }
    if (tex == Game::player4Tex)
    {
        return 3;
    }
    return 0;
}

void Player::SetTex(PlayerTex newTex)
{
    switch (newTex)
    {
    case Tex1_Type:
        tex = Game::player1Tex;
        break;
    case Tex2_Type:
        tex = Game::player2Tex;
        break;
    case Tex3_Type:
        tex = Game::player3Tex;
        break;
    case Tex4_Type:
        tex = Game::player4Tex;
        break;
    }
}

#pragma endregion 

#pragma region Movement

void Player::Move(float deltaTime)
{
    velocity.x = moveSpeed;
    velocity.y += bGravity ? (bFly ? gravity/2.f : gravity) : 0.f;
    if(velocity.y > terminalVel)
    {
        velocity.y = terminalVel;
    }
    sprite.move(velocity * deltaTime);
    planeSprite.setPosition(sprite.getPosition());
}

void Player::Rotate(float fixedDeltaTime)
{
    if(!bCanJump && !bFly)
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
    velocity.y = bFly ? jumpForce/2.f : jumpForce;
    bCanJump = false;
}

#pragma endregion 


