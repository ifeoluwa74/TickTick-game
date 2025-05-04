#include "LevelSelectGameState.hpp"

LevelSelectGameState::LevelSelectGameState(float layer, float id,Game<float> *game) : GameStates(layer, id),_game(game){
    backgroundImage = new SpriteGameObject(sprites.backgroundLevelSelect,layer,id);
    add(backgroundImage);


        //  add back button
    backButton = new Button(sprites.buttonBack,Id.layer_overlays,0.f);
    backButton->position = Vector2f(backButton->screenCenterX(), 680);
    backButton->scale = Vector2f(0.6,0.6);
    add(backButton);

    LevelArray Levels = LevelArray();
    
    for(unsigned int i = 0;i < Levels._LEVELS.size();i++){
    if(Levels._LEVELS[i].locked){
       float row = floor(i / 4);
       float column = i % 4;
       Button *levelButton = new Button(sprites.levelLocked,Id.layer_overlays_1,0.f);
       levelButton->position = Vector2f(column * (levelButton->width() + 20) + 288,row * (levelButton->height() + 20) + 150);
       levelButton->scale = Vector2f(0.8,0.8);
       _levelButtons.push_back(levelButton);
       add(levelButton);
    }else if(Levels._LEVELS[i].locked){
       float row = floor(i / 4);
       float column = i % 4;
       Button *levelButton = new Button(sprites.levelSolved,Id.layer_overlays_1,0.f);
       levelButton->position = Vector2f(column * (levelButton->width() + 20) + 288,row * (levelButton->height() + 20) + 150);
       levelButton->scale = Vector2f(0.8,0.8);
       _levelButtons.push_back(levelButton);
       add(levelButton);
    }else{
       float row = floor(i / 4);
       float column = i % 4;
       Button *levelButton = new Button(sprites.levelUnsolved,Id.layer_overlays_1,0.f);
       levelButton->position = Vector2f(column * (levelButton->width() + 20) + 288,row * (levelButton->height() + 20) + 150);
       levelButton->scale = Vector2f(0.8,0.8);
       _levelButtons.push_back(levelButton);
       add(levelButton);
    }
    }
}

LevelSelectGameState::~LevelSelectGameState(){}

int LevelSelectGameState::getSelectedLevel(){
    return -1;
}

void LevelSelectGameState::handleInput(float deltaTime,RenderWindow& window){
     for(unsigned int i = 0;i < _gameObjects.size();i++){
          _gameObjects[i]->handleInput(deltaTime,window);
     }
     if(backButton->pressed){
         _game->_gameWorld.switchTo(_game->Id_layer_title);
     }
     
     for(unsigned int i = 0;i < _levelButtons.size();i++){
         LevelArray Levels = LevelArray();
        if(_levelButtons[i]->pressed && !Levels._LEVELS[i].locked){
            _game->levelSelected = i;
            PlayerGameState* playingState = static_cast<PlayerGameState*>(_game->_gameWorld.get(_game->Id_layer_player));

            playingState->goToLevel(i);
            _game->_gameWorld.switchTo(_game->Id_layer_player);
            
        }
     }
}