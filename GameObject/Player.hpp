#pragma once

class Player : public SpriteGameObject{

    public:
       Keyboard keyboard;
       Vector2f position;
       Vector2f velocity;
       SpriteSheet* _sprite;
       SpriteStructure sprites;
       Vector2f gameSize;
       explicit Player(SpriteSheet*,float,float);
       ~Player();
       void update(float);
       void handleCollision();
       void handleInput(float,RenderWindow&);
       void draw(RenderWindow&);
};