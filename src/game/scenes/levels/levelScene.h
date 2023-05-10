#pragma once
#include "../base/baseLevelScene.h"

class LevelScene final : public BaseLevelScene
{
    
#pragma region LevelData

protected:

#pragma region CheckPoints

    void CreateCheckpoints() override;
    void CreateCheckpointHint() override;
    
#pragma endregion 
    
#pragma region Pickups
    
    void CreatePickups() override;

#pragma endregion 
    
#pragma region Obstacles
    
    void CreateObstacles() override;

#pragma endregion

#pragma region Floors
    
    void CreateFloor() override;

#pragma endregion

#pragma region WinPortal
    
    void CreateWinPortal() override;

#pragma endregion

#pragma region FlyPortal
    
    void CreateFlyPortal() override;

#pragma endregion 

#pragma endregion
    
};
