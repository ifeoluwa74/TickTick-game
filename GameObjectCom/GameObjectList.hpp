#include <vector>
#include <algorithm>
// #include "GameObject.cpp"
#pragma once

using namespace std;

class GameObjectList : public GameObject<float>{
    public:
      std::vector<SpriteGameObject *> _gameObjects;
      
      explicit GameObjectList(float, float);
      void add(SpriteGameObject*);
      // void remove(GameObject*);
      GameObject<float>* at(unsigned int index);
      void clear();
      void find(int);
      virtual void handleInput(float,RenderWindow&);
      virtual void update(float);
      virtual void reset(float);
      virtual void draw(RenderWindow&);
};