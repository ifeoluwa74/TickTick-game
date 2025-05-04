#include "PlayerGameState.hpp"


PlayerGameState::PlayerGameState(float layer,float id,Game<float> *game) : GameStates(layer, id),_game(game){
   loadLevel();
   currentLevelIndex = 0;
   currentLevel = level[currentLevelIndex];
}

PlayerGameState::~PlayerGameState(){

}

void PlayerGameState::handleInput(float deltaTime,RenderWindow& window){
  
   
   if(currentLevel){
      currentLevel->handleInput(deltaTime,window);
   }
}

void PlayerGameState::reset(float deltaTime){
       
}

void PlayerGameState::getSelectedLevel(unsigned int index){
    
}

void PlayerGameState::goToLevel(unsigned int levelId){
      if(levelId < 0 || levelId >= level.size())
        return;
     currentLevelIndex = levelId;
     currentLevel = level[currentLevelIndex];
     float deltaTime = 1 / 60;
     currentLevel->reset(deltaTime);
}
void PlayerGameState::loadLevel(){
      for(unsigned int i = 0;i < levelarray._LEVELS.size();i++){
           level.push_back(new Level(i,0.f,0.f,_game));
      }
}

void PlayerGameState::update(float deltaTime){
   // currentLevelIndex = _game->levelSelected;
   // currentLevel = level[currentLevelIndex];
    if(currentLevel){
       currentLevel->update(deltaTime);
    }
}

void PlayerGameState::draw(RenderWindow& window){
      if(currentLevel){
        currentLevel->draw(window);
      }
}