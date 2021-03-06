#include "asteroid.h"

Asteroid::Asteroid(float startX, float startY, float scaleX, float scaleY)
{
    image.loadFromFile(IMAGE_ASTEROID);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.scale(scaleX, scaleY);
    position.x = startX;
    position.y = startY;
    sprite.setPosition(position);
    speed = 2;
    state = ACTIVE;
    baseColor = sprite.getColor();
    speed = .1f;
    type = "ASTEROID";
}

void Asteroid::Update(float mFT)
{
    if (state == INACTIVE)
    {
        speed = 0;
        sprite.setColor(sf::Color::Transparent);
    }
    if (state == ACTIVE)
    {
        sprite.setColor(baseColor);
        speed = .5;
    }
    position.y += speed * mFT;
    sprite.setPosition(position);
    boundingBox = sprite.getGlobalBounds();
}