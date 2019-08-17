#include "GameFiles/MAIN_INCLUDE.h"

enum States {
    START, PAUSED, PLAYING, CLOSING
};
States GAME_STATE = START;

int main() { // move global variables into respective classes EG: font, hud = HudElement
    int FRAME_LIMIT = 30;
    sf::Clock elapsedTime;

    SoundManager soundManager(SOUND_LASER);
    MusicManager musicManager(MUSIC_SPACE);

    unsigned int winWidth{1024};
    unsigned int winHeight{768};
    int score{0};
    bool paused = false;

    // delays
    int laserSpawnDelay{DEF_LASER_SPAWN_TIMER}; // move to laser
    int asteroidSpawnDelay{DEF_ASTEROID_SPAWN_TIMER}; // move to asteroid
    int selectedLaser{0}; // move to entity manager

    // hud
    bool drawDebugHud{false};
    sf::Font font;
    sf::Text hud;
    font.loadFromFile(FONT_GEOSANS);
    hud.setFont(font);
    hud.setCharacterSize(20);
    hud.setFillColor(sf::Color::White);

    // background
    sf::Texture image;
    sf::Sprite background;
    image.loadFromFile("Images/space.png");
    background.setTexture(image);
    background.setScale(.7f, .7f);

    // window
    std::string winTitle = "Asteroid Clone";
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), winTitle, sf::Style::Default);
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(FRAME_LIMIT);


    // generic
    std::ostringstream ss;

    // entities
    Ship ship(int(winWidth / 2), int(winHeight / 2), 1, 1);
    std::vector<Laser> laserList;
    std::vector<Asteroid> asteroidList;

    // pre load asteroids
    for (int i{0}; i < 5; i++)
    {
        Asteroid tempAsteroid(0, 0, 1.f, 1.f);
        asteroidList.emplace_back(tempAsteroid);
    }

    while (window.isOpen()) {
        auto lastFrame = elapsedTime.restart(); // get last frame time and restart clock
        auto mFT = lastFrame.asMilliseconds(); // store last frame as milliseconds

        auto fps = int((1 / lastFrame.asSeconds())); // calculate fps
        window.setTitle(winTitle + "\tFPS : " + std::to_string(fps));

        // keyboard Input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        { // close window
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
            { // draw hud
                drawDebugHud = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
            { // hide hud
                drawDebugHud = false;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            if (!paused)
            {
                paused = true;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        {
            if (paused)
            {
                paused = false;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
        {
            if (FRAME_LIMIT <= 250)
            {
                FRAME_LIMIT+= 5;
            }
            window.setFramerateLimit(FRAME_LIMIT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {
            if (FRAME_LIMIT >= 30)
            {
                FRAME_LIMIT-= 5;
            }
            window.setFramerateLimit(FRAME_LIMIT);
        }

        if (!paused) // main gameplay loop
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            { // create and reset lasers
                if (laserSpawnDelay == DEF_LASER_SPAWN_TIMER)
                {
                    Laser tempL(ship.Position().x + 20, ship.Position().y + 70, .03f, .03f);
                    if (laserList.capacity() < 3)
                    { // add new laser to list
                        laserList.emplace_back(tempL);
                        soundManager.BufferReplace(SOUND_LASER);
                        soundManager.PlaySound();
                    }
                }
                if (laserSpawnDelay == DEF_LASER_SPAWN_TIMER)
                { // reset selectedLaser
                    if (selectedLaser >= laserList.capacity() - 1)
                    {
                        selectedLaser = 0;
                    }

                    if (laserList[selectedLaser].state == EXPIRED)
                    { // reset state
                        laserList[selectedLaser].state = RENEWED;
                        soundManager.BufferReplace(SOUND_LASER);
                        soundManager.PlaySound();
                        selectedLaser++;
                    }
                }
            }
            laserSpawnDelay+= 1 / mFT; // broken
            //laserSpawnDelay--;
            if (laserSpawnDelay <= 0) // reset laser delay
            {
                laserSpawnDelay = DEF_LASER_SPAWN_TIMER;
            }


            // Update Loop
            // ship update
            if (ship.Bounds().left + ship.Bounds().width > winWidth)
            { // right bounds check
                ship.X(ship.Position().x - 2);
            }
            if (ship.Bounds().left < 0)
            { // left bounds check
                ship.X(ship.Position().x + 2);
            }
            ship.Update(mFT);

            // laser update
            for (auto &l : laserList)
            { // expire laser if it has hit window bounds
                if (l.Bounds().top < 0)
                    l.state = EXPIRED;

                if (l.state == EXPIRED)
                { // reset laser position
                    l.X(ship.Position().x + 20);
                    l.Y(ship.Position().y + 70);
                }
                l.Update(mFT); // update laser
            }

            // asteroid update w/ laser collision
            for (auto &a : asteroidList)
            {
                for (auto &l : laserList)
                { // check for laser collision
                    if (l.Bounds().intersects(a.Bounds()))
                    {
                        soundManager.BufferReplace(SOUND_ASTEROID);
                        soundManager.PlaySound();
                        a.state = EXPIRED;
                        l.state = EXPIRED;
                        l.XY(ship.Position().x + 20, ship.Position().y + 70);
                        score += 10;
                    }
                }

                if (a.Bounds().intersects(ship.Bounds()))
                { // if asteroid hits ship
                    if (ship.Collidable()) {
                        ship.Health(-1, true);
                        ship.Collidable(false);
                    }
                }

                if (a.Bounds().top > winHeight)
                { // bounds check with window height
                    soundManager.BufferReplace(SOUND_LASER_BOUNDS);
                    soundManager.PlaySound();
                    a.state = EXPIRED;
                    score -= 20;
                }

                if (a.state == EXPIRED)
                { // renew asteroid spawn timer
                    a.Collidable(false);
                    a.XY(0, 0);
                    if (asteroidSpawnDelay == DEF_ASTEROID_SPAWN_TIMER)
                    {
                        a.X(CreateRandom(0, winHeight +
                                            a.Sprite().getTexture()->getSize().x)); // stops flash upon renew
                        a.Y(0);
                        a.state = RENEWED;
                        asteroidSpawnDelay-= 1; // prevent multiple spawns on a single frame
                    }
                }
                a.Update(mFT); // update asteroid
            }

            asteroidSpawnDelay-= 1;
            if (asteroidSpawnDelay == 0)
            { // reset asteroid spawn delay
                asteroidSpawnDelay = DEF_ASTEROID_SPAWN_TIMER;
            }

            if (ship.Health() == 0)
            { // death
                std::cout << "Game Over!" << std::endl;
                musicManager.SetMusicPath(std::string()); // stop music from playing
                system("PAUSE");
                window.close();
            }
        }


        // music update
        if (musicManager.GetStatus() == sf::Music::Stopped)
        { // replay music
            musicManager.PlayMusic();
        }

        musicManager.Update();
        soundManager.Update();


        // Draw Loop
        // debugging text (causes big slowdown. needs optimising)
        if (drawDebugHud)
        {
            int lCount{1};
            for (auto &l : laserList)
            {
                ss << "Laser: " << lCount << "\tX = " << int(l.Position().x)
                   << "\tY = " << int(l.Position().y) << "\n";
                lCount++;
            }

            ss << "\nFramerate = " << fps << "\n"
               << "Score = " << score << "\n"
               << "Laser delay = " << laserSpawnDelay << "\n"
               << "Selected laser = " << selectedLaser << "\n"
               << "Asteroid spawn delay = " << asteroidSpawnDelay << "\n"
               << "Ship LCP = " << ship.LastPressedKey() << "\n"
               << "Collider timer = " << ship.ColliderTime() << "\n"
               //<< "Update timer = " << updateClock.getElapsedTime().asMilliseconds() << "\n"
               << "Player lives = " << ship.Health() << "\n\n"

               << "Current music = " << musicManager.GetPath() << "\n"
               << "Current _sound effect = " << soundManager.GetPath() << "\n"
               << "Sound effect status = " << soundManager.GetStatus() << "\n"
               << "Music volume = " << musicManager.GetMusic()->getVolume() << "\n"
               << "Sound volume = " << soundManager.GetSound()->getVolume() << std::endl;
        }
        if (!drawDebugHud)
        {
            ss << "Framerate = " << fps << "\n"
               << "Score = " << score << "\n"
               << "Health = " << ship.Health() << std::endl;
        }
        hud.setString(sf::String(ss.str())); // set hud string
        ss.str(sf::String()); // flush ss string, same as = "" (not needed if sstream is not global)

        window.clear(sf::Color(26, 128, 182, 255));
        window.draw(background);

        for (auto l: laserList) // laggy due because of need to copy data each frame
        { // draw lasers
            window.draw(l.Sprite());
        }

        for (auto a : asteroidList)
        { // draw asteroids
            window.draw(a.Sprite());
        }
        window.draw(ship.Sprite());
        window.draw(hud);
        window.display();
    }
    return EXIT_SUCCESS;
}