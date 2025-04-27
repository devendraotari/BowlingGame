#pragma once

#include <vector>
#include "BowlingGame.hxx"
#include "TenthBowlingFrame.hxx"
#include "NormalBowlingFrame.hxx"
#include "BowlingGameUtil.hxx"
#include <string>
#include <iostream>

// The hidden implementation class.
class BowlingGame::Impl {
public:
    std::vector<std::unique_ptr<BowlingFrame>> frames;

    // Process a roll.
    void roll(int pins);

    // Calculate the final score using bonus rules for strikes and spares.
    int score() const;

    // Returns true if the game is over (10 frames and the 10th is complete).
    bool isGameOver() const;

    // Print a formatted scoreboard using hyphens and pipes.
    void printScoreBoard() const; 
};
