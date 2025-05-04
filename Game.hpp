
template <typename T>
class Game{
    public:
      Vector2<float> _gameSize;
      unsigned int _totalTime;
      float levelSelected;
      int _totalSprite;
      GameStateManager<float> _gameWorld;
      unsigned int _spriteStillLoading;
      float Id_layer_title;
      float Id_layer_player;
      float Id_layer_help;
      float Id_layer_gameover;
      float Id_layer_gamefinished;
      float Id_layer_levelselect;
      explicit Game();
      void start(float,float,Game<float>*);
    
      void loadAsset();
      void initialize(Game<float> *);
      void update(float);
      void handleInput(float);
      void draw();
};