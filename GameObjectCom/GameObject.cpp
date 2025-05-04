#include "GameObject.hpp"

template <typename T>
GameObject<T>::GameObject(T layer,T id) : _layer(layer),_id(id){
      position = Vector2f(0.f, 0.f);
      velocity = Vector2f(0.f, 0.f);
      _visible = true;
}

template <typename T>
void GameObject<T>::update(T deltaTime){
   position.x += velocity.x * deltaTime;
   position.y += velocity.y * deltaTime;
}

template <typename T>
void GameObject<T>::reset(T deltaTime){
    _visible = true;
}

template <typename T>
void GameObject<T>::handleInput(T deltaTime,RenderWindow& window){

}

template <typename T>
void GameObject<T>::draw(RenderWindow& window){
    // _sprite.draw(window,position,origin,sheetIndex,mirror,scale);
}