#include "ship.h"

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
    isCollidable = true;
    type = "PLAYER";
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
        //sprite.rotate(-_rotationSpeed);
        position.x -= speed * mFT;
        lastKeyPress = keyList[2];
    }
    if (sf::Keyboard::isKeyPressed(keyList[3]))
    { // right
        //sprite.rotate(+_rotationSpeed);
        position.x += speed * mFT;
        lastKeyPress = keyList[3];
    }

    if (GetBoundingBox().left + GetBoundingBox().width > winWidth && IsCollidable())
    { // right bounds check
        SetPosX(GetPosition().x - 2);
    }
    if (GetBoundingBox().left < 0 && IsCollidable())
    { // left bounds check
        SetPosX(GetPosition().x + 2);
    }

    if (!isCollidable)
    {
        boundingBox = sf::FloatRect(-100, -100, 0, 0);
        colliderTimer -= 1 * mFT;
        auto col = Sprite().getColor();
        if (col.a != 50)
        {
            col.a = 50; // 50% transparency
            Sprite().setColor(col);
        }
    }

    if (isCollidable)
    {
        if (Sprite().getColor().a == 50)
        {
            Sprite().setColor(privateSprite.getColor()); // reset sprite color
        }
    }

    if (colliderTimer <= 0)
    {
        colliderTimer = 2000;
        isCollidable = true; // end invul period
    }

    sprite.setPosition(position);
    if (isCollidable)
    {
        boundingBox = sprite.getGlobalBounds();
    }
}

int &Ship::GetColliderTime()
{
    return colliderTimer;
}