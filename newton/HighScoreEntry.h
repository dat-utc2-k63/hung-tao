
#pragma once
#include <string>

struct HighScoreEntry {
    std::string playerName;
    int score;

    HighScoreEntry() : playerName(""), score(0) {}

    HighScoreEntry(const std::string& name, int s) : playerName(name), score(s) {}

    bool operator<(const HighScoreEntry& other) const {
        return score > other.score;
    }
};
