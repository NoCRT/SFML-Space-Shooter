#ifndef FILES_ASTEROID_H
#define FILES_ASTEROID_H

#include "entity.h"

class Asteroid : public Entity
{
public:
    Asteroid(float startX, float startY, float scaleX, float scaleY);
    void Update(float mFT) override;

private:
    sf::Color baseCol;
};

#endif //FILES_ASTEROID_H
