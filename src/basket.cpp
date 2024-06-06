//
//  basket.cpp
//  testappletreeGame
//
//  Created by Reshma Raghavan on 9/21/22.
//
//  Group members: Michael Johnson and Reshma Raghavan

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "basket.hpp"

Basket::Basket()
{
    this->basket.loadFromFile("../basket-new.png");
    
    //set basket starting position and apply sprite
    this->basketSprite.setTexture(this->basket);
    this->basketSprite.setPosition(150.f, 625.f);
    
    // Update basketPosition to the correct position on screen
    this->basketPosition.x = 150.f;
    this->basketPosition.y = 625.f;
    
    if(!basket.loadFromFile("../basket-new.png")){
        std::cerr << "Error while loading texture" << std::endl;
    }
}

void Basket::move(int winWidth)
{
    //create a velocity variable to move the basket
    float basketXVelocity = 10;
    
    //Keystroke A moves basket left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        //Make sure the basket stays within the bounds of the window
        if (basketPosition.x < 0){ //116 = basket width
            basketXVelocity *= -1;
        }
        //update basket position
        basketPosition.x-=basketXVelocity;
        basketPosition.y = 623.f;
        basketSprite.setPosition(basketPosition);
    }

    //Keystroke D moves basket right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        //Make sure the basket stays within the bounds of the window
        if (basketPosition.x > 1150){
            basketXVelocity *= -1;
        }
        //update basket position
        basketPosition.x+=basketXVelocity;
        basketPosition.y = 623.f;
        basketSprite.setPosition(basketPosition);
    }
}

//place basket on the screen
void Basket::drawBasket(sf::RenderWindow& window)
{
    window.draw(basketSprite);
}

//get the current position of the basket for other functions
sf::Vector2f Basket::getBasketPosition()
{
    return basketPosition;
}

//get bounding rectangle for collision detection
sf::FloatRect Basket::getBasketGlobalBounds()
{
    return basketSprite.getGlobalBounds();
}

//determine if the squirrel and basket collide
bool Basket::basketSquirrelCollision(Squirrel& squirrel)
{
    if(getBasketGlobalBounds().intersects(squirrel.getSquirrelGlobalBounds())){
        return true;
    }
    return false;
}
