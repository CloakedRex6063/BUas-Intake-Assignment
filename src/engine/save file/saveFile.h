#pragma once
#include <string>

class SaveFile
{
public:
    static void SaveSettings(float soundVolume, float musicVolume, bool bVsync, bool bFps);
    static void LoadSettings(float& soundVolume, float& musicVolume, bool& bVsync, bool& bFps);

    static void SaveData(int coins, int usedCoins, int tex);
    static void LoadData(int& coins, int& usedCoins, int& tex);

    static void SaveButtonState(bool b1, int b2, int b3);
    static void LoadButtonState(bool& b1, bool& b2, bool& b3);

    static std::string settingsFileName;
    static std::string dataFileName;
    static std::string buttonStateFileName;
};
