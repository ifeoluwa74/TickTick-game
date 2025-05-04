#include "SpriteGameObject.hpp"

SpriteGameObject::SpriteGameObject(SpriteSheet *sprite,float layer,float id) : GameObject<float>(layer,id){
    _sprite = sprite;
    scale = Vector2f(1.f,1.f);
    mirror = false;
}

SpriteGameObject::~SpriteGameObject(){

}

float SpriteGameObject::width(){
  return _sprite->width();
}

float SpriteGameObject::height(){
 return _sprite->height();
}

float SpriteGameObject::screenCenterX(){
   return (1024 - (width() * 0.6)) / 2 + _origin.x;
}

float SpriteGameObject::screenCenterY(){
     return (725 - (height() * 0.6)) / 2 + _origin.y;
}
FloatRect SpriteGameObject::boundingBox(){
   return _sprite->boundingBox();
}

// bool SpriteGameObject::collideWith(){

// }

void SpriteGameObject::update(float deltaTime){
     position = velocity + position;
}

void SpriteGameObject::draw(RenderWindow& window){
    
    if(_visible)
    _sprite->draw(window,position,_origin,_sheetIndex,mirror,scale);
}