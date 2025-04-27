#include "NormalBowlingFrame.hxx"



void NormalBowlingFrame::addRoll(int pins)  {
    rolls.push_back(pins);
}

bool NormalBowlingFrame::isComplete() const  {
    if (rolls.empty())
        return false;
    // A strike completes the frame immediately.
    if (rolls[0] == 10)
        return true;
    // Otherwise, the frame is complete after two rolls.
    return (rolls.size() == 2);
}

std::vector<int> NormalBowlingFrame::getRolls() const  {
    return rolls;
}

int NormalBowlingFrame::baseScore() const  {
    int sum = 0;
    for (auto pins : rolls)
        sum += pins;
    return sum;
}