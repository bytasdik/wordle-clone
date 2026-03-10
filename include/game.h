#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

struct Tile {
    char letter;
    int state; // 0=empty, 1=absent, 2=present, 3=correct
};

vector<Tile> evaluateGuess(const string& guess, const string& solution);
void updateKeyStates(map<char, int>& keyStates, const vector<Tile>& tiles);
bool isValidWord(const string& word);
string toUpper(string s);
