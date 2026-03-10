#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>

#include "../include/game.h"
#include "../include/renderer.h"
#include "../include/words.h"
#include "../include/colors.h"

using namespace std;

int main() {
    srand((unsigned)time(nullptr));

    bool playAgain = true;
    while (playAgain) {
        string solution = WORD_LIST[rand() % WORD_LIST.size()];
        vector<vector<Tile>> board;
        map<char, int> keyStates;
        string currentGuess, message;
        bool gameOver = false, won = false;

        while (!gameOver) {
            clearScreen();
            printTitle();
            printBoard(board, (int)board.size(), currentGuess);
            printKeyboard(keyStates);

            if (!message.empty())
                cout << "  " << BOLD << FG_WHITE << message << RESET << "\n\n";

            cout << "  " << FG_WHITE << "Your guess: " << RESET;
            string input;
            getline(cin, input);
            input = toUpper(input);

            if (input == "QUIT" || input == "EXIT") {
                cout << "\n  " << FG_GRAY << "Thanks for playing!\n\n" << RESET;
                return 0;
            }

            if (!isValidWord(input)) {
                message = "Please enter a valid 5-letter word.";
                continue;
            }

            auto tiles = evaluateGuess(input, solution);
            board.push_back(tiles);
            updateKeyStates(keyStates, tiles);

            bool correct = true;
            for (auto& t : tiles) if (t.state != 3) { correct = false; break; }

            if (correct) {
                won = gameOver = true;
                vector<string> winMsgs = {
                    "Genius! First try!", "Magnificent!", "Impressive!",
                    "Splendid!", "Great!", "Phew, that was close!"
                };
                message = winMsgs[min((int)board.size() - 1, 5)];
            } else if ((int)board.size() >= 6) {
                gameOver = true;
                message = "The word was: " + solution;
            } else {
                message = "";
                currentGuess = "";
            }
        }

        clearScreen();
        printTitle();
        printBoard(board, 6, "");
        printKeyboard(keyStates);
        cout << "  " << BOLD << (won ? FG_GREEN : FG_YELLOW) << message << RESET << "\n\n";

        cout << "  Play again? (y/n): ";
        string again;
        getline(cin, again);
        playAgain = (!again.empty() && tolower(again[0]) == 'y');
    }

    cout << "\n  " << FG_GRAY << "Thanks for playing Wordle!\n\n" << RESET;
    return 0;
}