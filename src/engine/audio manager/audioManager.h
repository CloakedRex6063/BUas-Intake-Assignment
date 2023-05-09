#pragma once
#include "../enums/enums.h"
#include "../object.h"

class AudioManager final
{
public:
    static void Init();
    static void PlayMusic(MusicType music);
    static void PauseMusic();
    static void ResumeMusic();
    static void StopMusic();
    static void PlaySound(SoundType sound);
    static void OnClose();
    static float GetSoundVolume() {return playSound->getVolume()/100.f;}
    static void SetSoundVolume(float newValue) {playSound->setVolume(newValue * 100.f);}
    static float GetMusicVolume() {return playMusic->getVolume()/100.f;}
    static void SetMusicVolume(float newValue) {playMusic->setVolume(newValue * 100.f);}

private:
    static sf::SoundBuffer* deathBuffer;
    static sf::SoundBuffer* hoverBuffer;
    static sf::SoundBuffer* clickBuffer;

    static sf::Sound* playSound;
    static sf::Music* playMusic;
};
