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
public:
    ~BaseLevelScene() override;
    void Init() override;
    void Tick(float deltaTime) override;
    void PhysicsTick(float fixedDeltaTime) override;
    void Render() override;

    Player& GetPlayer() const {return *player;}


protected:
    bool bStart = false;

    sf::RectangleShape progressBar;
    sf::RectangleShape progressOutLineBar;
    
    Player* player = nullptr;
    virtual void CreatePlayer() = 0;
    float moveSpeed = 700;
    
    std::vector<Pickup> pickupList;
    virtual void CreatePickups() = 0;

    std::vector<Spike> obsList;
    virtual void CreateObstacles() = 0;

    std::vector<Floor> floorList;
    virtual void CreateFloor() = 0;

    WinPortal* winPortal = nullptr;
    virtual void CreateWinPortal() = 0;

    std::vector<FlyPortal> flyPortalList;
    virtual void CreateFlyPortal() = 0;

    std::function<void()> pauseGame;
    void CreateButtons() override;
    void BindButtons() override;
    
    void CreateText() override;

private:
    void ViewUpdate();

    void Die();
    void CollisionCheck();
    void PickupCheck();
    void FloorCheck();
    void BoundsCheck();
    void ObstacleCheck();
    void FlyCheck() const;
    void WinCheck() const;
    
    bool bRestarted = false;

protected:
    void AddSpikeLine(const sf::Vector2f& startPos, int numSpikes, sf::Vector2f spikeGaps, float spikeRadius);
    void AddFloorLine(const sf::Vector2f& startPos, int numFloors, sf::Vector2f floorGaps, sf::Vector2f startSize,
        sf::Vector2f sizeIncrease, sf::Vector2f texMultiplier, sf::Texture* tex);
    
    float GetProgress() const;
    void ShowProgress();

private:
    static int jumps;
    int score = 0;
    
public:
    static int GetJumps();
    static void SetJumps(int newJumps);
};
