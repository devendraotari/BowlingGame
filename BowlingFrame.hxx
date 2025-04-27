#pragma once
#include <vector>

// Abstract base class for a bowling frame.
class BowlingFrame {
public:
    virtual ~BowlingFrame() {}
    // Add a roll's pin count to the BowlingFrame.
    virtual void addRoll(int pins) = 0;
    // Return whether the BowlingFrame is complete (no further rolls allowed).
    virtual bool isComplete() const = 0;
    // Return the rolls in this BowlingFrame.
    virtual std::vector<int> getRolls() const = 0;
    // Return the basic score (simply sum of the BowlingFrame's rolls).
    virtual int baseScore() const = 0;
};
