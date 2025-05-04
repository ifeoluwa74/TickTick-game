// #include "GameStates.hpp"
#pragma once



class PlayerGameState : public GameStates{

    public:
      int currentLevelIndex;
      LevelArray levelarray;
      vector<Level*> level;
      Level* currentLevel;

      Game<float> *_game;
      explicit PlayerGameState(float,float,Game<float>*);
        ~PlayerGameState();
        void handleInput(float,RenderWindow&);
        void getSelectedLevel(unsigned int);
        void update(float);
        void reset(float);
        void draw(RenderWindow&);
        void loadLevel();
        void goToLevel(unsigned int);
};