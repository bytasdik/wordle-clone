#include "../include/renderer.h"
#include "../include/colors.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printTitle() {
    cout << BOLD << FG_WHITE
         << "\n"
         << "  ██╗    ██╗ ██████╗ ██████╗ ██████╗ ██╗     ███████╗\n"
         << "  ██║    ██║██╔═══██╗██╔══██╗██╔══██╗██║     ██╔════╝\n"
         << "  ██║ █╗ ██║██║   ██║██████╔╝██║  ██║██║     █████╗  \n"
         << "  ██║███╗██║██║   ██║██╔══██╗██║  ██║██║     ██╔══╝  \n"
         << "  ╚███╔███╔╝╚██████╔╝██║  ██║██████╔╝███████╗███████╗\n"
         << "   ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚══════╝╚══════╝\n"
         << RESET
         << FG_GRAY   << "  Guess the 5-letter word in 6 tries.\n" << RESET
         << FG_GREEN  << "  Green"  << RESET << " = correct spot  "
         << FG_YELLOW << "Yellow"   << RESET << " = wrong spot  "
         << FG_GRAY   << "Gray"     << RESET << " = not in word\n\n";
}

void printTile(char letter, int state) {
    string display = {' ', letter, ' '};
    switch (state) {
        case 3: cout << BG_GREEN  << BOLD << display << RESET; break;
        case 2: cout << BG_YELLOW << BOLD << display << RESET; break;
        case 1: cout << BG_GRAY          << display << RESET; break;
        default:
            if (letter == ' ') cout << BG_DARK << "   " << RESET;
            else               cout << BG_DARK << BOLD << display << RESET;
            break;
    }
}

void printBoard(const vector<vector<Tile>>& board, int currentRow, const string& currentGuess) {
    cout << "\n";
    for (int row = 0; row < 6; row++) {
        cout << "  ";
        for (int col = 0; col < 5; col++) {
            if (row < (int)board.size()) {
                printTile(board[row][col].letter, board[row][col].state);
            } else if (row == currentRow) {
                char c = col < (int)currentGuess.size() ? currentGuess[col] : ' ';
                printTile(c, 0);
            } else {
                printTile(' ', 0);
            }
            if (col < 4) cout << " ";
        }
        cout << "\n";
        if (row < 5) cout << "\n";
    }
    cout << "\n";
}

void printKeyboard(const map<char, int>& keyStates) {
    string rows[3] = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
    for (int r = 0; r < 3; r++) {
        cout << "  ";
        if (r == 1) cout << " ";
        if (r == 2) cout << "  ";
        for (char c : rows[r]) {
            auto it = keyStates.find(c);
            int state = (it != keyStates.end()) ? it->second : -1;
            switch (state) {
                case 3: cout << BG_GREEN  << BOLD << " " << c << " " << RESET; break;
                case 2: cout << BG_YELLOW << BOLD << " " << c << " " << RESET; break;
                case 1: cout << BG_GRAY          << " " << c << " " << RESET; break;
                default: cout << BG_DARK << FG_WHITE << " " << c << " " << RESET; break;
            }
            cout << " ";
        }
        cout << "\n\n";
    }
}