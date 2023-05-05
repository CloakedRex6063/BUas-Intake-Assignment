#include "levelScene.h"
#include "../../../engine/structs/structs.h"
#include "../../obstacles/spike.h"

void LevelScene::CreateObstacles()
{
    const auto windowSize = static_cast<sf::Vector2f>(GetWindow().getSize());
    const std::vector<ObstacleData> obstacleData =
        {
            {sf::Vector2f(1500.f,windowSize.y - 155.f),40.f},
            {sf::Vector2f(2100.f,windowSize.y - 140.f),30.f},
            {sf::Vector2f(2145.f,windowSize.y - 155.f),40.f},
            {sf::Vector2f(2925.f,windowSize.y - 155.f),40.f},
            {sf::Vector2f(4200.f,windowSize.y - 155.f),40.f},
            {sf::Vector2f(4260.f,windowSize.y - 155.f),40.f},
            {sf::Vector2f(6300.f,windowSize.y - 230.f),40.f},
            {sf::Vector2f(7500.f,windowSize.y - 300.f),40.f},
            {sf::Vector2f(12325.f,windowSize.y - 455.f),40.f},
            {sf::Vector2f(12390.f,windowSize.y - 355.f),40.f},
            {sf::Vector2f(13475.f,windowSize.y - 345.f),40.f},
            {sf::Vector2f(15895.f,170.f),30.f}
        };

    for (const auto& data : obstacleData)
    {
        auto obstacle = Spike(data.position, data.radius);
        obsList.emplace_back(obstacle);
    }

    AddSpikeLine(sf::Vector2f(3045,windowSize.y - 140.f),4,sf::Vector2f(50.f,0.f),30.f);
    AddSpikeLine(sf::Vector2f(3295,windowSize.y - 140.f),4,sf::Vector2f(50.f,0.f),30.f);
    AddSpikeLine(sf::Vector2f(5695,windowSize.y - 140.f),4,sf::Vector2f(50.f,0.f),30.f);
    AddSpikeLine(sf::Vector2f(6895,windowSize.y - 140.f),4,sf::Vector2f(50.f,0.f),30.f);
    AddSpikeLine(sf::Vector2f(9800,355.f),4,sf::Vector2f(50.f,0.f),30.f);
    AddSpikeLine(sf::Vector2f(10300,355.f),4,sf::Vector2f(50.f,0.f),30.f);
    AddSpikeLine(sf::Vector2f(11395,335.f),4,sf::Vector2f(50.f,0.f),30.f);
    
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
            {sf::Vector2f(-windowSize.x/2.f,windowSize.y - 50.f),sf::Vector2f(8900,100.f)},
            {sf::Vector2f(9400,windowSize.y),sf::Vector2f(1600.f,800.f)},
            {sf::Vector2f(11000.f,windowSize.y),sf::Vector2f(1000.f,600.f)},
            {sf::Vector2f(12000.f,windowSize.y),sf::Vector2f(400.f,800.f)},
            {sf::Vector2f(12400.f,windowSize.y),sf::Vector2f(700.f,600.f)},
            {sf::Vector2f(15800.f,windowSize.y),sf::Vector2f(2000.f,600.f)},
            {sf::Vector2f(16200.f,200.f),sf::Vector2f(1600.f,400.f)},
        };

    for (const auto& data : floorData)
    {
        auto floor = Floor(data.position, data.size);
        floorList.emplace_back(floor);
    }
    
    Floor plat1_3[3];
    for (int i = 0; i < std::size(plat1_3); i++)
    {
        const auto floorPos = sf::Vector2f(3000 + (i * 250.f),windowSize.y - (130.f + (static_cast<float>(i) * 50.f)));
        plat1_3[i] = Floor(floorPos,sf::Vector2f(50.f,60.f + (static_cast<float>(i) * 100.f)));
        floorList.emplace_back(plat1_3[i]);
    }
    
    Floor plat4_6[3];
    for (int i = 0; i < std::size(plat4_6); i++)
    {
        const auto floorPos = sf::Vector2f(4700 + i * 1200.f,windowSize.y - (135.f + (i == 2 ? 35.f : 0.f)));
        plat4_6[i] = Floor(floorPos,sf::Vector2f(1000.f,75.f + (i == 2 ? 75.f : 0.f)));
        floorList.emplace_back(plat4_6[i]);
    }
    
    Floor platAir1[4];
    for (int i = 0; i < std::size(platAir1); i++)
    {
        const auto floorPos = sf::Vector2f(8300 + (i * 250.f),windowSize.y - 325.f - (i * 50));
        platAir1[i] = Floor(floorPos,sf::Vector2f(50.f,25.f));
        floorList.emplace_back(platAir1[i]);
    }

    Floor platAir2[4];
    for (int i = 0; i < static_cast<int>(std::size(platAir2)); i++)
    {
        const auto floorPos = sf::Vector2f(9800 + (i * 50.f),300.f);
        platAir2[i] = Floor(floorPos,sf::Vector2f(50.f,25.f));
        floorList.emplace_back(platAir2[i]);
    }

    Floor platAir3[2];
    for (int i = 0; i < std::size(platAir3); i++)
    {
        const auto floorPos = sf::Vector2f(10300 + (i * 100.f),300.f);
        platAir3[i] = Floor(floorPos,sf::Vector2f(100.f,25.f));
        floorList.emplace_back(platAir3[i]);
    }

    Floor platAir4[2];
    for (int i = 0; i < std::size(platAir4); i++)
    {
        const auto floorPos = sf::Vector2f(11400 + (i * 100.f),390.f);
        platAir4[i] = Floor(floorPos,sf::Vector2f(100.f,25.f));
        floorList.emplace_back(platAir4[i]);
    }

    Floor platAir5[3];
    for (int i = 0; i < std::size(platAir5); i++)
    {
        const auto floorPos = sf::Vector2f(13250 + (i * 450.f + (i == 2 ? 100.f : 0.f)), 525.f + i * 100.f);
        platAir5[i] = Floor(floorPos,sf::Vector2f(300.f + (i * 100.f),25.f));
        floorList.emplace_back(platAir5[i]);
    }

    Floor platAir6[6];
    for (int i = 0; i < std::size(platAir6); i++)
    {
        const auto floorPos = sf::Vector2f(14650 + (i * 250.f), 725.f - i * 100.f);
        platAir6[i] = Floor(floorPos,sf::Vector2f(50.f,25.f));
        floorList.emplace_back(platAir6[i]);
    }
    
    for (auto &floor : floorList)
    {
        floor.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        floor.Init();
    }
}

void LevelScene::CreateWinPortal()
{
    const auto winSize = sf::Vector2f(50.f,200.f);
    const auto winPos = sf::Vector2f(17750.f,400.f);
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
