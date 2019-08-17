#ifndef FILES_ENTITY_H
#define FILES_ENTITY_H

#include "generic_include.h"

// use references to pass through values to save amount of data copied each frame

// active = stops entity from updating
// inactive = allows entity to continue updating normaly
enum State
{
    ACTIVE,
    INACTIVE
};


class Entity
{
public:

    // pure viatal function for parent classes
    virtual void Update(float mFT) = 0;

    // return player health
    const int &GetHealth();

    // sets player health to input value if it passes sanity check
    void SetHealth(int inpHealth);

    // return true if player is IsDead 
    const bool IsDead();

    // return reference to this entitys current position (x and y)
    sf::Vector2f &GetPosition();

    // return reference to this entitys bounding box
    sf::FloatRect &GetBoundingBox();

    // return if this entity is collidable
    const bool &IsCollidable();

    // return reference to sprite
    sf::Sprite &Sprite();

    // set position x position
    void SetPosX(float inpX);

    // set position y position
    void SetPosY(float inpY);
    
    // change both position x and y position
    void SetPosA(float inpX, float inpY);

    // set if entity is collidable or not
    void SetCollidable(bool inpParam);

    // current entity state
    State state{INACTIVE};

    // set if entity is active or not
    // changes state to either active or inactive,
    // depending on input
    void SetActive(bool inpBool);

    // returns entity isActive flag
    const bool IsActive();

    // return entity type as const reference
    const sf::String &GetType();

    // set entity type. used to override one in constructor if provided
    void SetType(sf::String inpType);

protected:
    int health{1};
    int colliderTimer{300};
    float speed{4.f};
    bool isIsDead  {false};
    bool isCollidable{true};
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect boundingBox;
    sf::Vector2f position;
    sf::String type;
    sf::Clock baseColor;
};

#endif //FILES_ENTITY_H
