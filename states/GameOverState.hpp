// #include "GameStates.hpp"
#pragma once


template <typename T>
class Game;

class GameOverState : public GameStates{
    public:
    Game<float> *_game;
      explicit GameOverState(float, float,Game<float>*);
         ~GameOverState();
         void handleInput(float,RenderWindow&);
};