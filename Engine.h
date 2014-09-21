#ifndef GUARD_Engine_h
#define GUARD_Engine_h
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Player.h"
#include "Level.h"

class Engine
{

    //private scope stuff must go here
    Tile* tile;
    Player* player;
    Level* level;
    sf::Event evt;
    sf::RenderWindow* window;
    public:
        Engine();
        ~Engine();
        void Init();
        void MainLoop();
        void LoadResource();
        int Collision();
        void TakeInput();
        void Update();
        void Render();





};


#endif // GUARD_Engine_h
