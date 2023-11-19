
#include "Menu.h"

Menu::Menu(sf::RenderWindow& window) {
    if (!font.loadFromFile("../ttf/Roboto-Regular.ttf")) {

    }

    if (!backgroundTexture.loadFromFile("../image/treeapple.jpeg")) {
    }
    background.setTexture(backgroundTexture);

    title.setFont(font);
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);
    title.setString("Game Menu");
    title.setPosition(300, 100);

    playButton.setFont(font);
    playButton.setCharacterSize(36);
    playButton.setFillColor(sf::Color::White);
    playButton.setString("Play");
    playButton.setPosition(300, 250);

    highscoreButton.setFont(font);
    highscoreButton.setCharacterSize(36);
    highscoreButton.setFillColor(sf::Color::White);
    highscoreButton.setString("Highscore");
    highscoreButton.setPosition(300, 350);
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(background);

    window.draw(title);
    window.draw(playButton);
    window.draw(highscoreButton);
}

bool Menu::isMouseOverPlayText(const sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return playButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}
bool Menu::isMouseOverHighScoreText(const sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return highscoreButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}

