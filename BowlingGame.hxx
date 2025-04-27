#pragma once
#include <memory>

//@brief BowlingGame class oject is used to represent a single game of ten frames
class BowlingGame {
public:
    BowlingGame();
    ~BowlingGame();

    // @brief Record a roll where 'pins' pins are knocked down.
    // @param[in] pins input integer for number of pins knocked out in a roll value should be 0-10.
    void roll(int pins);
    // @brief Return the total score of the game.
    int score() const;

    // @brief util function to check if game is completed
    bool isGameOver() const;

    // @brief util function to print the score board
    void printScoreBoard() const;

private:
    //@brief The internal implementation is hidden using pimpl.
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
