# Wordle — Terminal Edition

A faithful Wordle clone for the terminal, written in C++ with ANSI color output. Guess the hidden 5-letter word in 6 tries.

## Project Structure

```
wordle/
├── CMakeLists.txt
├── include/
│   ├── colors.h      # ANSI color/style macros
│   ├── game.h        # Tile struct + game logic declarations
│   ├── renderer.h    # Display function declarations
│   └── words.h       # Word list
└── src/
    ├── main.cpp      # Entry point and game loop
    ├── game.cpp      # evaluateGuess, updateKeyStates, isValidWord, toUpper
    └── renderer.cpp  # clearScreen, printTitle, printBoard, printKeyboard
```

## Build & Run

### CMake (recommended)

```bash
cmake -B build
cmake --build build
./build/wordle
```

### Manual (g++)

```bash
g++ -std=c++17 -Iinclude -o wordle src/main.cpp src/game.cpp src/renderer.cpp
./wordle
```

### Windows (MSVC)

```
cl /EHsc /std:c++17 /Iinclude src\main.cpp src\game.cpp src\renderer.cpp /Fe:wordle.exe
wordle.exe
```

> **Note:** Windows CMD does not support ANSI colors by default. Use Windows Terminal or enable virtual terminal processing.

## How to Play

1. Type a 5-letter word and press **Enter**
2. Tiles reveal how close your guess was:
   - 🟩 **Green** — correct letter, correct position
   - 🟨 **Yellow** — correct letter, wrong position
   - ⬛ **Gray** — letter not in the word
3. Use the color-coded keyboard tracker at the bottom to keep track of used letters
4. You have **6 attempts** to guess the word

Type `QUIT` or `EXIT` at any time to leave the game.

## Features

- 80-word randomized word list, new word each game
- Color-coded board and on-screen keyboard tracker
- Correct duplicate-letter handling
- Play again prompt after each round

## License

Unlicensed — do whatever you want with it.
