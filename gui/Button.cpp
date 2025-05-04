#include "Button.hpp"


Button::Button(SpriteSheet *sprite,float layer,float id) : SpriteGameObject(sprite,layer,id){
    pressed = false;
    down = false;
}


void Button::handleInput(float deltaTime,RenderWindow& window){
        pressed = false;
    if (mouse.isButtonPressed(mouse.Left) || mouse.isButtonPressed(mouse.Middle)){

             Vector2i pos(position.x,position.y);
             Vector2i size(boundingBox().width * 0.6,boundingBox().height * 0.6);
             IntRect blockRect(pos,size);
            pressed = _visible && (blockRect.contains(mouse.getPosition(window).x,mouse.getPosition(window).y));
            down = _visible && (blockRect.contains(mouse.getPosition(window).x,mouse.getPosition(window).y));
    }
}

void Button::draw(RenderWindow& window){
    window.setView(window.getDefaultView());
     if(_visible)
    _sprite->draw(window,position,_origin,_sheetIndex,mirror,scale);
}