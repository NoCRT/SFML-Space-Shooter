#include "files/main_inlcude.h"

enum States
{
    START,
    PAUSED,
    PLAYING,
    CLOSING
};
States GAME_STATE = START;

// move global variables into respective classes EG: font, hud = HudElement
// argc = count, argv = vector
int main()
{
    PRINT("setting FRAME_LIMIT to 60");
    int FRAME_LIMIT = 60;
    sf::Clock elapsedTime;

    SoundManager soundManager(SOUND_LASER);
    MusicManager musicManager(MUSIC_SPACE);

    int score{0};
    bool paused = false;

    // delays
    int laserSpawnDelay{DEF_LASER_SPAWN_TIMER};       // move to laser
    int asteroidSpawnDelay{DEF_ASTEROID_SPAWN_TIMER}; // move to asteroid
    int selectedLaser{0};                             // move to entity manager

    // hud
    bool drawDebugHud{false};
    sf::Font font;
    sf::Text *hud = new sf::Text;
    font.loadFromFile(FONT_GEOSANS);
    hud->setFont(font);
    hud->setCharacterSize(20);
    hud->setFillColor(sf::Color::White);

    // background
    sf::Texture image;
    sf::Sprite *background = new sf::Sprite;
    image.loadFromFile("Images/space.png");
    background->setTexture(image);
    background->setScale(.7f, .7f);

    // window
    sf::String winTitle = "Asteroid Clone";
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), winTitle, sf::Style::Default);
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(FRAME_LIMIT);

    // generic
    std::ostringstream ss;

    // entities
    PRINT("creating ship");
    Ship *ship = new Ship(int(winWidth / 2), int(winHeight / 2), 1, 1);
    ship->SetHealth(3);
    std::vector<Laser *> laserList;
    std::vector<Asteroid *> asteroidList;

    // pre load asteroids
    PRINT("preloading asteroids");
    for (int i{0}; i < 3; i++)
    {
        asteroidList.emplace_back(new Asteroid(0, 0, 1.f, 1.f));
    }

    PRINT("preloading lasers");
    for (int i{0}; i < 3; i++)
    {
        laserList.emplace_back(new Laser(ship->GetPosition().x + 20, ship->GetPosition().y + 70, .03f, .03f));
    }

    PRINT("entering window.isOpen loop");
    while (window.isOpen())
    {
        auto lastFrame = elapsedTime.restart();      // store last frame time and restart clock
        auto mFT = lastFrame.asMilliseconds();       // store last frame as milliseconds
        auto fps = int((1 / lastFrame.asSeconds())); // calculate fps
        window.setTitle(winTitle + "\tFPS : " + std::to_string(fps));

        // keyboard Input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // keyboard input
        if (sf::Event::KeyPressed) // always true
        { // if a key is pass through list
            PRINT("key press detected");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            { // close window
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
            { // switch between different hud modes
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) 
                { // switch to debug text
                    drawDebugHud = true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) 
                { // switch to regular text
                    drawDebugHud = false;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) 
            { // pause game
                if (!paused)
                {
                    paused = true;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) 
            { // unpause game
                paused = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) 
            { // increase max framerate
                if (FRAME_LIMIT <= 250)
                {
                    FRAME_LIMIT += 5;
                }
                window.setFramerateLimit(FRAME_LIMIT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
            { // decrease max framerate
                if (FRAME_LIMIT >= 30)
                {
                    FRAME_LIMIT -= 5;
                }
                window.setFramerateLimit(FRAME_LIMIT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            { // increase player health
                ship->SetHealth(ship->GetHealth() + 1);
            }
        }

        if (!paused) // main gameplay loop
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            { // create and reset lasers
                if (ship->IsCollidable())
                {
                    if (laserSpawnDelay <= 0) // reset laser delay
                    {
                        laserSpawnDelay = DEF_LASER_SPAWN_TIMER;
                    }

                    if (laserSpawnDelay == DEF_LASER_SPAWN_TIMER)
                    {
                        if (selectedLaser >= laserList.size())
                        { // reset laser
                            selectedLaser = 0;
                        }

                        if (!laserList[selectedLaser]->IsActive())
                        { // reset state
                            laserList[selectedLaser]->SetActive(true);
                            soundManager.BufferReplace(SOUND_LASER);
                            soundManager.PlaySound();
                            selectedLaser++;
                        }
                    }
                }
            }

            if (laserSpawnDelay >= -1)
            { // reset laserSpawnDelay
                laserSpawnDelay -= 1 * mFT;
            }

            // Update Loop
            // ship update
            if (ship->GetBoundingBox().left + ship->GetBoundingBox().width > winWidth && ship->IsCollidable())
            { // right bounds check
                ship->SetPosX(ship->GetPosition().x - 2);
            }
            if (ship->GetBoundingBox().left < 0 && ship->IsCollidable())
            { // left bounds check
                ship->SetPosX(ship->GetPosition().x + 2);
            }
            ship->Update(mFT);

            // laser update
            for (auto &laser : laserList)
            { // expire laser if it has hit window bounds
                if (laser->GetBoundingBox().top < 0)
                {
                    laser->SetActive(false);
                }
                if (!laser->IsActive())
                { // reset laser position
                    laser->SetPosX(ship->GetPosition().x + 20);
                    laser->SetPosY(ship->GetPosition().y + 70);
                    laser->SetCollidable(false);
                }
                laser->Update(mFT); // update laser
            }

            // asteroid update w/ laser collision
            for (auto &asteroid : asteroidList)
            {
                for (auto &laser : laserList)
                { // check for laser collision
                    if (laser->IsActive())
                    {
                        if (laser->GetBoundingBox().intersects(asteroid->GetBoundingBox()))
                        { // laser collision
                            soundManager.BufferReplace(SOUND_ASTEROID);
                            soundManager.PlaySound();
                            asteroid->SetActive(false);
                            laser->SetActive(false);
                            laser->SetPosA(ship->GetPosition().x + 20, ship->GetPosition().y + 70);
                            score += 10;
                        }
                    }
                }
                if (asteroid->GetBoundingBox().intersects(ship->GetBoundingBox()))
                { // if asteroid hits ship
                    if (ship->IsCollidable())
                    {
                        PRINT("ship collision with asteroid\n setting collidable to false");
                        ship->SetHealth(ship->GetHealth() - 1);
                        ship->SetCollidable(false);
                    }
                }

                if (asteroid->GetBoundingBox().top > winHeight)
                { // bounds check with window height
                    soundManager.BufferReplace(SOUND_LASER_BOUNDS);
                    soundManager.PlaySound();
                    asteroid->SetActive(false);
                    score -= 20;
                }

                if (!asteroid->IsActive())
                { // renew asteroid spawn timer
                    asteroid->SetCollidable(false);
                    asteroid->SetPosA(0, 0); // temp holding position
                    if (asteroidSpawnDelay == DEF_ASTEROID_SPAWN_TIMER)
                    {
                        asteroid->SetPosX(CreateRandom(0, winHeight +
                                                              asteroid->Sprite().getTexture()->getSize().x)); // stops flash upon renew
                        asteroid->SetPosY(0);
                        asteroid->SetActive(true);
                        asteroidSpawnDelay -= 1 * mFT; // prevent multiple spawns on a single frame
                    }
                }
                asteroid->Update(mFT); // update asteroid
            }

            asteroidSpawnDelay -= 1 * mFT;
            if (asteroidSpawnDelay <= 0)
            { // reset asteroid spawn delay
                asteroidSpawnDelay = DEF_ASTEROID_SPAWN_TIMER;
            }

            if (ship->GetHealth() == 0)
            { // death
                PRINT("Game over! your final score was " + score);
                musicManager.GetMusic()->stop(); // stop music from playing
                system("PAUSE");
                window.close();
            }
        }

        musicManager.Update();
        soundManager.Update();

        // Draw Loop
        if (drawDebugHud)
        {
            for (auto &laser : laserList)
            { // list each lasers position
                ss << "Laser: " << laserList.size() << "\tX = " << int(laser->GetPosition().x)
                   << "\tY = " << (laser->GetPosition().y) << "\n";
            }

            // list general information
            ss << "\nFramerate = " << fps << "\n"
               << "Score = " << score << "\n"
               << "Laser delay = " << laserSpawnDelay << "\n"
               << "Selected laser = " << selectedLaser << "\n"
               << "Asteroid spawn delay = " << asteroidSpawnDelay << "\n"
               << "Collider timer = " << ship->GetColliderTime() << "\n"
               << "Player collidable = " << (bool)ship->IsCollidable() << "\n"
               << "Player lives = " << ship->GetHealth() << "\n\n"

               << "Current music = " << musicManager.GetPath() << "\n"
               << "Current _sound effect = " << soundManager.GetPath() << "\n"
               << "Sound effect status = " << soundManager.GetStatus() << "\n"
               << "Music volume = " << musicManager.GetMusic()->getVolume() << "\n"
               << "Sound volume = " << soundManager.GetSound()->getVolume() << std::endl;
        }
        if (!drawDebugHud)
        { // list basic information
            ss << "Framerate = " << fps << "\n"
               << "Score = " << score << "\n"
               << "Lives = " << ship->GetHealth() << std::endl;
        }
        hud->setString(sf::String(ss.str())); // set hud string
        ss.str(sf::String());                 // flush ss string, same as = "" (not needed if sstream is not global)

        window.clear(sf::Color::Transparent);

        // why didn't i start this project with a EntityManager!!!
        window.draw(*background);
        window.draw(ship->Sprite());

        for (auto &laser : laserList)
        {
            if (laser->IsActive())
            { // do not draw if inactive
                window.draw(laser->Sprite());
            }
        }
        for (auto &asteroid : asteroidList)
        {
            if (asteroid->IsActive())
            { // do not draw if inactive
                window.draw(asteroid->Sprite());
            }
        }
        window.draw(*hud);
        window.display();
    }
    return EXIT_SUCCESS;
}