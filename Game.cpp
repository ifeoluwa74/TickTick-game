// #include "Game.hpp"

template <typename T>
Game<T>::Game(){
   _spriteStillLoading = 0;
   levelSelected = -1;
}

template <typename T>
void Game<T>::start(float x,float y,Game<float> *game){
   _gameSize = Vector2<float>(x, y);
   initialize(game);
}

template <typename T>
void Game<T>::loadAsset(){

}

template <typename T>
void Game<T>::initialize(Game<float> *game){
           _gameWorld = GameStateManager<float>();

        //  ID Id;

         Id_layer_title = _gameWorld.add(new TitleGameState(0.f, 0.f, game));
         Id_layer_player = _gameWorld.add(new PlayerGameState(0.f, 0.f, game));
         Id_layer_help = _gameWorld.add(new HelpGameState(0.f, 0.f, game));
         Id_layer_gameover = _gameWorld.add(new GameOverState(0.f, 0.f, game));
         Id_layer_gamefinished = _gameWorld.add(new GameFinishedState(0.f, 0.f, game));
         Id_layer_levelselect = _gameWorld.add(new LevelSelectGameState(0.f,0.f,game));

         _gameWorld.switchTo(Id_layer_title);
}

template <typename T>
void Game<T>::update(float deltaTime){

}

template <typename T>
void Game<T>::handleInput(float deltaTime){

}

template <typename T>
void Game<T>::draw(){

}

