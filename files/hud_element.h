#ifndef FILES_HUD_ELEMENT_H
#define FILES_HUD_ELEMENT_H



#include "generic_include.h"
#include "sound_manager.h"

class HudComponent // non functional
{
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
    std::string strText; //[3] {"Sound volume = ", "Music volume = ", "Reset volume"}; // 0 = sound volume, 1 = music volume, 2 = close
    int selected{0};     // see what is selected
    sf::Text hud;
    sf::Vector2f pos;
    std::stringstream ss;
};

#endif //FILES_HUD_ELEMENT_H
