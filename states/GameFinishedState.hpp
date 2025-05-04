#pragma once

template <typename T>
class Game;

class GameFinishedState : public GameStates{

    public:
    Game<float> *_game;
      explicit GameFinishedState(float, float,Game<float>*);
      ~GameFinishedState();
};