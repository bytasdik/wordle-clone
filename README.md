# Wordle — Terminal Edition

A faithful Wordle clone for the terminal, written in C++ with ANSI color output. Guess the hidden 5-letter word in 6 tries.

## Screenshot

```
  ██╗    ██╗ ██████╗ ██████╗ ██████╗ ██╗     ███████╗
  ██║    ██║██╔═══██╗██╔══██╗██╔══██╗██║     ██╔════╝
  ██║ █╗ ██║██║   ██║██████╔╝██║  ██║██║     █████╗
  ██║███╗██║██║   ██║██╔══██╗██║  ██║██║     ██╔══╝
  ╚███╔███╔╝╚██████╔╝██║  ██║██████╔╝███████╗███████╗
   ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚══════╝╚══════╝

  Guess the 5-letter word in 6 tries.
  Green = correct spot   Yellow = wrong spot   Gray = not in word

   [S]  [T]  [O]  [M]  [P]      <- correct guess (all green)
```

## Build & Run

**Requirements:** Any C++17-compatible compiler (GCC, Clang, MSVC).

```bash
# Compile
g++ -o wordle wordle.cpp -std=c++17

# Run
./wordle
```

On Windows (MSVC):
```
cl /EHsc /std:c++17 wordle.cpp /Fe:wordle.exe
wordle.exe
```

> **Note:** Windows CMD does not support ANSI colors by default. Use Windows Terminal or enable virtual terminal processing for colors to render correctly.

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
- Correct duplicate-letter handling (e.g. guessing `SPEED` against `ELDER` won't double-yellow the E)
- Play again prompt after each round

## License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.
