// #include "../SpriteSheet.hpp"
// #include "GameObject.hpp"
#pragma once

class SpriteGameObject : public GameObject<float>{

    public:
       SpriteSheet *_sprite;
       Vector2<float> _origin;
       Vector2<float> position;
       Vector2<float> velocity;
       Vector2<float> scale;
       Vector2<float> movement;
       bool mirror;
       int _sheetIndex;
       float _width,_height;
       explicit SpriteGameObject(SpriteSheet*, float, float);
        ~SpriteGameObject();
      float width();
      float height();
      float screenCenterX();
      float screenCenterY();
      void update(float);
      FloatRect boundingBox();
      // bool collideWith();
      void draw(RenderWindow&);
};