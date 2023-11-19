#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct HighScoreEntry {
    std::string playerName;
    int score;
};

class HighScoreScreen {
public:
    HighScoreScreen(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window, const std::vector<HighScoreEntry>& highScores);
    std::vector<HighScoreEntry> readHighScoresFromFile();
    void writeHighScoresToFile(const std::vector<HighScoreEntry>& highScores);
    bool isMouseOverReturn(const sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text highscoreTitle;
    sf::Text highscoreList;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    std::vector<HighScoreEntry> highScores;
    sf::Text highscoreButton;
    sf::Text returnButton;
};


