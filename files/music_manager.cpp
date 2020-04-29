#include "sound_manager.h"

MusicManager::MusicManager(std::string musicPath)
{
    SetMusicPath(musicPath);
    music.setVolume(25);
}

void MusicManager::SetMusicPath(std::string musicPath)
{
    path = musicPath;
    music.openFromFile(path);
}

void MusicManager::Update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    { // music vol up
        if (music.getVolume() < 100.f)
        {
            music.setVolume(music.getVolume() + 1);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    { // music vol down
        if (music.getVolume() >= 1.f)
        {
            music.setVolume(music.getVolume() - 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        {
            music.setVolume(0);
        }
    }

    if (music.getStatus() == sf::Music::Stopped)
    {
        music.play();
    }
}

void MusicManager::PlayMusic()
{
    music.play();
}

sf::SoundSource::Status MusicManager::GetStatus()
{
    return music.getStatus();
}

const std::string MusicManager::GetPath()
{
    return path;
}

sf::Music *MusicManager::GetMusic()
{
    return &music;
}