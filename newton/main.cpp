#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>
#include "CharacterMovement.h"
#include "Menu.h"
#include "FallingObjects.h"
#include "Endgame.h"
#include "HighScoreScreen.h"

enum class GameState {
    Menu,
    Gameplay,
    HighScore,
    Endgame
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1422, 741), "Newton's Game");

    std::stack<GameState> stateStack;
    stateStack.push(GameState::Menu);

    CharacterMovement characterMovement(window);
    FallingObjects FallingObjects;
    Menu menu(window);
    Endgame endgame(window, 0);

    std::vector<HighScoreEntry> highScores; //
    HighScoreScreen highScoreScreen(window);

    highScores = highScoreScreen.readHighScoresFromFile();

    int score = 0;
    int lives = 3;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (stateStack.top() == GameState::Menu) {
                    if (menu.isMouseOverPlayText(window)) {
                        stateStack.pop();
                        stateStack.push(GameState::Gameplay);
                        score = 0;
                        lives = 3;
                    }
                    else if (menu.isMouseOverHighScoreText(window)) {
                        stateStack.pop();
                        stateStack.push(GameState::HighScore);
                    }
                }
                else if (stateStack.top() == GameState::Endgame) {
                    if (endgame.isMouseOverPlayAgain(window)) {
                        stateStack.pop();
                        stateStack.push(GameState::Menu);
                        FallingObjects.reset();
                    }
                }
                else if (stateStack.top() == GameState::HighScore) {
                    if (highScoreScreen.isMouseOverReturn(window)) {
                        stateStack.pop();
                        stateStack.push(GameState::Menu);
                    }
                }
            }
        }

        window.clear();

        if (stateStack.top() == GameState::Menu) {
            menu.draw(window);
        }
        else if (stateStack.top() == GameState::Gameplay) {
            characterMovement.move();
            FallingObjects.update(0.016f);
            FallingObjects.draw(window);

            int collisionResult = FallingObjects.checkCollision(characterMovement.getCharacter(), score, lives);

            if (lives <= 0) {
                stateStack.pop();
                stateStack.push(GameState::Endgame);
                endgame.updateFinalScore(score);

                highScores.push_back({ "Player", score });
                std::sort(highScores.begin(), highScores.end(), [](const HighScoreEntry& a, const HighScoreEntry& b) {
                    return a.score > b.score;
                    });
                highScores.resize(std::min(10, static_cast<int>(highScores.size())));
                highScoreScreen.writeHighScoresToFile(highScores);
            }

            window.draw(characterMovement.getCharacter());
        }
        else if (stateStack.top() == GameState::Endgame) {
            endgame.draw(window);
        }
        else if (stateStack.top() == GameState::HighScore) {
            highScoreScreen.draw(window, highScores);
        }

        window.display();
    }

    return 0;
}
