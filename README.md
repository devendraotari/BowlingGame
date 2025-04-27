# Bowling Game Score Calculator

## Overview

The Bowling Game Score Calculator is a C++ project that simulates the scoring process for a single-player bowling game. It adheres to standard bowling rules such as strikes, spares, and bonus rolls in the 10th frame. The project demonstrates advanced object-oriented programming techniques by implementing:
- **Inheritance & Polymorphism:** An abstract `Frame` class with its derived classes (`NormalFrame` and `TenthFrame`) to capture the unique behaviors of different frames.
- **Pointer-to-Implementation (pimpl) Idiom:** The `BowlingGame` class uses this idiom to hide internal implementation details, promoting encapsulation and reducing compile-time dependencies.
- **Interactive Input & Console Output:** The main function allows users to enter rolls interactively and displays the evolving scoreboard in a table style (using hyphens and pipes).

## Project Structure & Design

### Classes and Their Roles

- **Frame (Abstract Base Class)**
  - Declares the interface for a bowling frame.
  - Key virtual methods:
    - `addRoll(int pins)`: Adds a roll’s pin count.
    - `isComplete() const`: Checks if the frame is finished.
    - `getRolls() const`: Returns the vector of rolls.
    - `baseScore() const`: Returns the basic score (sum of rolls in the frame).

- **NormalFrame (Derived Class)**
  - Manages frames 1–9.
  - Completes immediately if a strike is rolled (first roll equals 10) or after two rolls otherwise.

- **TenthFrame (Derived Class)**
  - Handles the unique rules of the 10th frame, allowing up to three rolls if a strike or spare is made.
  - Incorporates in-frame bonus throw logic (no advanced bonus calculation from future frames).

- **BowlingGame**
  - Manages the complete game flow by maintaining a collection of frames.
  - Uses the pimpl idiom to encapsulate internal operations such as creating new frames and computing scores.
  - Public methods include:
    - `roll(int pins)`: Records a new roll.
    - `score() const`: Returns the total game score.
    - `isGameOver() const`: Indicates whether all frames (including bonus rolls in the 10th frame) are complete.
    - `printScoreBoard() const`: Displays a formatted scoreboard on the console.

### Helper Function: `formatRoll()`

This helper function is crucial for rendering each roll’s outcome as a `std::string`:

- For **normal frames**:
  - If the first roll is a strike (10 pins), it returns `"X"`.
  - If two rolls add up to 10 (indicating a spare), the second roll is displayed as `"/"`.
  - Otherwise, the numeric pin count is returned.
  
- For the **10th frame**, the same logic applies, but the function accommodates up to three roll entries.

This function ensures that the scoreboard clearly indicates strikes and spares in an intuitive and compact format.

## How to Compile

To run this project open the solution file in visula studio and build and run the code
