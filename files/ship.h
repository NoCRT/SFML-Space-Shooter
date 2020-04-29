#ifndef FILES_SHIP_H
#define FILES_SHIP_H

#include "entity.h"

class Ship : public Entity
{
public:
    ~Ship() = default;
    Ship(float startX, float startY, float scaleX, float scaleY);
    void Update(float mFT) override;

    int &GetColliderTime();

private:
    std::vector<sf::Keyboard::Key> keyList{sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D};
    sf::Keyboard::Key lastKeyPress{sf::Keyboard::Unknown};
    int colliderTimer{1000}; // 2000 = 4 seconds
    const float defCoastSpeed{2.f};
    float coastSpeed{defCoastSpeed};
    float rotationSpeed{.1f};
    sf::Sprite privateSprite = Sprite(); // copy of initial sprite to allow for transparency changes
};

#endif //FILES_SHIP_H