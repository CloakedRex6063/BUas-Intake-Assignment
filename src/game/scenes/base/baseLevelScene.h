#pragma once
#include "baseScene.h"
#include "../../Floor/floor.h"
#include "../../obstacles/spike.h"
#include "../../pickups/pickup.h"
#include "../../player/player.h"
#include "../../winPortal/winPortal.h"


class BaseLevelScene : public BaseScene
{
public:
    ~BaseLevelScene();
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

    std::function<void()> pauseGame;
    void CreateButtons() override;
    void BindButtons() override;
    
    void CreateText() override;
    
    void ViewUpdate();
    void CollisionCheck();
    void AddSpikeLine(const sf::Vector2f& startPos, int numSpikes, sf::Vector2f spikeGaps, float spikeRadius);

    float GetProgress() const;
    void ShowProgress();

private:
    static int jumps;
    
public:
    static int GetJumps();
    static void SetJumps(int newJumps);
    static sf::Vector2f Multiply(sf::Vector2f vector1,sf::Vector2f vector2);
};
