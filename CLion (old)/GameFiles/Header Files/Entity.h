#ifndef FERAL_ENGINE_ENTITY_H
#define FERAL_ENGINE_ENTITY_H

// 12/12/18 test code format for inline header files (using standardised initializer)

// only return const when it is a pointer

#include "GENERIC_INCLUDE.h"
#include "Values.h"

enum State {
    EXPIRED, RENEWED, IDLE
};
// expired = stops entity from updating
// renewed = allows entity to continue updating normaly
// idle = exclude collision logic from updates

/*
struct Transform
{
    int X;
    int Y;
    int Scale;
    int Speed;

};
*/

class Entity
{
public:
    virtual void Update(float mFT) = 0;

    int Health();
    void Health(int inpHealth, bool useCurrent = false);
    bool Health(bool condition);

    bool Dead();

    sf::Vector2f Position();
    sf::FloatRect Bounds();
    sf::Sprite &Sprite();

    void X(float inpX);
    float const X();
    void Y(float inpY);
    float const Y();
    void XY(float inpX, float inpY);
    sf::Vector2f const XY();

    void Collidable(bool param);
    bool Collidable();
    State state{RENEWED};

protected:
    int health{1};
    float speed{4.f};
    bool isDead{false};
    bool isCollidable{true};
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::FloatRect boundingBox;
    sf::Vector2f position;
};

#endif //FERAL_ENGINE_ENTITY_H
