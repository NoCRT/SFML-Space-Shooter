#include "../Header Files/SoundManager.h"

SoundManager::SoundManager(std::string soundFile)
{
    SetSoundBuffer(soundFile);
    sound.setVolume(25);
}

void SoundManager::SetSoundBuffer(std::string soundPath)
{
    path = soundPath;
    soundBuffer.loadFromFile(path);
    sound.setBuffer(soundBuffer);
}

void SoundManager::Update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    { // _sound effect vol down
        if (sound.getVolume() >= 1.f)
        {
            sound.setVolume(sound.getVolume() - 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        {
            sound.setVolume(0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (sound.getVolume() < 100.f)
        {
            sound.setVolume(sound.getVolume() + 1);
        }
    }
}

bool SoundManager::BufferContains(std::string buffer)
{
    return path == buffer;
}

void SoundManager::BufferReplace(std::string checkBuffer)
{
    if (!BufferContains(checkBuffer))
    {
        SetSoundBuffer(checkBuffer);
    }
}

void SoundManager::PlaySound()
{
    sound.play();
}

const sf::SoundSource::Status SoundManager::GetStatus()
{
    return sound.getStatus();
}

const std::string SoundManager::GetPath()
{
    return path;
}

sf::Sound* SoundManager::GetSound()
{
    return &sound;
}

