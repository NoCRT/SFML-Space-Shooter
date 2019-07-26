#include "../Header Files/Asteroid.h"

Asteroid::Asteroid(float startX, float startY, float scaleX, float scaleY) {
    image.loadFromFile(IMAGE_ASTEROID);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.scale(scaleX, scaleY);
    position.x = startX;
    position.y = startY;
    sprite.setPosition(position);
    speed = 2;
    state = EXPIRED;
    baseCol = sprite.getColor();
    speed = .1f;
}

void Asteroid::Update(float mFT)
{
    if (state == EXPIRED)
    {
        speed = 0;
        sprite.setColor(sf::Color::Transparent);
    }
    if (state == RENEWED)
    {
        sprite.setColor(baseCol);
        speed = .5;
    }
    position.y += speed * mFT;
    // sprite.setRotation(1.f);
    sprite.setPosition(position);
    boundingBox = sprite.getGlobalBounds();
}