#include "Level.h"
#include "Tile.h"

#include <iostream>
Level::Level()
{

}

levelCrap Level::getTile(int x, int y){

        return objectofLevelCrap[levelMap [ (y * map_width) + x] ];
};

Level::~Level()
{

}
void Level::ConstructLevel()
{

}

void Level::LoadResources()
{
    tilesheet.loadFromFile("tilesheet.png");
    drawSprite.setTexture(tilesheet);


}


void Level::draw(int z, int c, sf::RenderWindow* rw)
{

    for(int x = 0; x < map_width; ++x)
    {
        for(int y = 0; y < map_height; ++y)
        {
            const levelCrap& b = getTile(x, y);
            //check view


            sf::View view(sf::FloatRect(0, 0, 1200, 800));
            view.move(xMove, yMove);

            sf::IntRect subImageRect(b.xorigin, b.yorigin, 40, 40);
            drawSprite.setTextureRect(subImageRect);
            drawSprite.setPosition(x * 40, y * 40);
            rw->setView(view);
            rw->draw(drawSprite);
        }
    }
}

void Level::MoveLevel(int x, int y)
{
    xMove+=x;
    yMove+=y;
}

void Level::Update()
{

   // std::cout << getTile(30, 0).solid << "   " << std::endl;
}
