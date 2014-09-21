#include "Engine.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Engine::Engine()
{
    //Constructor rules must go here.
    player = new Player();
    tile = new Tile();
    level = new Level();

}

Engine::~Engine()
{
    //Destruct variable access memory here.
}

void Engine::Init()
{
    window = new sf::RenderWindow(sf::VideoMode(1200, 800, 32), "Tridents of Ardeus", sf::Style::Close);


    LoadResource();
    MainLoop();
}

void Engine::MainLoop()
{

    while(window->isOpen())
    {
       TakeInput();
       Update();
       Render();

    }
}
void Engine::LoadResource()
{
    player->LoadResources();
    tile->LoadResources();
    level->LoadResources();
}

int Engine::Collision()
{
    player->getPlayer();
    //std::cout << "Player x: " << player->getPlayer().x << std::endl;
    //std::cout << "Player y: " << player->getPlayer().y << std::endl;

    int playerTilePosX = player->getPlayer().x / 40;
    //std::cout << player->getPlayer().x << std::endl;
    int playerTilePoxY = player->getPlayer().y / 40;
    //std::cout << playerTilePos << std::endl;

    //Top point of bounding box.
    int playerTop = player->getPlayer().north / 40;
    int playerBottom = player->getPlayer().south / 40;




    //use the get tile on a rotational basis for the axis aligned bounding box.
    bool tileX = level->getTile(playerTilePosX, playerTilePoxY).solid;

    bool topcollision = level->getTile(playerTilePosX, playerTop).solid;

    bool bottomcollision = level->getTile(playerTilePosX, playerBottom).solid;

//   // std::cout << tileX;
    if (topcollision == true){
        std::cout << "Top collision detected" << std::endl;
        std::cout << "Players Y" << player->getPlayer().y;
        std::cout << "current tile" << playerTilePoxY;
    }

    if (bottomcollision == true){
        std::cout << "Bottom collision detected" << std::endl;
        std::cout << "Players Y" << player->getPlayer().y;
        std::cout << "current tile" << playerTilePoxY;
    }




}
void Engine::TakeInput()
{

    while(window->pollEvent(evt))
    {
        if(evt.type == sf::Event::Closed)
            window->close();

        sf::Vector2i pixelPos;
        pixelPos = sf::Mouse::getPosition();
        sf::Vector2i result;





        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            int playerTilePosY = player->getPlayer().y / 40;
            int playerTilePosX = player->getPlayer().x / 40;
            int northPoint = player->getPlayer().north / 40;
            int southPoint = player->getPlayer().south / 40;
            int eastPoint = player->getPlayer().east / 40;
            int westPoint = player->getPlayer().west / 40;
            std::cout << "*******************************************" << std::endl;
           // std::cout << "*  PlayerTilePosY    :" << playerTilePosY <<         "  PlayerTilePosX      :" << playerTilePosX << std::endl;
            std::cout << "*  northPoint        :"       << northPoint <<       "  SouthPoint          :" << southPoint <<  std::endl;
            std::cout << "*  eastPoint         :"       << eastPoint <<       "  westPoint           :" << westPoint <<  std::endl;
            std::cout << "*******************************************" << std::endl;
            std::cout << "" << std::endl;
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            int playerTilePosX = player->getPlayer().x;
            std::cout << "*******************************************" << std::endl;
            std::cout << "*      Player X position: " << player->getPlayer().x << std::endl;

            std::cout << "*                                          " << std::endl;
            std::cout << "*      Player Y position: " << player->getPlayer().y << std::endl;
            std::cout << "*                                          " << std::endl;
            std::cout << "*      Player North position: " << player->getPlayer().north << std::endl;
            std::cout << "*******************************************" << std::endl;
            std::cout << "" << std::endl;

        }


        if(evt.type == sf::Event::KeyPressed)
        {

            //change this to collision(x, y) and allow each button to call a seperate collision event, It makes more sense


            if(evt.key.code == sf::Keyboard::W)
            {
                player->setAnimated(true);
                player->Move(0, -1);
                level->MoveLevel(0, -1);
            }
            if(evt.key.code == sf::Keyboard::S)
            {
                player->setAnimated(false);
                player->Move(0, 1);
                level->MoveLevel(0, 1);
            }
            if(evt.key.code == sf::Keyboard::A)
            {
                level->MoveLevel(-1, 0);
                player->setAnimated(true);
                player->Move(-1, 0);
            }
            if(evt.key.code == sf::Keyboard::D)
            {
                level->MoveLevel(1, 0);
                player->setAnimated(false);
                player->Move(1, 0);
            }
       }
    }




}
void Engine::Update()
{
   // level->getTile(500, 500);
    player->Update();
    level->Update();
    Collision();
}
void Engine::Render()
{
    window->clear();

    level->draw(0, 0, window);
    player->draw(0, 0, window);
    //tile->draw(30, 30, window);
    window->display();

}
