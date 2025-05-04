#pragma once

class WaterDrops : public SpriteGameObject{

    public:
      explicit WaterDrops(SpriteSheet*,float,float);
        ~WaterDrops();
        void update(float);
};