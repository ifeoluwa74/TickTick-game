// #include "GameStates.hpp"
#pragma once


// template <typename T>
// class Game;

class HelpGameState : public GameStates{
 public:
    ID Id;
    SpriteStructure sprites;
    SpriteGameObject *backgroundImage;
    Button *backButton;
    Game<float> *_game;
    explicit HelpGameState(float, float,Game<float>*);
       ~HelpGameState();
       void handleInput(float,RenderWindow&);
};