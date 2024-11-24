#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include "Button.h"

// Function for applying gravity/y-axis acceleration
void applyGravity(sf::RectangleShape& rectangle, sf::Vector2f& velocity, float gravity, float deltaTime) {
    velocity.y += gravity * deltaTime;
    rectangle.move(velocity * deltaTime);
}

int main() {
    int windowHeight = 600;
    int windowWidth = 800;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Physics Engine");

    // Define the Button
    Button toggleFloorButton(700, 30, 100, 50, sf::Color::White, sf::Color::Green);

    // Define the rectangle
    sf::RectangleShape rectangle(sf::Vector2f(50.0f, 50.0f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(375, 0);

    // Define the floor
    sf::RectangleShape floor(sf::Vector2f(800.0f, 20.0f));
    floor.setFillColor(sf::Color::Blue);
    floor.setPosition(0, 300);
    bool floorSolid = true;

    // Define the velocity vector and gravity
    sf::Vector2f velocity(0.0f, 0.0f);
    float gravity = 9.8f;

    // Clock for deltaTime
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;

        float deltaTime = clock.restart().asSeconds();
        deltaTime = std::min(deltaTime, 0.033f);  // Limit deltaTime for consistent behavior

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update the button with deltaTime
        toggleFloorButton.update(window, deltaTime);

        // Check if button is pressed
        if (toggleFloorButton.isPressed()) {
            floorSolid = !floorSolid;
            floor.setFillColor(floorSolid ? sf::Color::Blue : sf::Color::Green);
        }

        // Clear and draw
        window.clear();
        window.draw(floor);
        window.draw(rectangle);
        toggleFloorButton.draw(window);

        sf::Vector2f position = rectangle.getPosition();
        if (position.y > windowHeight) {
            rectangle.setPosition(375, 0);
        }

        if (floorSolid && rectangle.getGlobalBounds().intersects(floor.getGlobalBounds())) {
            velocity.y = 0;
        }
        else {
            applyGravity(rectangle, velocity, gravity, deltaTime);
        }

        window.display();
    }

    return 0;
}
