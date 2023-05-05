#pragma once
#include <string>

class SaveFile
{
public:
    static void SaveData(float soundVolume, float musicVolume, bool bVsync, bool bFps);
    static void LoadData(float& soundVolume, float& musicVolume, bool& bVsync, bool& bFps);

    static std::string filename;
};
