#include <iostream>
#include <vector>
#include <memory>
#include "NormalBowlingFrame.hxx"
#include "TenthBowlingFrame.hxx"
#include "BowlingGame.hxx"
#include "BowlingGameUtil.hxx"

using namespace std;

// Main function demonstrating two sample games.
// One simulates a perfect game (all strikes) and
// the other a mixed game with a spare and strike.
//
int main() {
    BowlingGame game;
    cout << "Welcome to the Bowling Game Score Calculator!\n";
    cout << "Enter the number of pins knocked down in each roll.\n\n";

    // Loop until the game (10 frames) is complete.
    while (!game.isGameOver()) {
        int pins;
        cout << "Enter pins knocked down for next roll (0-10): ";
        cin >> pins;
        // Validate input (basic check).
        if (!cin || pins < 0 || pins > 10) {
            cout << "Invalid input. Please enter a number between 0 and 10.\n";
            // Clear error flags and ignore the rest of the line.
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        game.roll(pins);
        cout << "\nCurrent Scoreboard:\n";
        game.printScoreBoard();
        cout << "\n";
    }

    cout << "\nFinal Scoreboard:\n";
    game.printScoreBoard();
    cout << "Game Over! Final Score: " << game.score() << "\n";

    return 0;
}
