#ifndef GUARD_Player
#define GUARD_Player
#include "playerS.h"
#include <SFML/Graphics.hpp>
class Player
{
        int pxPosition;
        int pyPosition;
        bool animated;
    public:
        sf::Sprite playerSprite;
        sf::Texture spriteSheet;
        sf::Event evt;
        playerS player1;


        Player();
        ~Player();

        void LoadResources();
        void HandleInput();
        void draw(int x, int y, sf::RenderWindow* rw);
        void Animate();
        void setAnimated(bool n);
        void Move(int x, int y);
        void Update();
        playerS getPlayer();
};



#endif // GUARD_Player
