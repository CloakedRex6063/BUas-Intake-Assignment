#pragma once
#include "enums.h"
#include "object.h"

class AudioManager final
{
public:
    static void Init();
    static void PlayMusic(MusicType music, float delay);
    static void StopMusic();
    static void PlaySound(SoundType sound);
    static float GetSoundVolume() {return playSound->getVolume();}
    static void SetSoundVolume(float newValue) {playSound->setVolume(newValue);}
    static float GetMusicVolume() {return playMusic->getVolume();}
    static void SetMusicVolume(float newValue) {playMusic->setVolume(newValue);}

private:
    static float musicVolume;
    static float soundVolume;
    
    static sf::SoundBuffer* deathBuffer;
    static sf::SoundBuffer* hoverBuffer;
    static sf::SoundBuffer* clickBuffer;

    static sf::Sound* playSound;
    static sf::Music* playMusic;
};
