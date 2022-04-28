//
// Created by Austin on 4/27/2022.
//

#ifndef INC_28_SPACEINVADERS_BUTTON_H
#define INC_28_SPACEINVADERS_BUTTON_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"

/**
 * @class
 * Button with a thin border around it to be used in menus.
 */
class Button : public sf::Drawable {
    sf::RectangleShape border;
    sf::Text           text;

public:
    /** Default constructor */
    Button();
    /** Sets the text of the button*/
    void setText(std::string str);
    /** Sets the position of the button*/
    void setPosition(sf::Vector2f pos);
    /** @return sf::FloatRect - the bounds of the button */
    sf::FloatRect getBounds();
    /** sets the background to glow */
    void highlight();
    /** Sets the background to transparent */
    void lowlight();
    /** overwrites the sf::Drawable draw to draw both border and text */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif //INC_28_SPACEINVADERS_BUTTON_H
