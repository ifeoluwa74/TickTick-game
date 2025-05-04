#include "TitleGameState.hpp"

TitleGameState::TitleGameState(float layer, float id,Game<float> *game) : GameStates(layer, id),_game(game){
     
     backgroundImage = new SpriteGameObject(sprites.backgroundTitle,layer,id);
     add(backgroundImage);

    // add play Button
  
    playButton = new Button(sprites.buttonPlay,Id.layer_overlays,0.f);
    playButton->position = Vector2f(playButton->screenCenterX(),540);
    playButton->scale = Vector2f(0.6,0.6);
    add(playButton);

    
    // add help Button
    helpButton = new Button(sprites.buttonHelp,Id.layer_overlays,0.f);
    helpButton->position = Vector2f(helpButton->screenCenterX(),600);
    helpButton->scale = Vector2f(0.6,0.6);
    add(helpButton);
}

TitleGameState::~TitleGameState(){}

void TitleGameState::handleInput(float deltaTime,RenderWindow& window){
     
     for(unsigned int i = 0;i < _gameObjects.size();i++){
          _gameObjects[i]->handleInput(deltaTime,window);
     }
     
      if(playButton->pressed){
          cout << "hey" << endl;
           _game->_gameWorld.switchTo(_game->Id_layer_levelselect);
          
      }
      else if(helpButton->pressed){
            _game->_gameWorld.switchTo(_game->Id_layer_help);
      }
}