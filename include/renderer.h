#pragma once

#include "game.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

void clearScreen();
void printTitle();
void printTile(char letter, int state);
void printBoard(const vector<vector<Tile>>& board, int currentRow, const string& currentGuess);
void printKeyboard(const map<char, int>& keyStates);
