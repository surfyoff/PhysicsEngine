#include <SFML/Graphics.hpp>
#include <iostream>
//using namespace sf;

//Button press logic
void buttonPressed(sf::RenderWindow& window, sf::RectangleShape& button, sf::RectangleShape& floor, bool& floorSolid, bool& isClicked) {
    // Only change button state if the mouse was pressed
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isClicked) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            floorSolid = !floorSolid;
            floor.setFillColor(floorSolid ? sf::Color::Blue : sf::Color::Green);  // Toggle floor color based on floorSolid state
        }
        isClicked = true;  // Set the clicked state to true to prevent multiple triggers
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        isClicked = false;  // Reset the clicked state when mouse is released
    }
}

int main() {
    int windowHeight = 600;
    int windowWidth = 800;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Physics Engine");

    //Defining the clock for delta time
    sf::Clock clock;

    //Defining the rectangle
    sf::RectangleShape rectangle(sf::Vector2f(50.0f, 50.0f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(375, 0);

    //Defining the floor
    sf::RectangleShape floor(sf::Vector2f(800.0f, 20.0f));
    floor.setFillColor(sf::Color::Blue);
    floor.setPosition(0, 300);

    //Defining the button
    sf::RectangleShape button(sf::Vector2f(20.0f, 20.0f));
    button.setFillColor(sf::Color::White);
    button.setPosition(700, 30);
    bool floorSolid = true;
    bool isClicked = false;

    //Defining the velocity vector and gravity
    sf::Vector2f velocity(0.0f, 0.0f);
    float gravity = 9.8f;

    while (window.isOpen()) {
        sf::Event event;

        float deltaTime = clock.restart().asSeconds();
        deltaTime = std::min(deltaTime, 0.033f);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        buttonPressed(window, button, floor, floorSolid, isClicked);

        velocity.y += gravity * deltaTime;

        window.clear();
        window.draw(floor);
        window.draw(rectangle);
        window.draw(button);
        sf::Vector2f position = rectangle.getPosition();
        if (position.y > windowHeight) {
            rectangle.setPosition(375, 0);
        }
        if (position.y + rectangle.getSize().y <= floor.getPosition().y &&
            position.y + rectangle.getSize().y >= floor.getPosition().y - 1 && floorSolid) {
            velocity.y = 0;
        }
        else {
            rectangle.move(velocity * deltaTime);
        }
        window.display();               // Display the changes  
    }
    return 0;
}