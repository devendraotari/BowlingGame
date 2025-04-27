# include "BowlingGameUtil.hxx"

std::string centerText(const std::string& text, int width) {
    int len = text.size();
    if (len >= width) return text;
    int padding = width - len;
    int padLeft = padding / 2;
    int padRight = padding - padLeft;
    return std::string(padLeft, ' ') + text + std::string(padRight, ' ');
}

// Helper function to format one roll into a std::string.
// For normal frames, if the first roll is 10 we display "X" (strike), and if two rolls sum to 10 we display the second as "/".
// In the tenth frame the logic is similar but applies for up to three rolls.
std::string formatRoll(const std::vector<int>& rolls, int idx, bool isTenth) {
    if (idx >= (int)rolls.size()) return " ";
    int r = rolls[idx];
    if (!isTenth) {
        if (idx == 0 && r == 10)
            return "X";
        else if (idx == 1 && (rolls[0] + r == 10))
            return "/";
        else
            return std::to_string(r);
    }
    else {
        if (r == 10)
            return "X";
        else if (idx > 0 && (rolls[idx - 1] != 10) && (rolls[idx - 1] + r == 10))
            return "/";
        else
            return std::to_string(r);
    }
}