#pragma once

#include <SFML/Audio.hpp>
#include <string>

using namespace sf;
using namespace std;

class AudioObject{
    public:
      const string& _filePath;
      int loadCount;
      bool loop;
      Music music;
      Sound sound;
      SoundBuffer buffer;
      explicit AudioObject(const string&,bool);
      void play();
};