//
//  world.cpp
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

#include "fallingApple.hpp"
#include "thrownApple1.hpp"
#include "world.hpp"
#include "basket.hpp"
#include "squirrel.hpp"

void World::loop()
{
    window.setFramerateLimit(60);
    
    // Create a texture for the background
    sf::Texture bgTexture;
    // Create a sprite for the background
    sf::Sprite bgSprite;
    
    // Store bgTexture size
    sf::Vector2u TextureSize;
    // Store window size
    sf::Vector2u WindowSize;
    int shotClock = 0;
    int spawnClock = 0;
    Basket basket;
    
    Squirrel squirrel;

    FallingApple appleFalling;
    
    ThrownApple applethrown;
    
//    Squirrel squirrelPos1(150.f,150.f);
//    Squirrel squirrelPos2(400.f,150.f);
//    Squirrel squirrelPos3(150.f,400.f);
//    Squirrel squirrelPos4(400.f,400.f);
//
//    Squirrel squirrelPos5(1000.f,400.f);
//    Squirrel squirrelPos6(1000.f,75.f);
//    Squirrel squirrelPos7(750.f,400.f);
//    Squirrel squirrelPos8(750.f,75.f);
    
    if(!bgTexture.loadFromFile("../background-new.png")){
        std::cerr << "Error while loading texture" << std::endl;
    }
    else{
        TextureSize = bgTexture.getSize(); //Get size of texture.
        WindowSize = window.getSize(); //Get size of window.
        
        // Calculate scale
        float ScaleX = (float) WindowSize.x / TextureSize.x;
        float ScaleY = (float) WindowSize.y / TextureSize.y;
        
        // Set bgSprite scale based on window size
        bgSprite.setTexture(bgTexture);
        bgSprite.setScale(ScaleX, ScaleY);
    }
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            // Command to close window
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(bgSprite);
        
        // Start the clocks for squirrel movement start and apple throw delay
        spawnClock++;
        shotClock++;
        
        // Draw the squirrel on the window
        squirrel.drawSquirrel(window);
        
        if (spawnClock > 100) {
            // Move the squirrel once the clock exceeds 100
            squirrel.moveSquirrel();
        }
        
        // Draw the basket on the window
        basket.drawBasket(window);
        
        // Move the basket using keys A and D
        basket.move(800);
        
        // Create apples on screen that fall from the
        // trees' canopies
        appleFalling.drawFallingApple(window);
        
        
        //populate variables for calling in other functions
        sf::Vector2f getPos = basket.getBasketPosition();
        
        //get thrown apple position and draw the thrown apple
        applethrown.setThrowPosition(getPos);
        applethrown.drawThrownApple(window, shotClock);
        
        
        //reset the game if the squirrel collides with the basket
        if(basket.basketSquirrelCollision(squirrel)){
            reset();
        }
        
        //remove falling apple if it collides with  the basket
        if(appleFalling.fallingAppleBasketCollision(basket)){
            appleFalling.destroyFallingAppleOnCollision();
        }
        
        //reset the squirrel if it and the thrown apple collide
        if (squirrel.squirrelThrownAppleCollision(applethrown)) {
            squirrel.resetSquirrelPosition();
            spawnClock = 0;
        }
  
        window.display();
    }
}

void World::reset()
{
    this->loop();
}
