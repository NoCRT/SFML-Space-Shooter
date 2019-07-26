#include "../Header Files/Laser.h"

Laser::Laser(float startX, float startY, float scaleX, float scaleY) {
    image.loadFromFile(IMAGE_LASER);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.scale(scaleX, scaleY);
    position.x = startX;
    position.y = startY;
    sprite.setPosition(position);
    speed = maxSpeed;
    state = RENEWED;
    baseCol = sprite.getColor();
    speed = .2f;
}

Laser::~Laser()
{
}

void Laser::Update(float mFT)
{
    if (state == EXPIRED)
    {
        speed = 0;
        sprite.setColor(sf::Color::Transparent);
    }
    if (state == RENEWED)
    {
        sprite.setColor(baseCol);
        speed = maxSpeed;
    }
    position.y -= speed * mFT;
    sprite.setPosition(position);
    boundingBox = sprite.getGlobalBounds();

}