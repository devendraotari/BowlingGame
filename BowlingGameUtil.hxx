#pragma once
#include <string>
#include <vector>

// @brief Helper function to center text in a fixed width.
std::string centerText(const std::string& text, int width);

// @brief Helper function to format one roll into a std::string.
// For normal frames, if the first roll is 10 we display "X" (strike), and if two rolls sum to 10 we display the second as "/".
// In the tenth frame the logic is similar but applies for up to three rolls.
std::string formatRoll(const std::vector<int>& rolls, int idx, bool isTenth);
