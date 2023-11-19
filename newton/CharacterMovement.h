#pragma once
#include <SFML/Graphics.hpp>

class CharacterMovement {
public:
    CharacterMovement(sf::RenderWindow& window);
    void move();
    sf::Sprite getCharacter() const;
    float getMovementSpeed() const;
    float getCharacterHeight() const;

private:
    static sf::Texture characterTexture;
    sf::Sprite character;
    float movementSpeed;
    float characterHeight;
    float windowWidth;
};
