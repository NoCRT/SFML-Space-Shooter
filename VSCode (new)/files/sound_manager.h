#ifndef FILES_SOUND_MANAGER_H
#define FILES_SOUND_MANAGER_H

#include "generic_include.h"

class SoundManager final
{
public:
    explicit SoundManager(std::string soundFile);
    void SetSoundBuffer(std::string soundPath);
    void Update();
    bool BufferContains(std::string buffer);
    void BufferReplace(std::string checkBuffer);
    void PlaySound();
    const sf::SoundSource::Status GetStatus();
    const std::string GetPath();
    sf::Sound *GetSound();

private:
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
    std::string path;
};

class MusicManager final
{
public:
    explicit MusicManager(std::string musicPath);
    void SetMusicPath(std::string musicPath);
    void Update();
    void PlayMusic();
    sf::SoundSource::Status GetStatus();
    const std::string GetPath();
    sf::Music *GetMusic();

private:
    sf::Music music;
    std::string path;
};

#endif //FILES_SOUND_MANAGER_H
