#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include "utils.cpp"
#include "Id.cpp"
#include "SpriteSheet.cpp"
#include "AudioObject.cpp"
#include "Sprites.cpp"
#include "Audios.cpp"
#include "GameObjectCom/GameObject.cpp"
#include "GameObjectCom/SpriteGameObject.cpp"
#include "GameObjectCom/GameObjectList.cpp"
#include "gui/Button.cpp"
// #include "gui/LevelButton.cpp"
#include "states/GameStates.cpp"
#include "GameStateManager.cpp"
#include "Game.hpp"
#include "GameObject/Tile.cpp"
#include "GameObject/WaterDrops.cpp"
#include "GameObject/Player.cpp"
#include "Level.hpp"
#include "states/PlayerGameState.hpp"
#include "Level.cpp"
#include "states/TitleGameState.cpp"
#include "states/HelpGameState.cpp"
#include "states/PlayerGameState.cpp"
#include "states/LevelSelectGameState.cpp"
#include "states/GameFinishedState.cpp"
#include "states/GameOverState.cpp"
#include "Game.cpp"
// #include "GameWorld.cpp"


using namespace sf;
using namespace std;




// struct AudioStucture{
//     const string& filePath = "TickTick/sounds/";

//     AudioObject *backgroundMusic = new AudioObject(filePath + "snd_music.ogg",true);
//     AudioObject *playerDie = new AudioObject(filePath + "snd_player_die.ogg",false);
//     AudioObject *playerExplode = new AudioObject(filePath + "snd_player_explode.ogg",false);
//     AudioObject *playerFall = new AudioObject(filePath + "snd_player_fall.ogg",false);
//     AudioObject *playerJump = new AudioObject(filePath + "snd_player_jump.ogg",false);
//     AudioObject *playerWon = new AudioObject(filePath + "snd_player_won.ogg",false);
//     AudioObject *playerCollected = new AudioObject(filePath + "snd_water_collected.ogg",false);
// };





enum GameState{
       GAMEOVER,
       PAUSE,
       PLAY
};




int main(){

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.majorVersion = 2;
    settings.minorVersion = 1;

    Game<float> *game = new Game<float>();

    game->start(1024,725,game);

    Audios* audios = new Audios();

  

    RenderWindow window(VideoMode(game->_gameSize.x, game->_gameSize.y), "TickTick");
    window.setVerticalSyncEnabled(true);
    Clock clock;

   

    // Setup OpenGL states
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Setup orthographic projection (matches SFML coordinates)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, game->_gameSize.x,game->_gameSize.y, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
       
        
        // window.clear();
        // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // glClearColor(0.0,0.0,0.0,1.0);
        game->_gameWorld.handleInput(deltaTime,window);
        game->_gameWorld.update(deltaTime);
        game->_gameWorld.draw(window);
        window.display();
    }
    return EXIT_SUCCESS;
}