// #include "GameStates.hpp"
#pragma once

class LevelSelectGameState : public GameStates{

    public:
       SpriteStructure sprites;
       SpriteGameObject *backgroundImage;
       Button *backButton;
      //  vector<LevelButton*> *_levelButton;
       vector<Button*> _levelButtons;
       ID Id;
       Game<float> *_game;
       LevelArray levelarray;
       explicit LevelSelectGameState(float,float,Game<float>*);
       ~LevelSelectGameState();
       int getSelectedLevel();
       void handleInput(float,RenderWindow&);
};