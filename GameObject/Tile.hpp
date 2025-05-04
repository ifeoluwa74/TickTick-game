#pragma once


class Tile : public SpriteGameObject{
    public:
      explicit Tile(SpriteSheet*,float,float,string);
      ~Tile();
      void update(float);
};