#include "shopMenuScene.h"

#include "../../../player/player.h"

void ShopMenuScene::Init()
{
    BaseScene::Init();
    sprite.setSize(sf::Vector2f(100.f,100.f));
    sprite.setOrigin(sprite.getSize()/2.f);
    sprite.setPosition(GetWindow().getSize().x/2.f, 200.f);
    sprite.setTexture(Player::tex);
}

void ShopMenuScene::Render()
{
    BaseScene::Render();
    GetWindow().draw(sprite);
}

void ShopMenuScene::CreateButtons()
{
    const auto backPos = sf::Vector2f(100.f,GetWindow().getSize().y - 100.f);
    const auto backBut = Button(backPos,sf::Vector2f(100.f,100.f),5.f,backTex);
    buttonList.emplace_back(backBut);
    for (auto &but : buttonList)
    {
        but.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        but.Init();
    }
}

void ShopMenuScene::BindButtons()
{
    back = [&]
    {
        GetGame().ChangeState(MainMenu_State);
    };
    buttonList[0].onButtonPressed = back;
}

void ShopMenuScene::CreateText()
{
    const auto shopPos = sf::Vector2f(static_cast<float>(GetWindow().getSize().x) /2.f,50.f);
    const auto shopText = Text(shopPos,getFont(),50,"Shop");
    textList.emplace_back(shopText);
    for (auto &text : textList)
    {
        text.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        text.Init();
    }
}
