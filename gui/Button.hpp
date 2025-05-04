
class Button : public SpriteGameObject{

    public:
      bool pressed;
      bool down;
      Mouse mouse;
      explicit Button(SpriteSheet*,float, float);
        ~Button();
       void handleInput(float,RenderWindow&);
       void draw(RenderWindow& window);
};