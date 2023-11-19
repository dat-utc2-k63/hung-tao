#pragma once
#include <SFML/Graphics.hpp>

enum class ObjectType {
    None,
    Apple,
    Durian,
    Boom
};

class FallingObjects {
public:
    FallingObjects();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool checkCollision(sf::Sprite character, int& score, int& lives);
    ObjectType getLastObjectType() const;
    const std::vector<sf::Sprite>& getObjects() const;
    void reset();

private:
    void spawnObject();
    void resetCharacterTexture();
    sf::Texture appleTexture;
    sf::Texture durianTexture;
    sf::Texture boomTexture;
    std::vector<sf::Sprite> objects;
    sf::Font font;
    sf::Text scoreText;
    sf::Text livesText;
    int score;
    int lives;
    float fallSpeed;
    float spawnInterval;
    float spawnTimer;
    int characterTextureIndex;
    int previousScore;
    sf::Sprite background;
    sf::Texture backgroundTexture;
};

