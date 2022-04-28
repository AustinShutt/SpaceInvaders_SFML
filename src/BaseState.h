//
// Created by Austin on 4/26/2022.
//

#ifndef INC_28_SPACEINVADERS_BASESTATE_H
#define INC_28_SPACEINVADERS_BASESTATE_H

/**
 * @interface base state to place in application state stack
 * <br/> contains only pure virtual functions so no class of this
 * type may be instantiated.
 */

class BaseState{
public:
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
};

#endif //INC_28_SPACEINVADERS_BASESTATE_H
