#ifndef FERAL_ENGINE_SHIP_H
#define FERAL_ENGINE_SHIP_H

#include "Entity.h"

class Ship : public Entity {
public:
    ~Ship() = default;
    Ship(float startX, float startY, float scaleX, float scaleY);
    void Update(float mFT) override;

    int const ColliderTime();
    bool const MovingLeft();
    bool const MovingRight();
    sf::Keyboard::Key const LastPressedKey();
private:
    std::vector<sf::Keyboard::Key> keyList {sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D};
    sf::Keyboard::Key lastKeyPress {sf::Keyboard::Unknown};
    int colliderTimer {300};
    const float defCoastSpeed{2.f};
    float coastSpeed{defCoastSpeed};
    float rotationSpeed{.1f};
};

#endif //FERAL_ENGINE_SHIP_H
