#include "../Header Files/HudElement.h"

HudComponent::HudComponent(std::string fontLoc)
{
    font.loadFromFile(fontLoc);
    hud.setFont(font);
    hud.setCharacterSize(20);
    hud.setFillColor(sf::Color::White);
}

void HudComponent::SetFont(std::string inpStr)
{
    font.loadFromFile(inpStr);
    hud.setFont(font);
}

void HudComponent::SetTextString(std::string &inpStr)
{
    strText = inpStr;
}

void HudComponent::SetPositionX(int inpX)
{
    pos.x = inpX;
}

void HudComponent::SetPositionY(int inpY)
{
    pos.y = inpY;
}

sf::Font HudComponent::GetFont()
{
    return font;
}

int HudComponent::GetSelected()
{
    return selected;
}

sf::Text HudComponent::GetHud()
{
    return hud;
}

void HudComponent::Update(SoundManager &s, MusicManager &m)
{
    hud.setPosition(pos);

    ss << strText[0] << s.GetSound()->getVolume() << "\n"
       << strText[1] << m.GetMusic()->getVolume() << "\n"
       << strText[2] << std::endl;

    hud.setString(ss.str());
}

