#include "GameObjectList.hpp"

GameObjectList::GameObjectList(float layer , float id) : GameObject<float>(layer,id){

}

void GameObjectList::add(SpriteGameObject *gameobject){
     _gameObjects.push_back(gameobject);
     
    //  sort(_gameObjects.begin(),_gameObjects.end());
}

// void GameObjectList::remove(GameObject<float> *gameobject){
//      for(unsigned int i = 0,l = _gameObjects.size();i < l;i++){
//          if(gameobject != _gameObjects[i])
//             continue;
//         _gameObjects.splice(i,1);
//         return;
//      }
        
// }

void GameObjectList::clear(){
    _gameObjects = {};
}

GameObject<float>* GameObjectList::at(unsigned int index){
    if(index < 0 || index >= _gameObjects.size())
        return nullptr;
    return _gameObjects[index];
}

void GameObjectList::find(int id){

}

void GameObjectList::handleInput(float deltaTime,RenderWindow& window){
   for(unsigned int i = 0,l = _gameObjects.size(); i < l;i++){
       _gameObjects[i]->handleInput(deltaTime,window);
   }
}

void GameObjectList::reset(float deltaTime){
    for(unsigned int i = 0,l = _gameObjects.size();i < l;i++)
      _gameObjects[i]->reset(deltaTime);
}

void GameObjectList::update(float deltaTime){
    for(unsigned int i = 0,l = _gameObjects.size(); i < l;i++){
       _gameObjects[i]->update(deltaTime);
    }
}

void GameObjectList::draw(RenderWindow& window){
     for(unsigned int i = 0,l = _gameObjects.size(); i < l;i++){
        _gameObjects[i]->draw(window);
     }
}