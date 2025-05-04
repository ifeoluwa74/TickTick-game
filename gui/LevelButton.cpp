#include "LevelButton.hpp"


LevelButton::LevelButton(float levelIndex,float layer,float id,bool locked,bool solved) : Button(layer,id){
    pressed = false;
    _levelIndex = levelIndex;
    _levelSolved = new SpriteGameObject(sprites.levelSolved,Id.layer_overlays_1,0.f);
    _levelUnsolved = new SpriteGameObject(sprites.levelUnsolved,Id.layer_overlays,0.f);

    _levelSolved->_sheetIndex = levelIndex;

   

    _levelLocked = new SpriteGameObject(sprites.levelLocked,Id.layer_overlays_1,0.f);
   

    // _levelLocked->_visible = false;
    // _levelSolved->_visible = false;
    // _levelUnsolved->_visible = true;


    add(_levelLocked);
    add(_levelSolved);
    add(_levelUnsolved);
}


LevelButton::~LevelButton(){

}

float LevelButton::getWidth(){
   return _levelLocked->width();
}

float LevelButton::getHeight(){
   return _levelLocked->height();
}

void LevelButton::handleInput(float deltaTime){

}

void LevelButton::update(float deltaTime){
    // _levelLocked->_visible = false;
    // _levelSolved->_visible = false;
    // _levelUnsolved->_visible = true;
}