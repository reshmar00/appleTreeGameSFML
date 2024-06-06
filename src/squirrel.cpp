//
//  squirrel.cpp
//  testappletreeGame
//
//  Created by Reshma Raghavan on 9/22/22.
//
//  Group members: Michael Johnson and Reshma Raghavan

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "fallingApple.hpp"
#include "thrownApple1.hpp"
#include "world.hpp"
#include "basket.hpp"
#include "squirrel.hpp"

#include <iostream>

Squirrel::~Squirrel(){
}

Squirrel::Squirrel()
{

    this->squirrel.loadFromFile("../squirrel-new.png");
    
    //set the squirrels starting position and apply the sprite
    this->squirrelSprite.setTexture(this->squirrel);
    this->squirrelSprite.setPosition(50.f, 625.f);
    
    // Update squirrelPosition to the correct position on screen
    this->squirrelPosition.x = 50.f;
    this->squirrelPosition.y = 625.f;
    
    if(!squirrel.loadFromFile("../squirrel-new.png")){
        std::cerr << "Error while loading texture" << std::endl;
    }
}

Squirrel::Squirrel(float posOfSquirrelX, float posOfSquirrelY)
{
    this->squirrel.loadFromFile("../squirrel-new.png");
    this->squirrelSprite.setTexture(this->squirrel);
    
    this->squirrelSprite.setPosition(posOfSquirrelX, posOfSquirrelY);
    
    // Update squirrelPosition to the correct position on screen
    this->squirrelPosition.x = posOfSquirrelX;
    this->squirrelPosition.y = posOfSquirrelY;
}

//apply the squirrel object to the screen
void Squirrel::drawSquirrel(sf::RenderWindow& window){
    window.draw(squirrelSprite);
}

//get the bounding rectangle for collision detection
sf::FloatRect Squirrel::getSquirrelGlobalBounds()
{
    return squirrelSprite.getGlobalBounds();
}

//set the squirrels movement when called
void Squirrel::moveSquirrel(){
        squirrelSprite.move(3, 0);
    }

//detect if there was a collision with the squirrel and a thrown apple
bool Squirrel::squirrelThrownAppleCollision (ThrownApple& appleThrown) {
    if (getSquirrelGlobalBounds().intersects(appleThrown.getBounds())){
        return true;
    }
    else {
        return false;
    }
}

//reset squirrel position when called, specifically when hit by thrown apple
void Squirrel::resetSquirrelPosition () {
    squirrelSprite.setPosition(50.f, 625.f);
    squirrelSprite.move(0,0);
}
