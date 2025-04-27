#include "BowlingFrame.hxx"

// NormalFrame for frames 1 to 9.
class NormalBowlingFrame : public BowlingFrame {
private:
    std::vector<int> rolls;
public:
    NormalBowlingFrame() {}

    void addRoll(int pins) override;

    bool isComplete() const override;

    std::vector<int> getRolls() const override;

    int baseScore() const override;
};
