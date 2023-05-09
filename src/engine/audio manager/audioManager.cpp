#include "audioManager.h"

#include <thread>

sf::SoundBuffer* AudioManager::hoverBuffer = new sf::SoundBuffer();
sf::SoundBuffer* AudioManager::clickBuffer = new sf::SoundBuffer();
sf::SoundBuffer* AudioManager::deathBuffer = new sf::SoundBuffer();
sf::Sound* AudioManager::playSound = new sf::Sound();
sf::Music* AudioManager::playMusic = new sf::Music();

void AudioManager::Init()
{
    hoverBuffer = new sf::SoundBuffer();
    hoverBuffer->loadFromFile("Assets/Sounds/SFX/MouseHover.ogg");
    clickBuffer = new sf::SoundBuffer();
    clickBuffer->loadFromFile("Assets/Sounds/SFX/MouseClick.ogg");
    deathBuffer = new sf::SoundBuffer();
    deathBuffer->loadFromFile("Assets/Sounds/SFX/Death.ogg");
}

void AudioManager::PlayMusic(MusicType music)
{
    switch (music)
    {
    case MenuMusic_Type:
        playMusic->openFromFile("Assets/Sounds/Music/Menu.ogg");
        break;
    case LevelMusic_Type:
        playMusic->openFromFile("Assets/Sounds/Music/Level.ogg");
        break;
    } 
    playMusic->play();
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
        playSound->setBuffer(*deathBuffer);
        playSound->play();
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

