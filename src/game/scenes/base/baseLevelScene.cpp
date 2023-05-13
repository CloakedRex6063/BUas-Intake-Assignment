#include "baseLevelScene.h"
#include "../../../engine/audio manager/audioManager.h"
#include "../../../engine/main/main.h"
#include "../../../engine/save file/saveFile.h"

#pragma region Required

BaseLevelScene::~BaseLevelScene()
{
    delete player;
}

void BaseLevelScene::Init()
{
    BaseScene::Init();
    CreateFloor();
    for (auto &floor : floorList)
    {
        floor.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        floor.Init();
    }
    
    CreateFlyPortal();
    for (auto &port : flyPortalList)
    {
        port.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        port.Init();
    }
    
    CreateObstacles();
    for (auto &obs : obsList)
    {
        obs.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        obs.Init();
    }
    
    CreatePickups();
    for (auto &pick : pickupList)
    {
        pick.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        pick.Init();
    }
    
    CreatePlayer();
    GetPlayer().SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    GetPlayer().Init();
    
    CreateWinPortal();
    winPortal->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    winPortal->Init();

    CreateCheckpoints();
    for (auto &check : checkpointList)
    {
        check.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        check.Init();
    }
    CreateCheckpointHint();
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
    GetWindow()->setView(*GetGameView());
    for (auto &port : flyPortalList)
    {
        port.Render();
    }
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
    for (auto &check : checkpointList)
    {
        check.Render();
    }
    player->Render();
    winPortal->Render();
    GetWindow()->setView(*GetFixedView());
    for (auto& checkHint : checkHintList)
    {
        GetWindow()->draw(checkHint);
    }
    BaseScene::Render();
}

#pragma endregion

#pragma region Progress

void BaseLevelScene::CreateSliders()
{
    const auto progressPos = sf::Vector2f(GetWindow()->getSize().x/2.f - 225.f,50.f);
    auto progressSlider = SliderBar(progressPos,sf::Vector2f(400.f,20.f),10.f);
    sliderList.emplace_back(progressSlider);
}

float BaseLevelScene::GetProgress() const
{
    return player->GetSprite().getPosition().x/winPortal->GetSprite().getPosition().x;
}

void BaseLevelScene::ShowProgress()
{
    sliderList[0].SetSliderValue(GetProgress());
}

#pragma endregion 

#pragma region Player

void BaseLevelScene::Die()
{
    AudioManager::PlaySound(DeathSound_Type);
    bRestarted = true;
    GetGame().RestartGame();
}

void BaseLevelScene::CreatePlayer()
{
    const auto viewCenter = GetGameView()->getCenter(); 
    const auto windowSize = sf::Vector2f(GetWindow()->getSize());
    const auto pos = GetGame().currentCheckPoint != nullptr
                         ? GetGame().currentCheckPoint->GetSprite().getPosition()
                         : sf::Vector2f(-windowSize.x / 4.f, windowSize.y - 145.f);
    if (GetGame().currentCheckPoint != nullptr)
    {
        GetGameView()->setCenter(sf::Vector2f(pos.x + 200.f, viewCenter.y));
    }
    else
    {
        GetGameView()->reset(sf::FloatRect(0,0,windowSize.x,windowSize.y));
    }
    SetPlayer(new Player(pos,sf::Vector2f(50,50),moveSpeed,-1050.f,50.f));
}

#pragma endregion

#pragma region LevelData

#pragma region Obstacles

void BaseLevelScene::AddSpikeLine(const sf::Vector2f& startPos, int numSpikes, sf::Vector2f spikeGaps, float spikeRadius)
{
    for (int i = 0; i < numSpikes; i++)
    {
        const auto obsPos = startPos + sf::Vector2f(i * spikeGaps.x, i * spikeGaps.y);
        auto spike = Spike(obsPos, spikeRadius);
        obsList.emplace_back(spike);
    }
}

#pragma endregion

#pragma region Floors

void BaseLevelScene::AddFloorLine(const sf::Vector2f& startPos, int numFloors, sf::Vector2f floorGaps,
    sf::Vector2f startSize, sf::Vector2f sizeIncrease, sf::Vector2f texMultiplier, sf::Texture* tex)
{
    for (int i = 0; i < numFloors; i++)
    {
        const auto floorPos = startPos + sf::Vector2f(i * floorGaps.x, i * floorGaps.y);
        const auto floorSize = startSize + sf::Vector2f(i * sizeIncrease.x, i * sizeIncrease.y);
        const auto floorTexMult = sf::Vector2i(static_cast<int>(texMultiplier.x * floorSize.x), static_cast<int>(texMultiplier.y * floorSize.y));
        auto floor = Floor(floorPos, floorSize, floorTexMult, tex);
        floorList.emplace_back(floor);
    }
}

#pragma endregion 

#pragma endregion 

#pragma region UI

void BaseLevelScene::CreateButtons()
{
    const auto pausePos = sf::Vector2f(static_cast<float>(GetWindow()->getSize().x) - 50.f,50.f);
    const auto pauseSize = sf::Vector2f(50.f,50.f);
    const auto pauseBut = Button(pausePos,pauseSize,5.f,GetGame().pauseTex);
    buttonList.emplace_back(pauseBut);
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
    const auto scorePos = sf::Vector2f(GetWindow()->getSize().x/2.f + 300.f,50.f);
    const auto scoreText = Text(scorePos,GetGame().GetFont(),50,std::to_string(0.f));
    const auto attemptPos = static_cast<sf::Vector2f>(GetWindow()->getSize())/2.f;
    auto attemptText = Text(attemptPos,GetGame().GetFont(),50,"Attempt " +
        std::to_string(GetGame().GetAttempts()));
    attemptText.bFixed = false;
    textList.emplace_back(scoreText);
    textList.emplace_back(attemptText);
}

#pragma endregion 

#pragma region ViewManipulation

void BaseLevelScene::ViewUpdate()
{
    if (player->GetSprite().getPosition().x > GetGameView()->getCenter().x - 200.f &&
        player->GetSprite().getPosition().x <= winPortal->GetSprite().getPosition().x - 950.f)
    {
        bStart = true;
        GetParallaxView()->move(50.f * Main::GetFixedDeltaSeconds(), 0.f);
        GetGameView()->move(moveSpeed * Main::GetFixedDeltaSeconds(), 0.f);
    }
}

#pragma endregion 

#pragma region Collision

void BaseLevelScene::CollisionCheck()
{
    PickupCheck();
    FlyCheck();
    CheckPointCheck();
    FloorCheck();
    if (bRestarted)
    {
        bRestarted = false;
        return;
    }
    BoundsCheck();
    if (bRestarted)
    {
        bRestarted = false;
        return;
    }
    ObstacleCheck();
    if (bRestarted)
    {
        bRestarted = false;
        return;
    }
    WinCheck();
}

void BaseLevelScene::PickupCheck()
{
    for (int i = 0; i < std::size(pickupList); i++)
    {
        if (player->GetCollider().intersects(pickupList[i].GetCollider()))
        {
            pickupList.erase(pickupList.begin() + i);
            coins++;
            break;
        }
    }
}

void BaseLevelScene::FloorCheck()
{
    bool bOnFloor = false;
    for (auto& floor : floorList)
    {
        if (player && player->GetCollider().intersects(floor.GetCollider()))
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
                Die();
                return;
            }
        }
    }
    
    if (!bOnFloor)
    {
        player->bGravity = true;
        player->bCanJump = false;
    }
}

void BaseLevelScene::BoundsCheck()
{
    for (const auto &obs : obsList)
    {
        if (player->GetCollider().intersects(obs.GetCollider()))
        {
            Die();
            return;
        }
    }
}

void BaseLevelScene::ObstacleCheck()
{
    if (player->GetSprite().getPosition().y > GetWindow()->getSize().y)
    {
        Die();
    }
}

void BaseLevelScene::CheckPointCheck()
{
    for (auto& check : checkpointList)
    {
        if (player->GetCollider().intersects(check.GetCollider()))
        {
            GetGame().currentCheckPoint = &check;
            GetGame().currentCheckPoint->GetSprite().setOutlineThickness(5.f);
            GetGame().currentCheckPoint->GetSprite().setOutlineColor(sf::Color::White);
        }
    }
}

void BaseLevelScene::FlyCheck() const
{
    for (const auto& flyPort : flyPortalList)
    {
        if (player->GetCollider().intersects(flyPort.GetCollider()))
        {
            player->bFly = flyPort.bFly ? true : false;
        }
    }
}

void BaseLevelScene::WinCheck() const
{
    if (player->GetCollider().intersects(winPortal->GetCollider()))
    {
        if (coins > Game::GetCoins())
        {
            Game::SetCoins(std::max(coins,3));
        }
        SaveFile::SaveData(Game::GetCoins(),Game::GetUsedCoins(),Player::GetTexIndex());
        GetGame().ChangeState(Victory_State);
    }
}

#pragma endregion







