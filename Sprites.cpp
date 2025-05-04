class SpriteStructure{
    public:
       SpriteSheet *backgroundCloud1;
       SpriteSheet *backgroundCloud2;
       SpriteSheet *backgroundCloud3;
       SpriteSheet *backgroundCloud4;
       SpriteSheet *backgroundCloud5;
       SpriteSheet *backgroundHelp;
       SpriteSheet *backgroundLevelSelect;
       SpriteSheet *backgroundMoutain1;
       SpriteSheet *backgroundMoutain2;
       SpriteSheet *backgroundSky;
       SpriteSheet *backgroundTitle;
       SpriteSheet *flame;
       SpriteSheet *buttonBack;
       SpriteSheet *buttonHelp;
       SpriteSheet *buttonPlay;
       SpriteSheet *buttonQuit;
       SpriteSheet *buttonPlayer;
       SpriteSheet *levelLocked;
       SpriteSheet *levelSolved;
       SpriteSheet *levelUnsolved;
       SpriteSheet *frameHint;
       SpriteSheet *gameOverClick;
       SpriteSheet *gameOverTap;
       SpriteSheet *timer;
       SpriteSheet *welldoneClick;
       SpriteSheet *welldoneTap;
       SpriteSheet *playerCelebrate;
       SpriteSheet *playerDie;
       SpriteSheet *playerExplode;
       SpriteSheet *playerIdle;
       SpriteSheet *playerJump;
       SpriteSheet *playerRun;
       SpriteSheet *rocket;
       SpriteSheet *electrocute;
       SpriteSheet *electrocute2;
       SpriteSheet *electrocuteIdle;
       SpriteSheet *platformHot;
       SpriteSheet *platformIce;
       SpriteSheet *platform;
       SpriteSheet *wallHot;
       SpriteSheet *wallIce;
       SpriteSheet *wall;
       SpriteSheet *turtleIdle;
       SpriteSheet *turtleSneeze;
       SpriteSheet *goal;
       SpriteSheet *water;
       explicit SpriteStructure(){
       const string& filePath = "TickTick/sprites/";
       backgroundCloud1 = new SpriteSheet(filePath + "backgrounds/spr_cloud_1.png",1, 1);
       backgroundCloud2 = new SpriteSheet(filePath + "backgrounds/spr_cloud_2.png",1, 1);
       backgroundCloud3 = new SpriteSheet(filePath + "backgrounds/spr_cloud_3.png",1, 1);
       backgroundCloud4 = new SpriteSheet(filePath + "backgrounds/spr_cloud_4.png",1, 1);
       backgroundCloud5 = new SpriteSheet(filePath + "backgrounds/spr_cloud_5.png",1, 1);
       backgroundHelp = new SpriteSheet(filePath + "backgrounds/spr_help.png",1 ,1);
       backgroundLevelSelect = new SpriteSheet(filePath + "backgrounds/spr_levelselect.png",1 ,1);
       backgroundMoutain1 = new SpriteSheet(filePath + "backgrounds/spr_mountain_1.png",1 , 1);
       backgroundMoutain2 = new SpriteSheet(filePath + "backgrounds/spr_mountain_2.png",1 , 1);
       backgroundSky = new SpriteSheet(filePath + "backgrounds/spr_sky.jpg",1 ,1);
       backgroundTitle = new SpriteSheet(filePath + "backgrounds/spr_title.png",1, 1);
       
       flame = new SpriteSheet(filePath + "flame/spr_flame@9.png",9, 1);
// //  GUI
       buttonBack = new SpriteSheet(filePath + "gui/spr_button_back.png",1,1);
       buttonHelp = new SpriteSheet(filePath + "gui/spr_button_help.png",1,1);
       buttonPlay = new SpriteSheet(filePath + "gui/spr_button_play.png",1,1);
       buttonQuit = new SpriteSheet(filePath + "gui/spr_button_quit.png",1,1);
       buttonPlayer = new SpriteSheet(filePath + "gui/spr_buttons_player@3.png", 3, 1);
       levelLocked = new SpriteSheet(filePath + "gui/spr_level_locked.png",1 ,1);
       levelSolved = new SpriteSheet(filePath + "gui/spr_level_solved.png",1 ,1);
       levelUnsolved = new SpriteSheet(filePath + "gui/spr_level_unsolved.png",1,1);
       frameHint = new SpriteSheet(filePath + "overlays/spr_frame_hint.png",1, 1);
       gameOverClick = new SpriteSheet(filePath + "overlays/spr_gameover_click.png",1 ,1);
       gameOverTap = new SpriteSheet(filePath + "overlays/spr_gameover_tap.png",1 ,1);
       timer = new SpriteSheet(filePath + "overlays/spr_timer.png",1 ,1);
       welldoneClick = new SpriteSheet(filePath + "overlays/spr_welldone_click.png",1 ,1);
       welldoneTap = new SpriteSheet(filePath + "overlays/spr_welldone_tap.png",1 , 1);
//     // Player
     
       playerCelebrate = new SpriteSheet(filePath + "player/spr_celebrate@14.png", 14 , 1);
       playerDie = new SpriteSheet(filePath + "player/spr_die@5.png", 5 , 1);
       playerExplode = new SpriteSheet(filePath + "player/spr_explode@5x5.png",5 , 5);
       playerIdle = new SpriteSheet(filePath + "player/spr_idle.png", 1, 1);
       playerJump = new SpriteSheet(filePath + "player/spr_jump@14.png",14 , 1);
       playerRun = new SpriteSheet(filePath + "player/spr_run@13.png",13 , 1);
//     // rocket
       rocket = new SpriteSheet(filePath + "rocket/spr_rocket@3.png",3 , 1);
//     // Sparky
       electrocute = new SpriteSheet(filePath + "sparky/spr_electrocute.png", 1 , 1);
       electrocute2 = new SpriteSheet(filePath + "sparky/spr_electrocute@6x5.png",6, 5);
       electrocuteIdle = new SpriteSheet(filePath + "sparky/spr_idle.png",1 , 1);
//     //tiles
       platformHot = new SpriteSheet(filePath + "tiles/spr_platform_hot.png",1 , 1);
       platformIce = new SpriteSheet(filePath + "tiles/spr_platform_ice.png",1 , 1);
       platform = new SpriteSheet(filePath + "tiles/spr_platform.png",1 , 1);
       wallHot = new SpriteSheet(filePath + "tiles/spr_wall_hot.png",1 , 1);
       wallIce = new SpriteSheet(filePath + "tiles/spr_wall_ice.png",1 , 1);
       wall = new SpriteSheet(filePath + "tiles/spr_wall.png", 1 , 1);
//     //Turtle
       turtleIdle = new SpriteSheet(filePath + "turtle/spr_idle.png",1, 1);
       turtleSneeze = new SpriteSheet(filePath + "turtle/spr_sneeze@9.png",9 , 1);
       goal = new SpriteSheet(filePath + "spr_goal.png",1 , 1);
       water = new SpriteSheet(filePath + "spr_water.png",1 , 1);
       }
};