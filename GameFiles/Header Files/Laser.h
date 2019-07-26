#ifndef FERAL_ENGINE_LASER_H
#define FERAL_ENGINE_LASER_H

#include "Entity.h"

class Laser : public Entity {
public:
    Laser(float startX, float startY, float scaleX, float scaleY);
    ~Laser();
    void Update(float mFT) override;

    State state;
    sf::Color baseCol;
private:
    float maxSpeed{3.f};

};

#endif //FERAL_ENGINE_LASER_H
