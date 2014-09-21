#include "Tile.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
Tile::Tile()
{

}

Tile::~Tile()
{

}

void Tile::LoadResources()
{
    grass.loadFromFile("grass.png");
    wall.loadFromFile("wall.png");
    drawSprite.setTexture(grass);
    drawSprite2.setTexture(wall);
}
void Tile::AddTile(sf::Texture& texture)
{
    tileVector.push_back(texture);
}

void Tile::draw(int x, int y, sf::RenderWindow* rw)
{

    drawSprite.setPosition(x, y);
    rw->draw(drawSprite);
    drawSprite2.setPosition(x + 20, y);
    rw->draw(drawSprite2);
    drawSprite2.setPosition(x + 60, y);
    rw->draw(drawSprite2);
}



