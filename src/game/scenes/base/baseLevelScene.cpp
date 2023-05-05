#include "baseLevelScene.h"
#include "../../../engine/main/main.h"

int BaseLevelScene::jumps = 0;

BaseLevelScene::~BaseLevelScene()
{
    delete player;
}

void BaseLevelScene::Init()
{
    BaseScene::Init();
    CreateFloor();
    CreateObstacles();
    CreatePickups();
    CreatePlayer();
    CreateWinPortal();
    progressBar.setPosition(GetWindow().getSize().x/2.f - 200.f ,50.f);
    progressBar.setFillColor(sf::Color::Green);
    progressOutLineBar.setPosition(GetWindow().getSize().x/2.f - 200.f ,50.f);
    progressOutLineBar.setSize(sf::Vector2f(400.f,20.f));
    progressOutLineBar.setFillColor(sf::Color::Transparent);
    progressOutLineBar.setOutlineThickness(5.f);
    progressOutLineBar.setOutlineColor(sf::Color::White);
}

void BaseLevelScene::Tick(float deltaTime)
{
    BaseScene::Tick(deltaTime);
    player->Tick(deltaTime);
    for (auto &obs : obsList)
    {
        obs.Tick(deltaTime);
    }
    for (auto &pic : pickupList)
    {
        pic.Tick(deltaTime);
    }
    textList[0].SetText(std::to_string(bStart ? static_cast<int>(std::roundf(GetProgress() * 100.f)) : 0) + "%");
    if(bStart)
    {
        ShowProgress();
    }
}

void BaseLevelScene::PhysicsTick(float fixedDeltaTime)
{
    BaseScene::PhysicsTick(fixedDeltaTime);
    for (auto &obs: obsList)
    {
        obs.PhysicsTick(fixedDeltaTime);
    }
    for (auto &pic : pickupList)
    {
        pic.PhysicsTick(fixedDeltaTime);
    }
    ViewUpdate();
    player->PhysicsTick(fixedDeltaTime);
    CollisionCheck();
}

void BaseLevelScene::Render()
{
    GetWindow().setView(GetGameView());
    for (auto &floor: floorList)
    {
        floor.Render();
    }
    for (auto &obs: obsList)
    {
        obs.Render();
    }
    for (auto &pic : pickupList)
    {
        pic.Render();
    }
    player->Render();
    winPortal->Render();
    GetWindow().setView(GetFixedView());
    GetWindow().draw(progressBar);
    GetWindow().draw(progressOutLineBar);
    BaseScene::Render();
}

void BaseLevelScene::CreateButtons()
{
    const auto pausePos = sf::Vector2f(static_cast<float>(GetWindow().getSize().x) - 50.f,50.f);
    const auto pauseSize = sf::Vector2f(50.f,50.f);
    const auto pauseBut = Button(pausePos,pauseSize,5.f,GetGame().pauseTex);
    buttonList.emplace_back(pauseBut);
    for (auto &but : buttonList)
    {
        but.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        but.Init();
    }
}

void BaseLevelScene::BindButtons()
{
    pauseGame = [&]
    {
        GetGame().ChangeState(Pause_State);
    };
    
    buttonList[0].onButtonPressed = pauseGame;
}

void BaseLevelScene::CreateText()
{
    const auto scorePos = sf::Vector2f(static_cast<float>(GetWindow().getSize().x) /2.f + 300.f,50.f);
    const auto scoreText = Text(scorePos,GetGame().GetFont(),50,std::to_string(0.f));
    textList.emplace_back(scoreText);
    for (auto &text : textList)
    {
        text.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        text.Init();
    }
}

void BaseLevelScene::ViewUpdate()
{
    if (player->GetSprite().getPosition().x > GetGameView().getCenter().x - 200.f)
    {
        if (player->GetSprite().getPosition().x <= (winPortal->GetSprite().getPosition().x - 1000.f))
        {
            bStart = true;
            GetParallaxView().move(50.f * Main::GetFixedDeltaSeconds(), 0.f);
            GetGameView().move(moveSpeed * Main::GetFixedDeltaSeconds(), 0.f);
        }
    }
}

void BaseLevelScene::CollisionCheck()
{
    if (player->GetCollider().intersects(winPortal->GetCollider()))
    {
        GetGame().ChangeState(GameVictory_State);
    }
    
    if (player->GetSprite().getPosition().y > GetWindow().getSize().y)
    {
        GetGame().ChangeState(GameOver_State);
    }

    for (int i = 0; i < std::size(pickupList); i++)
    {
        if (player->GetCollider().intersects(pickupList[i].GetCollider()))
        {
            pickupList.erase(pickupList.begin() + i);
            Game::IncreaseScore(1);
            break;
        }
    }

    for (const auto &obs : obsList)
    {
        if (player->GetCollider().intersects(obs.GetCollider()))
        {
            GetGame().ChangeState(GameOver_State);
            break;
        }
    }

    bool bOnFloor = false;
    for (auto& floor : floorList)
    {
        if (player->GetCollider().intersects(floor.GetCollider()))
        {
            if (player->GetCollider().top <= floor.GetCollider().top)
            {
                player->GetSprite().setPosition(player->GetSprite().getPosition().x, floor.GetCollider().top - player->GetCollider().height / 2.f);
                bOnFloor = true;
                player->bGravity = false;
                player->bCanJump = true;
            }
            else
            {
                GetGame().ChangeState(GameOver_State);
            }
        }
    }
    
    if (!bOnFloor)
    {
        player->bGravity = true;
        player->bCanJump = false;
    }
}

void BaseLevelScene::AddSpikeLine(const sf::Vector2f& startPos, int numSpikes, sf::Vector2f spikeGaps, float spikeRadius)
{
    for (int i = 0; i < numSpikes; i++)
    {
        const auto obsPos = startPos + sf::Vector2f(i * spikeGaps.x, i * spikeGaps.y);
        auto spike = Spike(obsPos, spikeRadius);
        obsList.emplace_back(spike);
    }
}

float BaseLevelScene::GetProgress() const
{
    return player->GetSprite().getPosition().x/winPortal->GetSprite().getPosition().x;
}

void BaseLevelScene::ShowProgress()
{
    progressBar.setSize(sf::Vector2f(GetProgress() * 400, 20));
}

int BaseLevelScene::GetJumps()
{
    return jumps;
}

void BaseLevelScene::SetJumps(int newJumps)
{
    jumps = newJumps;
}

sf::Vector2f BaseLevelScene::Multiply(sf::Vector2f vector1, sf::Vector2f vector2)
{
    return sf::Vector2f(vector1.x * vector2.x, vector1.y * vector2.y);
}


