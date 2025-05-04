#include "Level.hpp"



Level::Level(unsigned int levelIndex,float layer,float id,Game<float>* game) : GameObjectList(layer , id),_game(game){
  view = View(FloatRect(0 , 0 ,1024, 725));
  position = Vector2f(0.f,0.f);
  velocity = Vector2f(0.f,0.f);

  for(unsigned int i = 0;i < 5;i++){
    backgroundSky = new SpriteGameObject(sprites.backgroundSky,layer,id);
    backgroundSky->position = Vector2f(i * backgroundSky->width(),0.f);
    add(backgroundSky);
  }

//   for (var i = 0; i < 5; i++) {
//         var sprid = "mountain_" + (Math.ceil(Math.random()*2));
//         var mountain = new powerupjs.SpriteGameObject(sprites[sprid], ID.layer_background_2);
//         mountain.position = new powerupjs.Vector2(Math.random() * powerupjs.Game.size.x - mountain.width / 2,
//             powerupjs.Game.size.y - mountain.height);
//         backgrounds.add(mountain);
//     }

   for(unsigned int i = 0;i < 5;i++){
      SpriteSheet* mountains[] = {sprites.backgroundMoutain1,sprites.backgroundMoutain2};
      unsigned int r = ceil(rand() * 2);
      SpriteGameObject* backgroundMoutain = new SpriteGameObject(sprites.backgroundMoutain1,Id.layer_background_2,0.f);
      backgroundMoutain->position = Vector2f(i * (1024) - (backgroundMoutain->width() / 2),725  - backgroundMoutain->height());
      add(backgroundMoutain);
   }

  // LevelArray levelarray = LevelArray();
  // const string level[15] = levelarray._LEVELS[levelIndex].Level;


     quitButton = new Button(sprites.buttonQuit,Id.layer_overlays_2,0.f);
     quitButton->position = Vector2f(1024 - quitButton->width() * 0.6 - 10, 10);
     quitButton->scale = Vector2f(0.6,0.6);
     add(quitButton);
     
  LevelArray levelarray = LevelArray();
  const string level[15] = levelarray._LEVELS[levelIndex].Level;

  Vector2f gameSize = Vector2f(1024 * 5,725);

  _cellWidth = gameSize.x / 100;
  _cellHeight = gameSize.y / 15;

  for(unsigned int r = 0;r < 15;r++){
    for(unsigned int c = 0;c < 100;c++){
        // cout << level[r][c] == 'W' << endl;
        loadTile(level[r][c], c , r);
        if(level[r][c] == 'W'){
                waterdrops = new WaterDrops(sprites.water,Id.layer_objects,0.f);
                waterdrops->position = Vector2f(c * _cellWidth + (50 / 2),r * _cellHeight + 8);
                waterdrops->scale = Vector2f(0.75,0.75);
                add(waterdrops);
              _waterdrops.push_back(waterdrops);
        }else if(level[r][c] == '1'){
               player = new Player(sprites.playerIdle,Id.layer_objects,0.f);
               player->position = Vector2f(c * _cellWidth,r * _cellHeight - 35);
               player->scale = Vector2f(0.75,0.75);
               add(player);
        }else if(level[r][c] == 'X'){
            goal = new SpriteGameObject(sprites.goal,Id.layer_objects,0.f);
            goal->position = Vector2f(c * _cellWidth,r * _cellHeight + 8);
            add(goal);
        }
    }
  }
  move = false;
}

Level::~Level(){}

void Level::loadTile(char object, unsigned int x,unsigned int y){
     if(object == '#'){
         tiles = new Tile(sprites.wall,Id.layer_tiles,0.f,"normal");
         tiles->position = Vector2f((x * _cellWidth),y * _cellHeight + 8);
         tiles->scale = Vector2f(0.75,0.75);
         add(tiles);
     }else if(object == '-'){
         tiles = new Tile(sprites.platform,Id.layer_tiles,0.f,"normal");
         tiles->position = Vector2f(x * _cellWidth,y * _cellHeight + 8);
         tiles->scale = Vector2f(0.75,0.75);
         add(tiles);
     }else if(object == '*'){
        tiles = new Tile(sprites.wallIce,Id.layer_tiles,0.f,"normal");
        tiles->position = Vector2f(x * _cellWidth,y * _cellHeight + 8);
        tiles->scale = Vector2f(0.75,0.75);
        add(tiles);
     }
}

void Level::reset(float deltaTime){

}

void Level::handleInput(float deltaTime,RenderWindow& window){
      player->handleInput(deltaTime,window);
      for(unsigned int i = 0;i < _gameObjects.size();i++){
          _gameObjects[i]->handleInput(deltaTime,window);
      }

     if(quitButton->pressed){
        _game->_gameWorld.switchTo(_game->Id_layer_levelselect);
        reset(deltaTime);
     }


    if(keyboard.isKeyPressed(keyboard.Right) && position.x <= (1024 * 5)){
        velocity.x = 30 * deltaTime;
        position.x += velocity.x;
        move = true;
    }
    else if(keyboard.isKeyPressed(keyboard.Left) && position.x > 0){
      cout << "FirstPos:" << position.x << endl;
      velocity.x = -30 * deltaTime;
      position.x -= velocity.x;
      cout << "velocityminus:" << velocity.x << "\npositionX:" << position.x << endl;
       move = true;
    }else{
      move = false;
    }
}

void Level::update(float deltaTime){
      //  position = position + velocity;

       for(unsigned int i = 0;i < _gameObjects.size();i++){
         _gameObjects[i]->update(deltaTime);
       }

       player->update(deltaTime);
}

void Level::draw(RenderWindow& window){
    for(unsigned int i = 0;i < 5;i++){
        window.setView(view);
         rectangle.setSize(Vector2f(1024, 725));
         rectangle.setOutlineColor(Color(0,0,255,100));
         rectangle.setOutlineThickness(2);
         rectangle.setFillColor(Color(0,0,255,100));
         rectangle.setPosition(i * 1024,0);
         window.draw(rectangle);
    }

    for(unsigned int i = 0;i < _gameObjects.size();i++){
        if(_gameObjects[i] != player){
           if(move){
               view.move(velocity.x,0);
               move = false;
            }
          //  window.setView(view);
           _gameObjects[i]->draw(window);
          }
       if((_gameObjects[i] == player) || (_gameObjects[i] == quitButton)){
            _gameObjects[i]->draw(window);
       }
    }

}