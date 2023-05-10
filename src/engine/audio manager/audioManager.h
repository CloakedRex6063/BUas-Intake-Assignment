#pragma once
#include "../enums/enums.h"
#include "SFML/Audio.hpp"

class AudioManager final
{

#pragma region Required
    
public:
    static void Init();
    static void OnClose();

private:
    static sf::SoundBuffer* deathBuffer;
    static sf::SoundBuffer* hoverBuffer;
    static sf::SoundBuffer* clickBuffer;

    static sf::Sound* playSound;
    static sf::Music* playMusic;

#pragma endregion 

#pragma region MusicControl

public:
    static void PlayMusic(MusicType music);
    static void PauseMusic();
    static void ResumeMusic();
    static void StopMusic();

#pragma endregion

#pragma region SoundControl
    
    static void PlaySound(SoundType sound);
    
#pragma endregion 
    
#pragma region Volume
    
    static float GetSoundVolume() {return playSound->getVolume()/100.f;}
    static void SetSoundVolume(float newValue) {playSound->setVolume(newValue * 100.f);}
    static float GetMusicVolume() {return playMusic->getVolume()/100.f;}
    static void SetMusicVolume(float newValue) {playMusic->setVolume(newValue * 100.f);}

#pragma endregion
    
};
