#ifndef GUARD_Level_h
#define GUARD_Level_h
#include "levelCrap.h"
#include <SFML/Graphics.hpp>
#include <vector>
class Level
{
public:
    sf::Sprite drawSprite;
    sf::Texture tilesheet;
    int map_height = 20;
    int map_width = 30;
    bool animated;
    int xMove;
    int yMove;
    int levelMap[20 * 30] = {


        0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,

        1,1,1,1,1,  1,1,1,1,1,  2,2,2,2,2,  2,2,2,2,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,

        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,2,2,2,2,  2,2,2,2,2,  1,1,1,1,1,  1,1,1,1,1,

        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,0,0,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1
};

    levelCrap objectofLevelCrap[3] = {
        { true, 0, 0},
        { false, 40, 0},
        { false, 40, 40}
    };

    Level();
    ~Level();
    sf::View view;
    levelCrap getTile(int x, int y);
    void LoadResources();
    void ConstructLevel();
    void draw(int z, int c, sf::RenderWindow* rw);
    void MoveLevel(int x, int y);
    void Update();

};




#endif // GUARD_Level_h