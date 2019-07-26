#include "../Header Files/Ship.h"

Ship::Ship(float startX, float startY, float scaleX, float scaleY)
{
    image.loadFromFile(IMAGE_SHIP);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.scale(scaleX, scaleY);
    position.x = startX;
    position.y = startY;
    sprite.setPosition(position);
    health = 3;
    speed = 0.5f;
}

void Ship::Update(float mFT)
{
    if (sf::Keyboard::isKeyPressed(keyList[0]))
    { // forward
        position.y -= speed * mFT;
        lastKeyPress = keyList[0];
    }
    if (sf::Keyboard::isKeyPressed(keyList[1]))
    { // backwards
        position.y += speed * mFT;
        lastKeyPress = keyList[1];
    }
    if (sf::Keyboard::isKeyPressed(keyList[2]))
    { // left
        position.x -= speed * mFT;
        lastKeyPress = keyList[2];
    }
    if (sf::Keyboard::isKeyPressed(keyList[3]))
    { // right
        position.x += speed * mFT;
        lastKeyPress = keyList[3];
    }

    Collidable(colliderTimer == 300);
    if (colliderTimer == 0)
    {
        colliderTimer = 300;
    }
    colliderTimer--;

    sprite.setPosition(position);
    boundingBox = sprite.getGlobalBounds();
}

int const Ship::ColliderTime()
{
    return colliderTimer;
}

bool const Ship::MovingLeft()
{
    return sf::Keyboard::isKeyPressed(keyList[0]);
}

bool const Ship::MovingRight()
{
    return sf::Keyboard::isKeyPressed(keyList[1]);
}

sf::Keyboard::Key const Ship::LastPressedKey()
{
    return lastKeyPress;
}