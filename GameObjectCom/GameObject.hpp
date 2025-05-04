#pragma once

using namespace sf;

template <typename T>
class GameObject{
public:
    unsigned int _layer;
    unsigned int _id;
    Vector2<float> position;
    Vector2<float> velocity;
    bool _visible;
    explicit GameObject(T , T);
    void reset(T);
    void update(T);
    virtual void handleInput(T,RenderWindow&);
    virtual void draw(RenderWindow&);
};