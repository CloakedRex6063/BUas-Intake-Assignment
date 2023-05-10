#include "levelScene.h"
#include "../../../engine/structs/structs.h"
#include "../../obstacles/spike.h"

#pragma region LevelData

#pragma region Obstacles

void LevelScene::CreateObstacles()
{
    const auto windowSize = static_cast<sf::Vector2f>(GetWindow()->getSize());
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
    
    AddSpikeLine(sf::Vector2f(9815,370.f),4,sf::Vector2f(50.f,0.f),30.f);
    
    AddSpikeLine(sf::Vector2f(10415,370.f),4,sf::Vector2f(50.f,0.f),30.f);
    
    AddSpikeLine(sf::Vector2f(11410,350.f),4,sf::Vector2f(50.f,0.f),30.f);
    
    obstacleData.insert(obstacleData.end(),
{
        {sf::Vector2f(12340.f, windowSize.y - 440.f), 40.f},
        {sf::Vector2f(12415.f, windowSize.y - 340.f), 40.f},
        {sf::Vector2f(13490.f, windowSize.y - 330.f), 40.f},
        {sf::Vector2f(15910.f, 185.f), 30.f}
    });

    AddSpikeLine(sf::Vector2f(19320,GetWindow()->getSize().y - 50.f),10,sf::Vector2f(90.f,0.f),50.f);
    AddSpikeLine(sf::Vector2f(20870,150.f),10,sf::Vector2f(90.f,0.f),-50.f);
    AddSpikeLine(sf::Vector2f(22320,GetWindow()->getSize().y - 50.f),10,sf::Vector2f(90.f,0.f),50.f);
    AddSpikeLine(sf::Vector2f(22370,150.f),10,sf::Vector2f(90.f,0.f),-50.f);
    AddSpikeLine(sf::Vector2f(23870,150.f),10,sf::Vector2f(90.f,0.f),-50.f);

    obstacleData.insert(obstacleData.end(),
{
        {sf::Vector2f(32500.f, windowSize.y - 90.f), 40.f},
        {sf::Vector2f(32560.f, windowSize.y - 90.f), 40.f},
    });

    AddSpikeLine(sf::Vector2f(32710,windowSize.y - 80.f),7,sf::Vector2f(50.f,0.f),30.f);

    obstacleData.insert(obstacleData.end(),
{
        {sf::Vector2f(34200.f, windowSize.y - 90.f), 40.f},
        {sf::Vector2f(34260.f, windowSize.y - 90.f), 40.f},
        {sf::Vector2f(35000.f, windowSize.y - 90.f), 40.f},
        {sf::Vector2f(35040.f, windowSize.y/2.f), -40.f},
        {sf::Vector2f(35500.f, windowSize.y - 90.f), 40.f},
        {sf::Vector2f(35540.f, windowSize.y/2.f), -40.f},
        {sf::Vector2f(35570.f, windowSize.y - 90.f), 40.f},
        {sf::Vector2f(35610.f, windowSize.y/2.f), -40.f},
        {sf::Vector2f(36000.f, windowSize.y - 90.f), 40.f},
        {sf::Vector2f(36040.f, windowSize.y/2.f), -40.f},
        {sf::Vector2f(36070.f, windowSize.y - 90.f), 40.f},
        {sf::Vector2f(36110.f, windowSize.y/2.f), -40.f},
    });

    AddSpikeLine(sf::Vector2f(33220,windowSize.y - 80.f),16,sf::Vector2f(50.f,0.f),30.f);

    obstacleData.insert(obstacleData.end(),{sf::Vector2f(37800.f, windowSize.y - 240.f), 40.f});

    AddSpikeLine(sf::Vector2f(41620,GetWindow()->getSize().y - 100.f),10,sf::Vector2f(90.f,0.f),50.f);
    AddSpikeLine(sf::Vector2f(43670,100.f),10,sf::Vector2f(90.f,0.f),-50.f);
    AddSpikeLine(sf::Vector2f(45620,GetWindow()->getSize().y - 100.f),10,sf::Vector2f(90.f,0.f),50.f);
    AddSpikeLine(sf::Vector2f(45670,100.f),10,sf::Vector2f(90.f,0.f),-50.f);
    
    for (const auto& data : obstacleData)
    {
        auto obstacle = Spike(data.position, data.radius);
        obsList.emplace_back(obstacle);
    }
}

#pragma endregion

#pragma region Floors

void LevelScene::CreateFloor()
{
    const auto windowSize = static_cast<sf::Vector2f>(GetWindow()->getSize());
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
{
        {sf::Vector2f(4700.f,windowSize.y - 50.f),sf::Vector2f(1000.f,300.f),
                sf::Vector2f(0.5f,0.5f),GetGame().floor1Tex},
        {sf::Vector2f(5700.f,windowSize.y - 50.f),sf::Vector2f(200.f,100.f),
                sf::Vector2f(0.5f,0.5f),GetGame().floor1Tex},
        {sf::Vector2f(5900.f,windowSize.y - 50.f),sf::Vector2f(1000.f,300.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor1Tex},
        {sf::Vector2f(6900.f,windowSize.y - 50.f),sf::Vector2f(200.f,100.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor1Tex},
        {sf::Vector2f(7100.f,windowSize.y - 150.f),sf::Vector2f(1000.f,300.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor1Tex},
    });

    const auto Line2Pos = sf::Vector2f(8350.f,windowSize.y - 325.f);
    const auto Line2Gaps = sf::Vector2f(275.f,-50.f);
    const auto Line2Size = sf::Vector2f(50.f,25.f);
    const auto Line2Increase = sf::Vector2f(0.f,0.f);
    const auto Line2TexMult = sf::Vector2f(1.f,2.f);
    AddFloorLine(Line2Pos,4,Line2Gaps,Line2Size,Line2Increase,Line2TexMult,GetGame().floor1Tex);

    floorData.insert(floorData.end(),
{
        {sf::Vector2f(9400,windowSize.y),sf::Vector2f(1600.f,800.f),
            sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
        {sf::Vector2f(9800.f,300.f),sf::Vector2f(200.f,25.f),
            sf::Vector2f(1.f,2.f), GetGame().floor1Tex},
        {sf::Vector2f(10400.f,300.f),sf::Vector2f(200.f,25.f),
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
    
    const auto Line3Pos = sf::Vector2f(13250.f,525.f);
    const auto Line3Gaps = sf::Vector2f(450.f,100.f);
    const auto Line3Size = sf::Vector2f(300.f,25.f);
    const auto Line3Increase = sf::Vector2f(100.f,0.f);
    const auto Line3TexMult = sf::Vector2f(1.f,2.f);
    AddFloorLine(Line3Pos,2,Line3Gaps,Line3Size,Line3Increase,Line3TexMult,GetGame().floor1Tex);

    floorData.insert(floorData.end(),
{sf::Vector2f(14250.f,725.f),sf::Vector2f(500.f,25.f),
                sf::Vector2f(1.f,1.f), GetGame().floor1Tex});

    const auto Line4Pos = sf::Vector2f(14650.f,725.f);
    const auto Line4Gaps = sf::Vector2f(250.f,-100.f);
    const auto Line4Size = sf::Vector2f(50.f,25.f);
    const auto Line4Increase = sf::Vector2f(0.f,0.f);
    const auto Line4TexMult = sf::Vector2f(1.f,2.f);
    AddFloorLine(Line4Pos,6,Line4Gaps,Line4Size,Line4Increase,Line4TexMult,GetGame().floor1Tex);

    floorData.insert(floorData.end(),
{
    {sf::Vector2f(15800.f,windowSize.y),sf::Vector2f(2000.f,500.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(16200.f,200.f),sf::Vector2f(1200.f,400.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(17400,150.f),sf::Vector2f(400,300.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(17800,windowSize.y + 50.f),sf::Vector2f(7500,100.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(17800,0.f),sf::Vector2f(7500,200.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex}
    });

    floorData.insert(floorData.end(),
{
    {sf::Vector2f(19200,windowSize.y - 50.f),sf::Vector2f(100.f,100.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(20200,windowSize.y - 50.f),sf::Vector2f(100.f,100.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(20700,150.f),sf::Vector2f(100.f,100.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(21700,150.f),sf::Vector2f(100.f,100.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(22200,windowSize.y - 100.f),sf::Vector2f(100.f,200.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(22200,200.f),sf::Vector2f(100.f,200.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(23200,windowSize.y - 50.f),sf::Vector2f(100.f,100.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(23200,150.f),sf::Vector2f(100.f,100.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(23700,250.f),sf::Vector2f(100.f,300.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(24700,150.f),sf::Vector2f(100.f,100.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(25300,GetWindow()->getSize().y - 100.f),sf::Vector2f(1500.f,300.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex},
    {sf::Vector2f(25300,150.f),sf::Vector2f(1500.f,300.f),
        sf::Vector2f(0.5f,0.5f), GetGame().floor1Tex}
    }
    );

    floorData.insert(floorData.begin(),
{sf::Vector2f(26800,windowSize.y),sf::Vector2f(1000.f,300.f),
        sf::Vector2f(0.5f,0.5f),GetGame().floor1Tex});

    AddFloorLine(sf::Vector2f(28050,windowSize.y),3,sf::Vector2f(250.f,-50.f),
        sf::Vector2f(50.f,300.f),sf::Vector2f(0.f,100.f),sf::Vector2f(1.f,1.f),GetGame().floor2Tex);

    floorData.insert(floorData.begin(),
{
    {sf::Vector2f(28825,GetWindow()->getSize().y/2.f + 100.f),sf::Vector2f(50.f,200.f),
            sf::Vector2f(1.f,1.f),GetGame().floor2Tex},
    {sf::Vector2f(28825,windowSize.y),sf::Vector2f(500.f,200.f),
        sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
    }
    );

    AddFloorLine(sf::Vector2f(29550,windowSize.y),5,sf::Vector2f(250.f,-50.f),
        sf::Vector2f(50.f,300.f),sf::Vector2f(0.f,100.f),sf::Vector2f(1.f,1.f),GetGame().floor2Tex);

    AddFloorLine(sf::Vector2f(30600,262.f),3,sf::Vector2f(200.f,150.f),
        sf::Vector2f(100.f,25.f),sf::Vector2f(50.f,0.f),sf::Vector2f(1.f,1.f),GetGame().floor2Tex);

    floorData.insert(floorData.begin(),
    {
        {sf::Vector2f(31400.f,windowSize.y),sf::Vector2f(200.f,300.f),
                sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(31800.f,windowSize.y),sf::Vector2f(18200.f,100.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(32620.f,windowSize.y - 90.f),sf::Vector2f(80.f,80.f),
            sf::Vector2f(0.625f,0.625f),GetGame().floor2Tex},
        {sf::Vector2f(32800.f,windowSize.y - 150.f),sf::Vector2f(200.f,25.f),
            sf::Vector2f(1.f,2.f),GetGame().floor2Tex},
        {sf::Vector2f(33050.f,windowSize.y - 90.f),sf::Vector2f(160.f,80.f),
            sf::Vector2f(0.625f,0.625f),GetGame().floor2Tex},
        {sf::Vector2f(33375.f,windowSize.y - 150.f),sf::Vector2f(200.f,25.f),
            sf::Vector2f(1.f,2.f),GetGame().floor2Tex},
        {sf::Vector2f(33700.f,windowSize.y - 200.f),sf::Vector2f(200.f,25.f),
            sf::Vector2f(1.f,2.f),GetGame().floor2Tex},
        {sf::Vector2f(34020.f,windowSize.y - 90.f),sf::Vector2f(160.f,80.f),
            sf::Vector2f(0.625f,0.625f),GetGame().floor2Tex},
        {sf::Vector2f(34980.f,320.f),sf::Vector2f(80.f,80.f),
            sf::Vector2f(0.625f,0.625f),GetGame().floor2Tex},
        {sf::Vector2f(35475.f,320.f),sf::Vector2f(160.f,80.f),
            sf::Vector2f(0.625f,0.625f),GetGame().floor2Tex},
        {sf::Vector2f(35975.f,320.f),sf::Vector2f(160.f,80.f),
            sf::Vector2f(0.625f,0.625f),GetGame().floor2Tex},
    }
    );

    AddFloorLine(sf::Vector2f(36500,windowSize.y - 125.f),3,sf::Vector2f(250.f,-100.f),
        sf::Vector2f(150.f,25.f),sf::Vector2f(0.f,0.f),sf::Vector2f(1.f,2.f),GetGame().floor2Tex);
    AddFloorLine(sf::Vector2f(37150,windowSize.y - 250.f),3,sf::Vector2f(160.f,80.f),
        sf::Vector2f(80.f,80.f),sf::Vector2f(0.f,0.f),sf::Vector2f(0.625f,0.625f),GetGame().floor1Tex);
    AddFloorLine(sf::Vector2f(37300,windowSize.y/ 2.f),4,sf::Vector2f(160.f,80.f),
        sf::Vector2f(80.f,80.f),sf::Vector2f(0.f,0.f),sf::Vector2f(0.625f,0.625f),GetGame().floor1Tex);

    floorData.insert(floorData.end(),
{
        {sf::Vector2f(39000.f,windowSize.y - 100.f),sf::Vector2f(200.f,100.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(39200.f,windowSize.y - 150.f),sf::Vector2f(1200.f,200.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(39400.f,150.f),sf::Vector2f(1000.f,300.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(40400.f,0.f),sf::Vector2f(9600.f,100.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex}
    });

    floorData.insert(floorData.end(),
{
        {sf::Vector2f(41500.f,windowSize.y - 100.f),sf::Vector2f(100.f,100.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(42500.f,windowSize.y - 200.f),sf::Vector2f(100.f,300.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(43500.f,200.f),sf::Vector2f(100.f,300.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(44500.f,100.f),sf::Vector2f(100.f,100.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(45500.f,windowSize.y - 100.f),sf::Vector2f(100.f,100.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(45500.f,200.f),sf::Vector2f(100.f,300.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(46500.f,windowSize.y - 150.f),sf::Vector2f(100.f,200.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
        {sf::Vector2f(46500.f,150.f),sf::Vector2f(100.f,200.f),
            sf::Vector2f(0.5f,0.5f),GetGame().floor2Tex},
    });
    
    for (const auto& data : floorData)
    {
        const auto texMultiplier = sf::Vector2i(static_cast<int>(data.size.x * data.texSize.x), static_cast<int>(data.size.y * data.texSize.y));
        auto floor = Floor(data.position, data.size, texMultiplier,GetGame().floor1Tex);
        floorList.emplace_back(floor);
    }
}

#pragma endregion

#pragma region WinPortal

void LevelScene::CreateWinPortal()
{
    const auto winSize = sf::Vector2f(100.f,700.f);
    const auto winPos = sf::Vector2f(47450.f,400.f);
    winPortal = new WinPortal(winPos,winSize,GetGame().winPortalTex);
}

#pragma endregion

#pragma region FlyPortal

void LevelScene::CreateFlyPortal()
{
    const auto portal1Size = sf::Vector2f(50.f,250.f);
    const auto portal1Pos = sf::Vector2f(17775.f,425.f);
    auto portal1 = FlyPortal(portal1Pos,portal1Size,true,GetGame().flyPortalTex);
    const auto portal2Size = sf::Vector2f(50.f,250.f);
    const auto portal2Pos = sf::Vector2f(25325.f,425.f);
    auto portal2 = FlyPortal(portal2Pos,portal2Size,false,GetGame().flyPortalTex);
    const auto portal3Size = sf::Vector2f(50.f,250.f);
    const auto portal3Pos = sf::Vector2f(40375.f,425.f);
    auto portal3 = FlyPortal(portal3Pos,portal3Size,true,GetGame().flyPortalTex);
    flyPortalList.emplace_back(portal1);
    flyPortalList.emplace_back(portal2);
    flyPortalList.emplace_back(portal3);
}

#pragma endregion

#pragma region CheckPoints

void LevelScene::CreateCheckpoints()
{
    const auto windowSize = static_cast<sf::Vector2f>(GetWindow()->getSize());
    auto check1 = CheckPoint(sf::Vector2f(7200.f, windowSize.y - 340.f),sf::Vector2f(75.f,75.f),GetGame().checkPointTex);
    auto check2 = CheckPoint(sf::Vector2f(16250.f,windowSize.y/2.f + 100.f),sf::Vector2f(75.f,75.f),GetGame().checkPointTex);
    auto check3 = CheckPoint(sf::Vector2f(25625.f,windowSize.y/2.f + 100.f),sf::Vector2f(75.f,75.f),GetGame().checkPointTex);
    auto check4 = CheckPoint(sf::Vector2f(39500.f, windowSize.y/2.f + 100.f),sf::Vector2f(75.f,75.f),GetGame().checkPointTex);
    checkpointList.emplace_back(check1);
    checkpointList.emplace_back(check2);
    checkpointList.emplace_back(check3);
    checkpointList.emplace_back(check4);
}

void LevelScene::CreateCheckpointHint()
{
    auto pos = sf::Vector2f(GetWindow()->getSize().x/2.f - 225.f, 50.f);
    pos.x -= 5.f;

    for (int i = 0; i < 4; ++i)
    {
        auto hint = sf::RectangleShape(sf::Vector2f(5.f, 20.f));
        const auto prog = checkpointList[i].GetSprite().getPosition().x / winPortal->GetSprite().getPosition().x;
        hint.setFillColor(sf::Color::Red);
        hint.setPosition(pos);
        hint.move(prog * 400.f, 0.f);
        checkHintList.emplace_back(hint);
    }
}

#pragma endregion 

#pragma region Pickups

void LevelScene::CreatePickups()
{
    const auto windowSize = static_cast<sf::Vector2f>(GetWindow()->getSize());
    auto pickup1 = Pickup(sf::Vector2f(3750,windowSize.y - 125.f),25.f,GetGame().coinTex);
    auto pickup2 = Pickup(sf::Vector2f(28850,windowSize.y - 125.f),25.f,GetGame().coinTex);
    auto pickup3 = Pickup(sf::Vector2f(37820,windowSize.y/2.f),25.f,GetGame().coinTex);
    pickupList.emplace_back(pickup1);
    pickupList.emplace_back(pickup2);
    pickupList.emplace_back(pickup3);
}

#pragma endregion 

#pragma endregion

