#pragma once

class Level : public GameObjectList{
public:
    SpriteGameObject *backgroundSky;
    WaterDrops* waterdrops;
    Tile* tiles;
    vector<WaterDrops*> _waterdrops;
    float _cellWidth;
    float _cellHeight;
    vector<Tile*> _tiles;
    vector<SpriteGameObject*> _enemies;
    Player* player;
    Button* quitButton;
    SpriteGameObject* goal;
    SpriteStructure sprites;
    Game<float>* _game;
    Keyboard keyboard;
    ID Id;
    RectangleShape rectangle;
    View view;
    Vector2f position;
    Vector2f velocity;
    bool move;
    explicit Level(unsigned int,float,float,Game<float>*);
    ~Level();
    void reset(float);
    void update(float);
    void handleInput(float,RenderWindow&);
    void draw(RenderWindow&);
    void loadTile(char,unsigned int,unsigned int);
};