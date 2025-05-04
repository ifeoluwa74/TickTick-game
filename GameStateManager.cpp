#include "GameStateManager.hpp"


template <typename T>
GameStateManager<T>::GameStateManager(){
//    _currentState = _gamestates->titlestate;
}

template <typename T>
void GameStateManager<T>::update(T deltaTime){
     if(_currentState){
         _currentState->update(deltaTime);
     }
}

template <typename T>
void GameStateManager<T>::reset(T deltaTime){
       if(_currentState){
           _currentState->reset(deltaTime);
       }
}

template <typename T>
GameStates* GameStateManager<T>::get(int id){
     if(id < 0 || id >= _states.size())
     return nullptr;
     return _states[id];
}

// void GameStateManager<T>::initialize(){
//          float Id_layer_title = add(new TitleGameState(0.f, 0.f/* , game */));
//          float Id_layer_player = add(new PlayerGameState(0.f, 0.f/* , game */));
//          float Id_layer_help = add(new HelpGameState(0.f, 0.f/* , game */));
//          float Id_layer_gameover = add(new GameOverState(0.f, 0.f/* , game */));
//          float Id_layer_gamefinished = add(new GameFinishedState(0.f, 0.f/* , game */));
// }

template <typename T>
void GameStateManager<T>::handleInput(T deltaTime,RenderWindow& window){
     if(_currentState){
         _currentState->handleInput(deltaTime,window);
     }
}

template <typename T>
float GameStateManager<T>::add(GameStates *gamestate){
     _states.push_back(gamestate);
     _currentState = gamestate;
     return _states.size() - 1;
}

template <typename T>
void GameStateManager<T>::switchTo(unsigned int id){
   _currentState = _states[id];
}

template <typename T>
void GameStateManager<T>::draw(RenderWindow& window){
    if(_currentState){
        _currentState->draw(window);
    }
}