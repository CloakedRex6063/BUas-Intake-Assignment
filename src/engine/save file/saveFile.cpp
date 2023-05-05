#include "saveFile.h"
#include <fstream>
#include <iostream>

std::string SaveFile::filename = "data.txt";

void SaveFile::SaveData(float soundVolume, float musicVolume, bool bVsync, bool bFps)
{
    std::ofstream outFile;
    outFile.open(filename);
    outFile << soundVolume << std::endl;
    outFile << musicVolume << std::endl;
    outFile << bVsync << std::endl;
    outFile << bFps << std::endl;
    outFile.close();
}

void SaveFile::LoadData(float& soundVolume, float& musicVolume, bool& bVsync, bool& bFps)
{
    std::ifstream inFile;
    inFile.open(filename);
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
        SaveData(0.5f,0.5f,false, true);
        LoadData(soundVolume,musicVolume, bVsync, bFps);
        inFile.close();
    }
}
