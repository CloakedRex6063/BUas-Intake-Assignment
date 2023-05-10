#include "saveFile.h"
#include <fstream>
#include <iostream>

#pragma region Static Initialisation

std::string SaveFile::settingsFileName = "settings.txt";
std::string SaveFile::dataFileName = "data.txt";
std::string SaveFile::buttonStateFileName = "buttonState.txt";

#pragma endregion

#pragma region Settings

void SaveFile::SaveSettings(float soundVolume, float musicVolume, bool bVsync, bool bFps)
{
    std::ofstream outFile;
    outFile.open(settingsFileName);
    outFile << soundVolume << std::endl;
    outFile << musicVolume << std::endl;
    outFile << bVsync << std::endl;
    outFile << bFps << std::endl;
    outFile.close();
}

void SaveFile::LoadSettings(float& soundVolume, float& musicVolume, bool& bVsync, bool& bFps)
{
    std::ifstream inFile;
    inFile.open(settingsFileName);
    if(inFile.is_open())
    {
        inFile >> soundVolume;
        inFile >> musicVolume;
        inFile >> bVsync;
        inFile >> bFps;
        inFile.close();
    }
    else
    {
        SaveSettings(0.5f,0.5f,false, true);
        LoadSettings(soundVolume,musicVolume, bVsync, bFps);
        inFile.close();
    }
}

#pragma endregion

#pragma region SaveData

void SaveFile::SaveData(int coins, int usedCoins, int tex)
{
    std::ofstream outFile;
    outFile.open(dataFileName);
    outFile << coins << std::endl;
    outFile << usedCoins << std::endl;
    outFile << tex << std::endl;
    outFile.close();
}

void SaveFile::LoadData(int& coins, int& usedCoins, int& tex)
{
    std::ifstream inFile;
    inFile.open(dataFileName);
    if(inFile.is_open())
    {
        inFile >> coins;
        inFile >> usedCoins;
        inFile >> tex;
        inFile.close();
    }
    else
    {
        SaveData(0,0,0);
        LoadData(coins,usedCoins,tex);
        inFile.close();
    }
}

#pragma endregion

#pragma region ButtonState

void SaveFile::SaveButtonState(bool b1, int b2, int b3)
{
    std::ofstream outFile;
    outFile.open(buttonStateFileName);
    outFile << b1 << std::endl;
    outFile << b2 << std::endl;
    outFile << b3 << std::endl;
    outFile.close();
}

void SaveFile::LoadButtonState(bool& b1, bool& b2, bool& b3)
{
    std::ifstream inFile;
    inFile.open(buttonStateFileName);
    if(inFile.is_open())
    {
        inFile >> b1;
        inFile >> b2;
        inFile >> b3;
        inFile.close();
    }
    else
    {
        SaveButtonState(true,true,true);
        LoadButtonState(b1,b2,b3);
        inFile.close();
    }
}

#pragma endregion 
