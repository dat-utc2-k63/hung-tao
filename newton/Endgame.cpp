
#include "Endgame.h"
int lives;
Endgame::Endgame(sf::RenderWindow& window, int score) {
    if (!font.loadFromFile("../ttf/Roboto-Regular.ttf")) {
    }
    if (!backgroundTexture.loadFromFile("../image/treeapple.jpeg")) {
    }
    background.setTexture(backgroundTexture);

    endgameTitle.setFont(font);
    endgameTitle.setCharacterSize(60);
    endgameTitle.setFillColor(sf::Color::Red);
    endgameTitle.setString("Game Over!");
    endgameTitle.setPosition(650, 100);

    finalScore = score;
    finalScoreText.setFont(font);
    finalScoreText.setCharacterSize(60);
    finalScoreText.setFillColor(sf::Color::White);
    finalScoreText.setPosition(500, 250);

    Playagain.setFont(font);
    Playagain.setCharacterSize(60);
    Playagain.setFillColor(sf::Color::White);
    Playagain.setString("Play again!");
    Playagain.setPosition(350, 350);

}
void Endgame::updateFinalScore(int score) {
    finalScore = score;
}

void Endgame::draw(sf::RenderWindow& window) {
    window.draw(background);
    std::string scoreString = "My Score: " + std::to_string(finalScore);
    finalScoreText.setString(scoreString);
    window.draw(endgameTitle);
    window.draw(finalScoreText);
    window.draw(Playagain);
}
int Endgame::getScore() const {
    return finalScore;
}
int Endgame::getLives() const {
    return lives;
}
bool Endgame::isMouseOverPlayAgain(const sf::RenderWindow& window) const {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return Playagain.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}
