#ifndef FILES_SOUND_MANAGER_H
#define FILES_SOUND_MANAGER_H

#include "generic_include.h"

struct Sound
{
    Sound(sf::SoundBuffer& newBuffer, int volume = 100)
    { // copy buffer
        //buffer = sf::SoundBuffer(newBuffer);
        sound.setBuffer(newBuffer);
        printf("playing sound\n");
        sound.play();
    }
    Sound(const std::string path, int volume = 100)
    { // load from file
        buffer.loadFromFile(path);
        sound.setBuffer(buffer);
        sound.setVolume(volume);
        printf("playing sound\n");
        sound.play();
    }
    sf::Sound sound;
    sf::SoundBuffer buffer;
};

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

    // experimental
    void PlaySound(const std::string path, int volume = 100);
    void PlaySound(sf::SoundBuffer& buffer, int volume = 100);
    void AltUpdate();

private:
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
    std::string path;
    sf::Clock clock;
    
    // TAG : expermiental
    std::vector<Sound> soundQueue;
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
