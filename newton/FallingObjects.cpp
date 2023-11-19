
#include "FallingObjects.h"
#include <iostream>

FallingObjects::FallingObjects() {
    appleTexture.loadFromFile("../image/apple1.jpeg");
    durianTexture.loadFromFile("../image/saurieng1.jpeg");
    boomTexture.loadFromFile("../image/boom1.jpeg");
    if (!backgroundTexture.loadFromFile("../image/treeapple.jpeg")) {
    }
    background.setTexture(backgroundTexture);
    fallSpeed = 10.0f;
    spawnInterval = 10.0f;
    spawnTimer = 0.0f;

    characterTextureIndex = 0;

    score = 0;
    lives = 3;

    font.loadFromFile("../ttf/Roboto-Regular.ttf");

    livesText.setFont(font);
    livesText.setCharacterSize(24);
    livesText.setFillColor(sf::Color::Red);
    livesText.setPosition(10, 40);

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Green);
    scoreText.setPosition(10, 10);
}

void FallingObjects::update(float deltaTime) {
    spawnTimer += deltaTime;

    if (spawnTimer >= spawnInterval) {
        spawnObject();
        spawnTimer = 0.0f;
    }

    for (size_t i = 0; i < objects.size(); i++) {
        objects[i].move(0, fallSpeed * deltaTime);

        if (objects[i].getPosition().y > 800) {
            objects.erase(objects.begin() + i);
        }
    }

    if (score >= previousScore + 2000) {
        fallSpeed += 15.0f;
        spawnInterval -= 1.0;
        previousScore = score;
    }

    previousScore = score;
}

void FallingObjects::spawnObject() {
    int randomValue = std::rand() % 100;

    sf::Sprite object;

    if (randomValue < 70) {
        object.setTexture(appleTexture);
    }
    else if (randomValue < 90) {
        object.setTexture(durianTexture);
    }
    else {
        object.setTexture(boomTexture);
    }

    float x = static_cast<float>(std::rand() % 1400);
    object.setPosition(x, 0);
    objects.push_back(object);
}

bool FallingObjects::checkCollision(sf::Sprite character, int& score, int& lives) {
    livesText.setString("Lives: " + std::to_string(lives));
    scoreText.setString("Score: " + std::to_string(score));
    for (size_t i = 0; i < objects.size(); i++) {
        if (character.getGlobalBounds().intersects(objects[i].getGlobalBounds())) {
            if (objects[i].getTexture() == &appleTexture) {
                objects.erase(objects.begin() + i);
                score += 100;
            }
            else if (objects[i].getTexture() == &durianTexture) {
                objects.erase(objects.begin() + i);
                lives--;
                resetCharacterTexture();
            }
            else {
                lives--;
                resetCharacterTexture();
            }

            livesText.setString("Lives: " + std::to_string(lives));
            scoreText.setString("Score: " + std::to_string(score));

            return true;
        }
    }

    return false;
}

void FallingObjects::draw(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(livesText);
    window.draw(scoreText);

    for (const sf::Sprite& object : objects) {
        window.draw(object);
    }
}

void FallingObjects::resetCharacterTexture() {
    if (characterTextureIndex == 0) {
        characterTextureIndex = 1;
    }
}
void FallingObjects::reset() {

    objects.clear();
}
