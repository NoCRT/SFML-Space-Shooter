#include "../Header Files/Entity.h"

int Entity::Health()
{
    return health;
}

void Entity::Health(int inpHealth, bool useCurrent)
{
    if (useCurrent) // use current health
    {
        if (inpHealth <= 0)
        {
            health -= inpHealth;
        }
        else
        {
            health+= inpHealth;
        }
    }

    if (!useCurrent) // set new health value
    {
        health = inpHealth;
    }
}

bool Entity::Health(bool condition) {
    return health = condition;
}

bool Entity::Dead()
{
    return health <1;
}

sf::Vector2f Entity::Position()
{
    return position;
}

sf::FloatRect Entity::Bounds()
{
    return boundingBox;
}

sf::Sprite &Entity::Sprite()
{
    return sprite;
}

void Entity::X(float inpX)
{
    position.x = inpX;
}

float const Entity::X() {
    return position.x;
}

void Entity::Y(float inpY)
{
    position.y = inpY;
}

float const Entity::Y()
{
    return position.y;
}


void Entity::XY(float inpX, float inpY)
{
    position.x = inpX;
    position.y = inpY;
}

sf::Vector2f const Entity::XY()
{
    return sf::Vector2f(position.x, position.y);
}

void Entity::Collidable(bool param)
{
    isCollidable = param;
}

bool Entity::Collidable()
{
    return isCollidable;
}