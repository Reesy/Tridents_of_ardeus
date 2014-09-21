#ifndef GUARD_Tile_h
#define GUARD_Tile_h
#include <vector>
#include <SFML/Graphics.hpp>
class Tile
{

    std::vector<sf::Texture> tileVector;
    sf::Sprite drawSprite;
    sf::Texture grass;
    sf::Sprite drawSprite2;
    sf::Texture wall;
    public:
        Tile();
        ~Tile();
        void LoadResources();
        void AddTile(sf::Texture& texture);
        sf::Texture getTile(int n);
        void draw(int x, int y, sf::RenderWindow* rw);



};



#endif // GUARD_Tile_h
