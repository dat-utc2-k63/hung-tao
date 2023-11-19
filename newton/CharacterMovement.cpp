
#include "CharacterMovement.h"
#include <iostream>

sf::Texture CharacterMovement::characterTexture;

CharacterMovement::CharacterMovement(sf::RenderWindow& window) {
    if (characterTexture.getSize().x == 0) {
        if (!characterTexture.loadFromFile("../image/charactor.png")) {
            std::cerr << "Failed to load character texture!" << std::endl;
        }
    }

    character.setTexture(characterTexture);
    movementSpeed = 100.0f;
    characterHeight = character.getLocalBounds().height;

    sf::Vector2u windowSize = window.getSize();
    windowWidth = static_cast<float>(windowSize.x);

    character.setPosition(windowWidth / 2.0f, windowSize.y - characterHeight);
}

void CharacterMovement::move() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition();

    if (mousePosition.x < 0) {
        mousePosition.x = 0;
    }
    if (mousePosition.x > windowWidth - character.getLocalBounds().width) {
        mousePosition.x = static_cast<int>(windowWidth - character.getLocalBounds().width);
    }

    character.setPosition(static_cast<float>(mousePosition.x), character.getPosition().y);
}

sf::Sprite CharacterMovement::getCharacter() const {
    return character;
}

float CharacterMovement::getMovementSpeed() const {
    return movementSpeed;
}

float CharacterMovement::getCharacterHeight() const {
    return characterHeight;
}
