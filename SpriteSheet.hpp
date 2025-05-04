#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

using namespace sf;
using namespace std;

class SpriteSheet{

private:
    GLuint texID;
public:
    Texture texture;
    Sprite sprite;
    // Image image;
    GLuint textureID;
    int _col;
    int _row;
    float _width;
    float _height;
    
    // RenderTarget target;
    explicit SpriteSheet(const string&,int column, int row);
    Vector2f getOrigin();
    sf::Texture resizeTexture(const sf::Texture&,unsigned int,unsigned int);
    float width();
    float height();
    Vector2f center();
    float nrSpriteSheet();
    FloatRect boundingBox() const;
    void draw(RenderWindow&,Vector2<float>,Vector2<float>,float,bool,Vector2<float>);
};