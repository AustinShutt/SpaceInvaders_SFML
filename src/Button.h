//
// Created by Austin on 4/27/2022.
//

#ifndef INC_28_SPACEINVADERS_BUTTON_H
#define INC_28_SPACEINVADERS_BUTTON_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Button : public sf::Drawable, public sf::Transformable{
    sf::RectangleShape border;
    sf::Text           text;

public:
    Button();
    void setText(std::string str);
    void setPosition(sf::Vector2f pos);
    sf::FloatRect getBounds();
    void highlight();
    void lowlight();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif //INC_28_SPACEINVADERS_BUTTON_H
