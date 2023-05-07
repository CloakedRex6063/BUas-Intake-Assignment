#include "shopMenuScene.h"
#include "../../../../engine/main/main.h"
#include "../../../../engine/save file/saveFile.h"
#include "../../../player/player.h"

void ShopMenuScene::Init()
{
    BaseScene::Init();
    sprite.setSize(sf::Vector2f(200.f,200.f));
    sprite.setOrigin(sprite.getSize()/2.f);
    sprite.setPosition(GetWindow().getSize().x/2.f, 300.f);
    sprite.setTexture(Player::GetTex());
}

void ShopMenuScene::Tick(float deltaTime)
{
    avCoins = Game::GetCoins() - Game::GetUsedCoins();
    textList[1].SetText("Coins:" + std::to_string(avCoins));
    BaseScene::Tick(deltaTime);
}

void ShopMenuScene::Render()
{
    BaseScene::Render();
    GetWindow().draw(sprite);
}

void ShopMenuScene::CreateButtons()
{
    const auto backPos = sf::Vector2f(100.f,GetWindow().getSize().y - 100.f);
    const auto backBut = Button(backPos,sf::Vector2f(100.f,100.f),5.f,Game::backTex);

    const auto type1Pos = sf::Vector2f(GetWindow().getSize().x/2.f - 450.f,GetWindow().getSize().y/2.f + 100.f);
    const auto type1But = Button(type1Pos,sf::Vector2f(100.f,100.f),5.f,Game::player1Tex);
    const auto type2Pos = sf::Vector2f(GetWindow().getSize().x/2.f - 150.f,GetWindow().getSize().y/2.f + 100.f);
    const auto type2But = Button(type2Pos,sf::Vector2f(100.f,100.f),5.f,Game::player2Tex);
    const auto type3Pos = sf::Vector2f(GetWindow().getSize().x/2.f + 150.f,GetWindow().getSize().y/2.f + 100.f);
    const auto type3But = Button(type3Pos,sf::Vector2f(100.f,100.f),5.f,Game::player3Tex);
    const auto type4Pos = sf::Vector2f(GetWindow().getSize().x/2.f + 450.f,GetWindow().getSize().y/2.f + 100.f);
    const auto type4But = Button(type4Pos,sf::Vector2f(100.f,100.f),5.f,Game::player4Tex);
    
    buttonList.emplace_back(backBut);
    buttonList.emplace_back(type1But);
    buttonList.emplace_back(type2But);
    buttonList.emplace_back(type3But);
    buttonList.emplace_back(type4But);
    
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
        SaveFile::SaveData(Game::GetCoins(),Game::GetUsedCoins(),Player::GetTexIndex());
        SaveFile::SaveButtonState(buttonList[2].bLocked,buttonList[3].bLocked,buttonList[4].bLocked);
        GetGame().ChangeState(MainMenu_State);
    };
    type1 = [&]
    {
        Player::SetTex(Tex1_Type);
        sprite.setTexture(Game::player1Tex);
    };
    type2 = [&]
    {
        if (buttonList[2].bLocked && avCoins > 0)
        {
            buttonList[2].bLocked = false;
            buttonList[2].SetColor(sf::Color::White);
            Game::SetUsedCoins(Game::GetUsedCoins() + 1);
        }
        else if (!buttonList[2].bLocked)
        {
            Player::SetTex(Tex2_Type);
            sprite.setTexture(Game::player2Tex);
        }
    };
    type3 = [&]
    {
        if (buttonList[3].bLocked && avCoins > 0)
        {
            buttonList[3].bLocked = false;
            buttonList[3].SetColor(sf::Color::White);
            Game::SetUsedCoins(Game::GetUsedCoins() + 1);
        }
        else if (!buttonList[3].bLocked)
        {
            Player::SetTex(Tex3_Type);
            sprite.setTexture(Game::player3Tex);
        }
    };
    type4 = [&]
    {
        if (buttonList[4].bLocked && avCoins > 0)
        {
            buttonList[4].bLocked = false;
            buttonList[4].SetColor(sf::Color::White);
            Game::SetUsedCoins(Game::GetUsedCoins() + 1);
        }
        else if (!buttonList[4].bLocked)
        {
            Player::SetTex(Tex4_Type);
            sprite.setTexture(Game::player4Tex);
        }
    };
    buttonList[0].onButtonPressed = back;
    buttonList[1].onButtonPressed = type1;
    buttonList[2].onButtonPressed = type2;
    buttonList[3].onButtonPressed = type3;
    buttonList[4].onButtonPressed = type4;
}

void ShopMenuScene::CreateText()
{
    const auto shopPos = sf::Vector2f(static_cast<float>(GetWindow().getSize().x) /2.f,50.f);
    const auto shopText = Text(shopPos,GetGame().GetFont(),50,"Shop");
    const auto coinPos = sf::Vector2f(static_cast<float>(GetWindow().getSize().x) - 100.f,50.f);
    auto coinText = Text(coinPos,GetGame().GetFont(),50,"Coins:0");
    textList.emplace_back(shopText);
    textList.emplace_back(coinText);
    for (auto &text : textList)
    {
        text.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        text.Init();
    }
}
