#include "BowlingFrame.hxx"

// TenthBowlingFrame with special handling for bonus throws.
class TenthBowlingFrame : public BowlingFrame {
private:
    std::vector<int> rolls;
public:
    TenthBowlingFrame() {}

    void addRoll(int pins) override;

    bool isComplete() const override;

    std::vector<int> getRolls() const override;

    int baseScore() const override;
};
