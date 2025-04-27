#pragma once
#include "BowlingGame.hxx"
#include "BowlingGameImpl.hxx"

void BowlingGame::roll(int pins) {
    pImpl->roll(pins);
}

int BowlingGame::score() const {
    return pImpl->score();
}

bool BowlingGame::isGameOver() const {
    return pImpl->isGameOver();
}

void BowlingGame::printScoreBoard() const {
    pImpl->printScoreBoard();
}