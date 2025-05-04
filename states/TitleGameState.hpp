// #include "GameStates.hpp"
#pragma once

// template <typename T>
// class Game;

class TitleGameState : public GameStates{

    public:
       SpriteStructure sprites;
       SpriteGameObject *backgroundImage;
       Button *playButton;
       Button *helpButton;
       ID Id;
       Game<float> *_game;
       explicit TitleGameState(float,float,Game<float>*);
       ~TitleGameState();
       void handleInput(float,RenderWindow&);
};