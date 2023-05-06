﻿#pragma once
#include "../base/baseLevelScene.h"

class LevelScene final : public BaseLevelScene
{
public:
    ~LevelScene() override {}

protected:
    void CreatePickups() override;
    void CreateObstacles() override;
    void CreateFloor() override;
    void CreateWinPortal() override;
    void CreatePlayer() override;
};
