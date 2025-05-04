#include "HelpGameState.hpp"

HelpGameState::HelpGameState(float layer,float id,Game<float> *game) : GameStates(layer, id),_game(game){
    backgroundImage = new SpriteGameObject(sprites.backgroundHelp,layer,id);
    add(backgroundImage);

    // add back button

    backButton = new Button(sprites.buttonBack,Id.layer_overlays,0.f);
    backButton->position = Vector2f(backButton->screenCenterX(),680);
    backButton->scale = Vector2f(0.6,0.6);
    add(backButton);
}

HelpGameState::~HelpGameState(){}

void HelpGameState::handleInput(float deltaTime,RenderWindow& window){
    for(unsigned int i = 0;i < _gameObjects.size();i++){
          _gameObjects[i]->handleInput(deltaTime,window);
     }
     
     if(backButton->pressed){
         _game->_gameWorld.switchTo(_game->Id_layer_title);
     }
}