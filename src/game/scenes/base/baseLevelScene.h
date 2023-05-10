#pragma once
#include "baseScene.h"
#include "../../Floor/floor.h"
#include "../../fly portal/flyPortal.h"
#include "../../obstacles/spike.h"
#include "../../pickups/pickup.h"
#include "../../player/player.h"
#include "../../win portal/winPortal.h"

class BaseLevelScene : public BaseScene
{
    
#pragma region Required
    
public:
    ~BaseLevelScene();
    void Init() override;
    void Tick(float deltaTime) override;
    void PhysicsTick(float fixedDeltaTime) override;
    void Render() override;

#pragma endregion 

#pragma region Player
    
private:
    Player* player = nullptr;
protected:
    virtual void CreatePlayer();
    void SetPlayer(Player* player) {this->player = player;}
    Player& GetPlayer() const {return *player;}
    float moveSpeed = 700;

private:
    void Die();
    
#pragma endregion

#pragma region LevelData

#pragma region CheckPoints

protected:
    std::vector<CheckPoint> checkpointList;
    virtual void CreateCheckpoints() = 0;
    std::vector<sf::RectangleShape> checkHintList;
    virtual void CreateCheckpointHint() = 0;
    
#pragma endregion 
    
#pragma region Pickups
    
    std::vector<Pickup> pickupList;
    virtual void CreatePickups() = 0;

#pragma endregion

#pragma region Obstacles

    std::vector<Spike> obsList;
    virtual void CreateObstacles() = 0;
    void AddSpikeLine(const sf::Vector2f& startPos, int numSpikes, sf::Vector2f spikeGaps, float spikeRadius);

#pragma endregion

#pragma region Floors

    std::vector<Floor> floorList;
    virtual void CreateFloor() = 0;
    void AddFloorLine(const sf::Vector2f& startPos, int numFloors, sf::Vector2f floorGaps, sf::Vector2f startSize,
        sf::Vector2f sizeIncrease, sf::Vector2f texMultiplier, sf::Texture* tex);

#pragma endregion

#pragma region WinPortal

    WinPortal* winPortal = nullptr;
    virtual void CreateWinPortal() = 0;

#pragma endregion

#pragma region FlyPortal

    std::vector<FlyPortal> flyPortalList;
    virtual void CreateFlyPortal() = 0;

#pragma endregion 

#pragma endregion

#pragma region UI

#pragma region Buttons
    
    std::function<void()> pauseGame;
    void CreateButtons() override;
    void BindButtons() override;

#pragma endregion

#pragma region Text
    
    void CreateText() override;
    
#pragma endregion

#pragma region Sliders

private:
    void CreateSliders() override;
    
protected:
    bool bStart = false;

public:
    float GetProgress() const;
    void ShowProgress();

#pragma endregion

#pragma endregion 

#pragma region ViewManipulation
    
private:
    void ViewUpdate();

#pragma endregion 

#pragma region Collision
    
    void CollisionCheck();
    void PickupCheck();
    void FloorCheck();
    void BoundsCheck();
    void ObstacleCheck();
    void CheckPointCheck();
    void FlyCheck() const;
    void WinCheck() const;
    
    bool bRestarted = false;

#pragma endregion

#pragma region Coins
    
    int coins = 0;

#pragma endregion 
    
};
