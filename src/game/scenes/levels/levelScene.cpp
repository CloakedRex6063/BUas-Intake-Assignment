#include "levelScene.h"
#include "../../../engine/structs/structs.h"
#include "../../obstacles/spike.h"

void LevelScene::CreateObstacles()
{
    const auto windowSize = static_cast<sf::Vector2f>(GetWindow().getSize());
    std::vector<ObstacleData> obstacleData =
    {
        {sf::Vector2f(1500.f,windowSize.y - 140.f),40.f},
        {sf::Vector2f(2100.f,windowSize.y - 130.f),30.f},
        {sf::Vector2f(2150.f,windowSize.y - 140.f),40.f},
        {sf::Vector2f(2945.f,windowSize.y - 140.f),40.f}
    };
    
    AddSpikeLine(sf::Vector2f(3055,windowSize.y - 130.f),4,sf::Vector2f(50.f,0.f),30.f);
    
    AddSpikeLine(sf::Vector2f(3310,windowSize.y - 130.f),4,sf::Vector2f(50.f,0.f),30.f);
    
    AddSpikeLine(sf::Vector2f(4200,windowSize.y - 140.f),2,sf::Vector2f(60.f,0.f),40.f);
    
    AddSpikeLine(sf::Vector2f(5710,windowSize.y - 130.f),4,sf::Vector2f(50.f,0.f),30.f);
    
    obstacleData.insert(obstacleData.end(),{sf::Vector2f(6300.f, windowSize.y - 240.f), 40.f});
    
    AddSpikeLine(sf::Vector2f(6910,windowSize.y - 130.f),4,sf::Vector2f(50.f,0.f),30.f);
    
    obstacleData.insert(obstacleData.end(),{sf::Vector2f(7500.f, windowSize.y - 340.f), 40.f});
    
    AddSpikeLine(sf::Vector2f(9815,370.f),4,sf::Vector2f(50.f,0.f),30.f);
    
    AddSpikeLine(sf::Vector2f(10315,370.f),4,sf::Vector2f(50.f,0.f),30.f);
    
    AddSpikeLine(sf::Vector2f(11410,350.f),4,sf::Vector2f(50.f,0.f),30.f);
    
    obstacleData.insert(obstacleData.end(),
{
        {sf::Vector2f(12340.f, windowSize.y - 440.f), 40.f},
        {sf::Vector2f(12415.f, windowSize.y - 340.f), 40.f},
        {sf::Vector2f(13490.f, windowSize.y - 330.f), 40.f},
        {sf::Vector2f(15910.f, 185.f), 30.f}
    });

    for (const auto& data : obstacleData)
    {
        auto obstacle = Spike(data.position, data.radius);
        obsList.emplace_back(obstacle);
    }
    
    for (auto &obs : obsList)
    {
        obs.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        obs.Init();
    }
}

void LevelScene::CreateFloor()
{
    const auto windowSize = static_cast<sf::Vector2f>(GetWindow().getSize());
    std::vector<FloorData> floorData =
        {
            {sf::Vector2f(-windowSize.x/2.f,windowSize.y - 50.f),sf::Vector2f(5700,100.f),
                sf::Vector2f(0.5f,0.5f),GetGame().floor1Tex}
        };
    
    const auto Line1Pos = sf::Vector2f(3000,windowSize.y - 135.f);
    const auto Line1Gaps = sf::Vector2f(250.f,-50.f);
    const auto Line1Size = sf::Vector2f(50.f,75.f);
    const auto Line1Increase = sf::Vector2f(0.f,100.f);
    const auto Line1TexMult = sf::Vector2f(1.f,1.f);
    AddFloorLine(Line1Pos,3,Line1Gaps,Line1Size,Line1Increase,Line1TexMult,GetGame().floor2Tex);

    floorData.insert(floorData.end(),
        {sf::Vector2f(4700.f,windowSize.y - 50.f),sf::Vector2f(1000.f,300.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor1Tex});

    floorData.insert(floorData.end(),
        {sf::Vector2f(5700.f,windowSize.y - 50.f),sf::Vector2f(200.f,100.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor1Tex});

    const auto Line2Pos = sf::Vector2f(5900.f,windowSize.y - 50.f);
    const auto Line2Gaps = sf::Vector2f(1200.f,-100.f);
    const auto Line2Size = sf::Vector2f(1000.f,300.f);
    const auto Line2Increase = sf::Vector2f(0.f,0.f);
    const auto Line2TexMult = sf::Vector2f(0.5f,0.5f);
    AddFloorLine(Line2Pos,2,Line2Gaps,Line2Size,Line2Increase,Line2TexMult,GetGame().floor1Tex);

    floorData.insert(floorData.end(),
        {sf::Vector2f(6900.f,windowSize.y - 50.f),sf::Vector2f(200.f,100.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor1Tex});

    const auto Line3Pos = sf::Vector2f(8350.f,windowSize.y - 325.f);
    const auto Line3Gaps = sf::Vector2f(275.f,-50.f);
    const auto Line3Size = sf::Vector2f(50.f,25.f);
    const auto Line3Increase = sf::Vector2f(0.f,0.f);
    const auto Line3TexMult = sf::Vector2f(1.f,1.f);
    AddFloorLine(Line3Pos,4,Line3Gaps,Line3Size,Line3Increase,Line3TexMult,GetGame().floor1Tex);

    floorData.insert(floorData.end(),
{
        {sf::Vector2f(9400,windowSize.y),sf::Vector2f(1600.f,800.f),
            sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
        {sf::Vector2f(9800.f,300.f),sf::Vector2f(200.f,25.f),
            sf::Vector2f(1.f,2.f), GetGame().floor1Tex},
        {sf::Vector2f(10300.f,300.f),sf::Vector2f(200.f,25.f),
            sf::Vector2f(1.f,2.f),GetGame().floor1Tex},
        {sf::Vector2f(11000.f,windowSize.y),sf::Vector2f(1000.f,600.f),
            sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
        {sf::Vector2f(11400.f,390.f),sf::Vector2f(200.f,25.f),
            sf::Vector2f(1.f,2.f), GetGame().floor1Tex},
        {sf::Vector2f(12000.f,windowSize.y),sf::Vector2f(400.f,800.f),
            sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
        {sf::Vector2f(12400.f,windowSize.y),sf::Vector2f(700.f,600.f),
            sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex}
    });
    
    const auto Line4Pos = sf::Vector2f(13250.f,525.f);
    const auto Line4Gaps = sf::Vector2f(450.f,100.f);
    const auto Line4Size = sf::Vector2f(300.f,25.f);
    const auto Line4Increase = sf::Vector2f(100.f,0.f);
    const auto Line4TexMult = sf::Vector2f(1.f,2.f);
    AddFloorLine(Line4Pos,2,Line4Gaps,Line4Size,Line4Increase,Line4TexMult,GetGame().floor1Tex);

    floorData.insert(floorData.end(),
            {sf::Vector2f(14250.f,725.f),sf::Vector2f(500.f,25.f),
                sf::Vector2f(1.f,1.f), GetGame().floor1Tex});

    const auto Line5Pos = sf::Vector2f(14650.f,725.f);
    const auto Line5Gaps = sf::Vector2f(250.f,-100.f);
    const auto Line5Size = sf::Vector2f(50.f,25.f);
    const auto Line5Increase = sf::Vector2f(0.f,0.f);
    const auto Line5TexMult = sf::Vector2f(1.f,1.f);
    AddFloorLine(Line5Pos,6,Line5Gaps,Line5Size,Line5Increase,Line5TexMult,GetGame().floor1Tex);

    floorData.insert(floorData.end(),
{
    {sf::Vector2f(15800.f,windowSize.y),sf::Vector2f(2000.f,600.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(16200.f,200.f),sf::Vector2f(1600.f,400.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex}
    });

    for (const auto& data : floorData)
    {
        sf::Vector2f texMultiplier = sf::Vector2f(data.size.x * data.texSize.x, data.size.y * data.texSize.y);
        auto floor = Floor(data.position, data.size, texMultiplier,GetGame().floor1Tex);
        floorList.emplace_back(floor);
    }
    
    for (auto &floor : floorList)
    {
        floor.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        floor.Init();
    }
}

void LevelScene::CreateWinPortal()
{
    const auto winSize = sf::Vector2f(50.f,100.f);
    const auto winPos = sf::Vector2f(17750.f,450.f);
    winPortal = new WinPortal(winPos,winSize);
    winPortal->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    winPortal->Init();
}

void LevelScene::CreatePlayer()
{
    const auto windowSize = static_cast<sf::Vector2f>(GetWindow().getSize());
    const auto pos = sf::Vector2f(-windowSize.x/4.f,windowSize.y - 145.f);
    player = new Player(pos,sf::Vector2f(50,50),moveSpeed,-1050.f,50.f);
    player->SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
    player->Init();
}

void LevelScene::CreatePickups()
{
    const auto windowSize = static_cast<sf::Vector2f>(GetWindow().getSize());
    const auto pickup1 = Pickup(sf::Vector2f(windowSize.x/2.f,200.f),25.f, 200.f);
    const auto pickup2 = Pickup(sf::Vector2f(3700,windowSize.y - 125.f),25.f, 200.f);
    //pickupList.emplace_back(pickup1);
    pickupList.emplace_back(pickup2);
    for (auto &pick : pickupList)
    {
        pick.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        pick.Init();
    }
}
