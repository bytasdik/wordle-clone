#include "../include/game.h"
#include <cctype>

using namespace std;

vector<Tile> evaluateGuess(const string& guess, const string& solution) {
    vector<Tile> result(5);
    string remaining = solution;

    for (int i = 0; i < 5; i++) {
        result[i].letter = guess[i];
        if (guess[i] == solution[i]) {
            result[i].state = 3;
            remaining[i] = '*';
        } else {
            result[i].state = 1;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (result[i].state == 3) continue;
        size_t pos = remaining.find(guess[i]);
        if (pos != string::npos) {
            result[i].state = 2;
            remaining[pos] = '*';
        }
    }
    return result;
}

void updateKeyStates(map<char, int>& keyStates, const vector<Tile>& tiles) {
    for (const auto& tile : tiles) {
        auto it = keyStates.find(tile.letter);
        if (it == keyStates.end() || it->second < tile.state)
            keyStates[tile.letter] = tile.state;
    }
}

bool isValidWord(const string& word) {
    if (word.size() != 5) return false;
    for (char c : word) if (!isalpha(c)) return false;
    return true;
}

string toUpper(string s) {
    for (char& c : s) c = toupper(c);
    return s;
}