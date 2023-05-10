#pragma once
#include <string>

class SaveFile final
{

#pragma region Settings
    
public:
    static void SaveSettings(float soundVolume, float musicVolume, bool bVsync, bool bFps);
    static void LoadSettings(float& soundVolume, float& musicVolume, bool& bVsync, bool& bFps);

private:
    static std::string settingsFileName;

#pragma endregion 

#pragma region Data
    
public:
    static void SaveData(int coins, int usedCoins, int tex);
    static void LoadData(int& coins, int& usedCoins, int& tex);

private:
    static std::string dataFileName;

#pragma endregion 

#pragma region ButtonState

public:
    static void SaveButtonState(bool b1, int b2, int b3);
    static void LoadButtonState(bool& b1, bool& b2, bool& b3);

private:
    static std::string buttonStateFileName;

#pragma endregion
    
};
