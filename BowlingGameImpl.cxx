#include "BowlingGameImpl.hxx"

BowlingGame::BowlingGame() : pImpl(std::make_unique<Impl>()) {}

BowlingGame::~BowlingGame() = default;

// Record a roll.
void BowlingGame::Impl::roll(int pins) {
    // If game is over (10 frames and last frame complete), ignore further rolls.
    if (frames.size() == 10 && frames.back()->isComplete())
        return;
    // If there’s no frame or the last frame is complete, create a new frame.
    if (frames.empty() || frames.back()->isComplete()) {
        if (frames.size() < 9) {
            frames.push_back(std::make_unique<NormalBowlingFrame>());
        }
        else {
            // The 10th frame.
            frames.push_back(std::make_unique<TenthBowlingFrame>());
        }
    }
    frames.back()->addRoll(pins);
}

// Calculate the total game score.
int BowlingGame::Impl::score() const {
    int totalScore = 0;
    // Process each frame (for frames 1–9, include bonuses; 10th-frame is taken as-is).
    for (size_t i = 0; i < frames.size(); i++) {
        int frameScore = frames[i]->baseScore();
        if (i < 9) {
            std::vector<int> rolls = frames[i]->getRolls();
            // Strike bonus: add the next two rolls.
            if (!rolls.empty() && rolls[0] == 10) {
                int bonus = 0;
                int bonusRollsNeeded = 2;
                for (size_t j = i + 1; j < frames.size() && bonusRollsNeeded > 0; j++) {
                    std::vector<int> nextRolls = frames[j]->getRolls();
                    for (int r : nextRolls) {
                        bonus += r;
                        bonusRollsNeeded--;
                        if (bonusRollsNeeded == 0)
                            break;
                    }
                }
                frameScore += bonus;
            }
            // Spare bonus: add the next roll.
            else if (rolls.size() >= 2 && (rolls[0] + rolls[1] == 10)) {
                if (i + 1 < frames.size()) {
                    std::vector<int> nextRolls = frames[i + 1]->getRolls();
                    if (!nextRolls.empty())
                        frameScore += nextRolls[0];
                }
            }
        }
        totalScore += frameScore;
    }
    return totalScore;
}

// Returns true if the game is over (10 frames and the 10th is complete).
bool BowlingGame::Impl::isGameOver() const {
    return (frames.size() == 10 && frames.back()->isComplete());
}
void  BowlingGame::Impl::printScoreBoard() const {
    const int cellWidth = 9;
    // Build a horizontal border.
    std::string border = "+";
    for (int i = 0; i < 10; i++) {
        border += std::string(cellWidth, '-') + "+";
    }

    // Print header (Frame numbers).
    std::cout << border << "\n";
    std::cout << "|";
    for (int i = 0; i < 10; i++) {
        std::string label = "F" + std::to_string(i + 1);
        std::cout << centerText(label, cellWidth) << "|";
    }
    std::cout << "\n" << border << "\n";

    // Print roll outcomes for each frame.
    std::cout << "|";
    for (int i = 0; i < 10; i++) {
        std::string cellContent;
        if (i < (int)frames.size()) {
            bool isTenth = (i == 9);
            std::vector<int> r = frames[i]->getRolls();
            int totalSlots = isTenth ? 3 : 2;
            // For each cell in this frame, display the formatted roll or a space.
            for (int j = 0; j < totalSlots; j++) {
                if (j > 0)
                    cellContent += " ";
                if (j < (int)r.size()) {
                    cellContent += formatRoll(r, j, isTenth);
                }
                else {
                    cellContent += " ";
                }
            }
        }
        else {
            cellContent = " ";
        }
        std::cout << centerText(cellContent, cellWidth) << "|";
    }
    std::cout << "\n" << border << "\n";

    // Compute cumulative scores per frame.
    std::vector<std::string> cumScores(10, " ");
    int total = 0;
    for (int i = 0; i < (int)frames.size() && i < 10; i++) {
        std::vector<int> r = frames[i]->getRolls();
        int frameScore = frames[i]->baseScore();
        bool scoreFinal = true;
        if (i < 9) {
            if (r.empty()) {
                scoreFinal = false;
            }
            else if (r[0] == 10) {
                int bonusCount = 0, bonus = 0;
                for (int j = i + 1; j < (int)frames.size() && bonusCount < 2; j++) {
                    std::vector<int> nextRolls = frames[j]->getRolls();
                    for (int pins : nextRolls) {
                        bonus += pins;
                        bonusCount++;
                        if (bonusCount == 2)
                            break;
                    }
                }
                if (bonusCount < 2)
                    scoreFinal = false;
                frameScore += bonus;
            }
            else if (r.size() >= 2 && (r[0] + r[1] == 10)) {
                if (i + 1 < (int)frames.size() && !frames[i + 1]->getRolls().empty()) {
                    frameScore += frames[i + 1]->getRolls()[0];
                }
                else {
                    scoreFinal = false;
                }
            }
            else if (r.size() < 2) {
                scoreFinal = false;
            }
        }
        else {
            // Tenth frame score is final only when complete.
            if (!frames[i]->isComplete())
                scoreFinal = false;
        }
        if (scoreFinal) {
            total += frameScore;
            cumScores[i] = std::to_string(total);
        }
        else {
            // Once a frame's score is not final, leave the remaining frames blank.
            break;
        }
    }

    // Print cumulative scores row.
    std::cout << "|";
    for (int i = 0; i < 10; i++) {
        std::cout << centerText(cumScores[i], cellWidth) << "|";
    }
    std::cout << "\n" << border << "\n";
}