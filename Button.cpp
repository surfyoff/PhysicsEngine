#include "Button.h"

// Constructor
Button::Button(float x, float y, float width, float height, sf::Color idleColor, sf::Color hoverColor)
    : idleColor(idleColor), hoverColor(hoverColor), isPressedState(false), isBeingClicked(false), cooldownTimer(0.0f) {
    buttonShape.setPosition(x, y);
    buttonShape.setSize({ width, height });
    buttonShape.setFillColor(idleColor);
}

// Update button state (hover effect and click detection)
void Button::update(const sf::RenderWindow& window, float deltaTime) {
    // Update the cooldown timer
    if (cooldownTimer > 0.0f) {
        cooldownTimer -= deltaTime;
    }

    // Get mouse position
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    // Check if mouse is over button
    if (buttonShape.getGlobalBounds().contains(mousePosF)) {
        buttonShape.setFillColor(hoverColor);

        // Check if mouse is clicked and cooldown has passed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cooldownTimer <= 0.0f && !isBeingClicked) {
            // Prevent registering another click if already clicked
            isPressedState = true;
            isBeingClicked = true; // Prevent further clicking until cooldown ends
            cooldownTimer = clickCooldown; // Reset cooldown timer
        }
    }
    else {
        buttonShape.setFillColor(idleColor);
    }

    // Reset click state when mouse is not pressed anymore
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        isBeingClicked = false;
    }
}

// Draw the button
void Button::draw(sf::RenderWindow& window) const {
    window.draw(buttonShape);
}

// Check if button is pressed
bool Button::isPressed() {
    // If pressed, return true and reset the state for next press
    if (isPressedState) {
        isPressedState = false; // Reset the press state
        return true;
    }
    return false;
}
