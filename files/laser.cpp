#include "laser.h"

Laser::Laser(float startX, float startY, float scaleX, float scaleY)
{
    image.loadFromFile(IMAGE_LASER);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.scale(scaleX, scaleY);
    position.x = startX;
    position.y = startY;
    sprite.setPosition(position);
    speed = maxSpeed;
    state = ACTIVE;
    baseColor = sprite.getColor();
    speed = .2f;
    type = "LASER";
}

Laser::~Laser() = default;

void Laser::Update(float mFT)
{ // called each frame
    if (!IsActive())
    {
        if (speed != 0)
        { // set once until changed
            speed = 0;
        }

        if (sprite.getColor() != sf::Color::Transparent)
        { // set once until changed
            sprite.setColor(sf::Color::Transparent);
        }
    }
    if (IsActive())
    {
        if (sprite.getColor() == sf::Color::Transparent)
        {
            sprite.setColor(baseColor);
        }

        if (speed == 0)
        {
            speed = maxSpeed;
        }
    }
    position.y -= speed * mFT;
    sprite.setPosition(position);
    boundingBox = sprite.getGlobalBounds();
}