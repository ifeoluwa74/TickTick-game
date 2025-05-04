

class LevelButton : public Button{

    public:
      bool pressed;
      float _levelIndex;
      SpriteStructure sprites;
      SpriteGameObject *_levelSolved;
      SpriteGameObject *_levelUnsolved;
      Font font;
      SpriteGameObject *_levelLocked;
      ID Id;
      explicit LevelButton(float,float ,float,bool,bool);
        ~LevelButton();
        float getWidth();
        float getHeight();
        void handleInput(float);
        void update(float);
};