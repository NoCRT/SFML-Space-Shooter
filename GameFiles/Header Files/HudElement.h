#ifndef FERAL_ENGINE_HUDELEMENT_H
#define FERAL_ENGINE_HUDELEMENT_H

#include "GENERIC_INCLUDE.h"
#include "SoundManager.h"

class HudComponent {
public:
    explicit HudComponent(std::string fontLoc);

    void SetFont(std::string inpStr);
    void SetTextString(std::string &inpStr);
    void SetPositionX(int inpX);
    void SetPositionY(int inpY);

    sf::Font GetFont();
    int GetSelected();
    sf::Text GetHud();
    void Update(SoundManager &s, MusicManager &m);

private:
    sf::Font font;
    sf::String strText; //[3] {"Sound volume = ", "Music volume = ", "Reset volume"}; // 0 = sound volume, 1 = music volume, 2 = close
    int selected{0}; // see what is selected
    sf::Text hud;
    sf::Vector2f pos;
    std::stringstream ss;
};

#endif //FERAL_ENGINE_HUDELEMENT_H
