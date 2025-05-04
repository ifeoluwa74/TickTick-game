#pragma once

#include <vector>
// #include "states/GameStates.hpp"

using namespace std;

template <typename T>
class GameStateManager{
public:
    vector<GameStates *> _states;
    GameStates *_currentState;
    explicit GameStateManager();
    float add(GameStates*);
    // void initialize();
    void switchTo(unsigned int);
    void reset(T);
    void update(T);
    GameStates* get(int);
    void handleInput(T,RenderWindow&);
    void draw(RenderWindow&);
};