#include "audioManager.h"

#include <thread>

sf::SoundBuffer* AudioManager::hoverBuffer = nullptr;
sf::SoundBuffer* AudioManager::clickBuffer = nullptr;
sf::SoundBuffer* AudioManager::deathBuffer = nullptr;
sf::Sound* AudioManager::playSound = nullptr;
sf::Music* AudioManager::playMusic = nullptr;

void AudioManager::Init()
{
    hoverBuffer = new sf::SoundBuffer();
    hoverBuffer->loadFromFile("Assets/Sounds/SFX/MouseHover.wav");
    clickBuffer = new sf::SoundBuffer();
    clickBuffer->loadFromFile("Assets/Sounds/SFX/MouseClick.wav");
    //deathBuffer = new sf::SoundBuffer();
    //deathBuffer->loadFromFile("Assets/Sounds/SFX/Death.wav");
    playSound = new sf::Sound();
    playMusic = new sf::Music();
}

void AudioManager::PlayMusic(MusicType music, float delay)
{
    switch (music)
    {
    case MenuMusic_Type:
        playMusic->openFromFile("Assets/Sounds/Music/Menu.wav");
        break;
    case LevelMusic_Type:
        playMusic->openFromFile("Assets/Sounds/Music/Level.wav");
        break;
    }
    
    std::thread audioThread ([delay]
    {
        std::this_thread::sleep_for(std::chrono::duration<float>(delay));
        playMusic->play();
    });
    audioThread.detach();
}

void AudioManager::PauseMusic()
{
    playMusic->pause();
}

void AudioManager::ResumeMusic()
{
    playMusic->play();
}

void AudioManager::StopMusic()
{
    playMusic->stop();
}

void AudioManager::PlaySound(SoundType sound)
{
    switch (sound)
    {
    case HoverSound_Type:
        playSound->setBuffer(*hoverBuffer);
        playSound->play();
        break;
    case ClickSound_Type:
        playSound->setBuffer(*clickBuffer);
        playSound->play();
        break;
    case DeathSound_Type:
        break;
    }
}

void AudioManager::OnClose()
{
    StopMusic();
    delete playSound;
    delete playMusic;
    delete deathBuffer;
    delete hoverBuffer;
    delete clickBuffer;
}

