//
//  fallingApple.cpp
//  testSFML
//
//  Created by Michael Johnson on 9/21/22.
//
//  Group members: Michael Johnson and Reshma Raghavan

#include "fallingApple.hpp"
#include "basket.hpp"



//check that the image for the sprite works and apply it to our object
void FallingApple::fallingAppleLoaded () {
    if (!fallingAppleTexture.loadFromFile("../apple-new.png")) {
        std::cerr << "error while loading texture" << std::endl;
    }
    else {
        fallingApple.setTexture(fallingAppleTexture);
    }
}


//assemble all pieces of the falling apple when the whenever the spawn clock reaches 150
void FallingApple::buildFallingApple () {
    if (spawnclock > 150) { //ensure apples spawn at a sane rate
        fallingAppleLoaded(); //attach sprite
        spawnFallingApple(fallingApplePosition); //call the randomizer for a spawn location
        fallingApple.setPosition(fallingApplePosition); //attach spawn location to the falling apple object
        fallingApples.push_back(fallingApple); //add to vector
        //reset the spawnclock to 0 so the spawning doesn't happen continuously
        spawnclock = 0;
    }
    //increment the spawnclock so it keeps pace
    else {
        spawnclock++;
    }
}


//draw the assembled falling apple on the screen with it's variables
void FallingApple::drawFallingApple (sf::RenderWindow& window) {
    buildFallingApple(); //attach sprite, position, and add to the vector
    for (int i = 0; i < fallingApples.size(); i++) {
        fallingApples[i].move(0, yvelocity); //define falling rate
        window.draw(fallingApples[i]); //draw the apple on the screen
        destroyFallingApple(); //remove the apple if it is offscreen
    }
}


//remove apple object if they move beyond the screen
void FallingApple::destroyFallingApple() {
    //loop through the falling apple objects
    for (int i = 0; i < fallingApples.size(); i++) {
        //check if they are below the lower bounds of the screen and remove them if they are
        if (fallingApples[i].getPosition().y > 960) {
            fallingApples.erase(fallingApples.begin() + i);
        }
    }
}


//remove apples upon call. specifically when the program detects an intersect of the apple and basket
void FallingApple::destroyFallingAppleOnCollision() {
    for (int i = 0; i < fallingApples.size(); i++) {
            fallingApples.erase(fallingApples.begin() + i);
    }
}


// assign the spawn coordinates for the apple on the left tree
void FallingApple::spawnAppleLeft (sf::Vector2f& spawnPositionLeft) {
    std::srand(time(NULL));
    spawnPositionLeft.x = rand()% 400 + 150;
    spawnPositionLeft.y = rand()% 400 + 150;
    
}


// assign the spawn coordinates for the apple on the right tree
void FallingApple::spawnAppleRight (sf::Vector2f& spawnPositionRight) {
    std::srand(time(NULL));
    spawnPositionRight.x = rand()% 1000 + 750;
    spawnPositionRight.y = rand()% 750 + 75;
}


// assign spawn coordinates for the apple to one of the trees
void FallingApple::spawnFallingApple (sf::Vector2f& spawnposition) {
    //get a ranom number and determine if it is even or odd
    if (rand() % 2 == 0) {
        //if the random number is even, the position is on the left tree
        spawnAppleLeft(spawnposition);
    }
    else {
        //if the random number is odd, the position is on the right tree
        spawnAppleRight(spawnposition);
    }
}


//get the bounding rectangle for falling apple objects to help determine collisions
sf::FloatRect FallingApple::fallingAppleGlobal () {
    for (int i = 0; i < fallingApples.size(); i++)
    return fallingApples[i].getGlobalBounds();
}


//return true if there is an intersect of the apple and basket bounding rectangles
bool FallingApple::fallingAppleBasketCollision(Basket& basket)
{
    if(fallingAppleGlobal().intersects(basket.getBasketGlobalBounds())){
        return true;
    }
    //return false otherwise
    return false;
}
