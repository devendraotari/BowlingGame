#include "TenthBowlingFrame.hxx"


void TenthBowlingFrame::addRoll(int pins)  {
    rolls.push_back(pins);
}

bool TenthBowlingFrame::isComplete() const  {
    // At least two rolls needed.
    if (rolls.size() < 2)
        return false;
    // In the tenth, if the first roll was a strike or if the two rolls form a spare,
    // an extra (third) roll is allowed.
    if (rolls.size() == 2) {
        if (rolls[0] == 10 || (rolls[0] + rolls[1] == 10))
            return false;
        return true;
    }
    // Three rolls complete the frame.
    if (rolls.size() == 3)
        return true;
    return false;
}

std::vector<int> TenthBowlingFrame::getRolls() const  {
    return rolls;
}

int TenthBowlingFrame::baseScore() const  {
    int sum = 0;
    for (auto pins : rolls)
        sum += pins;
    return sum;
}