//
//  thrownApple.cpp
//  testSFML
//
//  Created by Michael Johnson on 9/21/22.
//
//  Group members: Michael Johnson and Reshma Raghavan

#include "thrownApple1.hpp"
#include "basket.hpp"

Basket basket;

//attach sprite to the thrown apple object
void ThrownApple::thrownAppleLoaded () {
    if (!apple.loadFromFile("../apple-new.png")) {
        std::cerr << "error while loading texture" << std::endl;
    }
    else {
        thrownApple.setTexture(apple);
    }
}


//find the position of the basket and set the spawn position of the thrown apple to that location
void ThrownApple::setThrowPosition (sf::Vector2f& basketPosition) {
        thrownApplePosition = basketPosition;
}


//put the thrown apple object on the screen
void ThrownApple::drawThrownApple (sf::RenderWindow& window, int& shotClock) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shotClock > 10){
        //check if the spacebar is pressed and the shot clock is at least 10
    shotClock = 0; //reset the shot clock to 0 to prevent apple machine gun
    thrownAppleLoaded(); //call the function that attaches the sprite
    thrownApple.setPosition(thrownApplePosition); //set spawning location
    thrownApples.push_back(thrownApple); //add object to the vector
    }
    for (int i = 0; i < thrownApples.size(); i++) {
        thrownApples[i].move(xvelocity, 0); //set each objects speed
        window.draw(thrownApples[i]); //draw the object to the screen
    }
}


//remove the thrown apple from the screen when called by other conditions
void ThrownApple::destroyThrownApple () {
    for (int i = 0; i < thrownApples.size(); i++) {
            thrownApples.erase(thrownApples.begin() + i);
    }
}


//get the bounding rectangle for the thrown apple for collision detection
sf::FloatRect ThrownApple::getBounds() {
    for (int i = 0; i < thrownApples.size(); i++)
    return thrownApples[i].getGlobalBounds();
}
