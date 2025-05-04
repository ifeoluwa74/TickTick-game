

class Audios{

    public:
       AudioObject *backgroundMusic;
       AudioObject *playerDie;
       AudioObject *playerExplode;
       AudioObject *playerFall;
       AudioObject *playerJump;
       AudioObject *playerWon;
       AudioObject *playerCollected;
       explicit Audios(){
         const string& filePath = "TickTick/sounds/";

             backgroundMusic = new AudioObject(filePath + "snd_music.ogg",true);
             playerDie = new AudioObject(filePath + "snd_player_die.ogg",false);
             playerExplode = new AudioObject(filePath + "snd_player_explode.ogg",false);
             playerFall = new AudioObject(filePath + "snd_player_fall.ogg",false);
             playerJump = new AudioObject(filePath + "snd_player_jump.ogg",false);
             playerWon = new AudioObject(filePath + "snd_player_won.ogg",false);
             playerCollected = new AudioObject(filePath + "snd_water_collected.ogg",false);
       }
};