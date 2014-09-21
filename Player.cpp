#include "Player.h"
#include <iostream>

Player::Player()
{
    animated = true;
//    pxPosition = 580;
//    pyPosition = 380;



    player1.x = 580;
    player1.y = 380;
}

Player::~Player()
{

}
void Player::LoadResources()
{
    spriteSheet.loadFromFile("player_spritesheet.png");
    playerSprite.setTexture(spriteSheet);
}
void Player::HandleInput()
{


}
void Player::Move(int x, int y)
{
    player1.x += x;
    player1.y += y;
    player1.north = player1.y + 3;
    player1.east = player1.x  + 36;
    player1.south = player1.y + 36;
    player1.west = player1.x  + 4 ;

}
void Player::Animate()
{
    sf::IntRect spriteSubImage(0, 0, 40, 40);
    sf::IntRect spriteSubImage2(40, 0, 40, 40);
    if(animated == true){
        playerSprite.setTextureRect(spriteSubImage);
    }else
    {
        playerSprite.setTextureRect(spriteSubImage2);
    }

}
void Player::draw(int x, int y, sf::RenderWindow* rw)
{
    Animate();

    playerSprite.setPosition(player1.x, player1.y);



    rw->draw(playerSprite);

}
void Player::setAnimated(bool n)
{
    animated = n;
}
void Player::Update()
{
    HandleInput();
}

playerS Player::getPlayer()
{
    return player1;
}
