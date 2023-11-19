#pragma once
#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    bool isMouseOverPlayText(const sf::RenderWindow& window);
    bool isMouseOverHighScoreText(const sf::RenderWindow& window);
private:
    sf::Font font;
    sf::Text title;
    sf::Text playButton;
    sf::Text highscoreButton;
    sf::Sprite background;
    sf::Texture backgroundTexture;

};
