#ifndef FILES_LASER_H
#define FILES_LASER_H

#include "entity.h"

class Laser : public Entity
{
public:
    Laser(float startX, float startY, float scaleX, float scaleY);
    ~Laser();
    void Update(float mFT) override;

    State state; // defaults to inactive

private:
    float maxSpeed{3.f};
};

#endif //FILES_LASER_H