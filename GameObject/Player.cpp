#include "Player.hpp"


Player::Player(SpriteSheet* sprite,float layer,float id) : SpriteGameObject(sprite,layer,id){
   _sprite = sprite;
   _sheetIndex = 0;
   gameSize = Vector2f(1024 * 5, 725);
}

Player::~Player(){

}

void Player::update(float deltaTime){
    position = position + velocity;
}

void Player::handleCollision(){
  
}

void Player::handleInput(float deltaTime,RenderWindow& window){
    
    if(keyboard.isKeyPressed(keyboard.Right)){
      _sprite = sprites.playerRun;
    }else if(keyboard.isKeyPressed(keyboard.Left)){
      _sprite = sprites.playerRun;
    }else{
      _sprite = sprites.playerIdle;
    }


  /* 
  #include <SFML/Graphics.hpp>

// ... (other includes and class definitions)

bool checkCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
    sf::FloatRect rect1 = sprite1.getGlobalBounds();
    sf::FloatRect rect2 = sprite2.getGlobalBounds();

    return rect1.intersects(rect2);
}

void handlePlayerCollisions(Player& player, const std::vector<sf::Sprite>& platforms) {
    // Temporary variables to store potential new player position
    float newPlayerX = player.getPosition().x;
    float newPlayerY = player.getPosition().y;

    // Check for collisions with platforms
    for (const sf::Sprite& platform : platforms) {
        if (checkCollision(player.getSprite(), platform)) {
            // Upward collision
            if (player.getVelocity().y < 0) { // Player is moving upwards
                // Prevent player from moving further up
                newPlayerY = platform.getPosition().y + platform.getGlobalBounds().height;
                player.setVelocityY(0); // Stop vertical movement
            }

            // Downward collision
            if (player.getVelocity().y > 0) { // Player is moving downwards
                // Prevent player from falling through platform
                newPlayerY = platform.getPosition().y - player.getSprite().getGlobalBounds().height;
                player.setVelocityY(0); // Stop vertical movement
                player.setOnGround(true); // Indicate player is on ground
            }
        }
    }

    // Update player position based on collision handling
    player.setPosition(newPlayerX, newPlayerY);
}
  
  
   */
    
}

void Player::draw(RenderWindow& window){
     if(_sheetIndex >= _sprite->nrSpriteSheet() - 1){
            _sheetIndex = 0;
     }else{
        _sheetIndex++;
     }

    window.setView(window.getDefaultView());
    
    if(_visible)
    _sprite->draw(window,position,_origin,_sheetIndex,mirror,scale);
}