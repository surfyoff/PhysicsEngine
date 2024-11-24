#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button {
private:
    sf::RectangleShape buttonShape; // The button's rectangle shape
    sf::Color idleColor;            // Button's default color
    sf::Color hoverColor;           // Button's hover color
    bool isPressedState = false;    // Tracks if the button is pressed
    bool isBeingClicked = false;   // To prevent multiple clicks in quick succession
    float clickCooldown = 0.2f;    // Time in seconds between allowed button clicks
    float cooldownTimer = 0.0f;    // Timer to track cooldown

public:
    // Constructor
    Button(float x, float y, float width, float height, sf::Color idleColor, sf::Color hoverColor);

    // Update button state (hover, click, etc.)
    void update(const sf::RenderWindow& window, float deltaTime);

    // Check if button is pressed
    bool isPressed();

    // Draw the button to the window
    void draw(sf::RenderWindow& window) const;
};

#endif
