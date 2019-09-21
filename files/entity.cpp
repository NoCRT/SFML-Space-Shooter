#include "entity.h"

const int &Entity::GetHealth()
{
    return health;
}

const bool Entity::IsDead()
{
    return health < 1;
}

sf::Vector2f &Entity::GetPosition()
{
    return position;
}

sf::FloatRect &Entity::GetBoundingBox()
{
    return boundingBox;
}

const bool &Entity::IsCollidable()
{
    return isCollidable;
}

sf::Sprite &Entity::Sprite()
{
    return sprite;
}

void Entity::SetPosX(float inpX)
{
    position.x = inpX;
}

void Entity::SetPosY(float inpY)
{
    position.y = inpY;
}

void Entity::SetPosA(float inpX, float inpY)
{
    position.x = inpX;
    position.y = inpY;
}

void Entity::SetCollidable(bool inpParam)
{
    isCollidable = inpParam;
}

void Entity::SetHealth(int inpHealth)
{
    if (inpHealth <= 3)
    {
        health = inpHealth;
    }
    else
    {
        PRINT("SetHealth input value failed sanity check : " + std::to_string(inpHealth) + ".\n Setting health to max allowed : " + std::to_string(3));
    }
}

void Entity::SetActive(bool inpBool)
{
    if (inpBool)
    {
        state = ACTIVE;
    }
    else
    {
        state = INACTIVE;
    }
}

const bool Entity::IsActive()
{
    return state == State::ACTIVE;
}

const sf::String &Entity::GetType()
{
    return type;
}

void Entity::SetType(sf::String inpType)
{
    if (type != inpType)
    {
        type = inpType;
    }
}