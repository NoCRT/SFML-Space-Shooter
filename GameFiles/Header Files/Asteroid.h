#ifndef FERAL_ENGINE_ASTEROID_H
#define FERAL_ENGINE_ASTEROID_H

#include "Entity.h"

class Asteroid : public Entity {
public:
    Asteroid(float startX, float startY, float scaleX, float scaleY);
    void Update(float mFT) override;
private:
    sf::Color baseCol;
};

#endif //FERAL_ENGINE_ASTEROID_H
