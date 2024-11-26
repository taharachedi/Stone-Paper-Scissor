# ✂️🪨📄 Stone-Paper-Scissors Game in C++  

> **A fun and interactive console-based game where players challenge the computer in multiple rounds of Stone-Paper-Scissors! 🕹️**  

---

## 🌟 Project Overview  
This **C++ project** simulates the classic Stone-Paper-Scissors game 🎮, allowing players to compete against the computer in a series of rounds. It provides a user-friendly experience with dynamic console colors, detailed round results, and an exciting final summary!  

---

## ✨ Features  
- 🕹️ **Multiplayer Rounds**: Play up to **100 rounds** and compete for victory.  
- 🎲 **Random Computer Choices**: Computer decisions are randomized for fair gameplay.  
- 📊 **Round Results Display**: Displays the player's choice, computer's choice, and round winner dynamically.  
- 🎨 **Dynamic Colors**: Highlights the winner of each round with unique console colors.  
- 🏆 **Game Summary**: Provides a detailed report of the total wins, losses, and draws.  
- 🔁 **Replay Option**: Play as many games as you like with a replay prompt.  

---

## ⚙️ How It Works  

### Core Components  
1. **Player and Computer Choices**:  
   - The player selects a choice (Stone, Paper, or Scissors 🪨📄✂️).  
   - The computer generates its choice randomly.  

2. **Game Logic**:  
   - **Enum-based structure** organizes the choices and winner calculation.  
   - Round winners are determined based on the traditional rules of Stone-Paper-Scissors:  
     - 🪨 Stone beats ✂️ Scissors.  
     - 📄 Paper beats 🪨 Stone.  
     - ✂️ Scissors beat 📄 Paper.  

3. **Results Tracking**:  
   - **Per Round**: Tracks choices and the winner for each round.  
   - **Overall**: Aggregates total wins, losses, and draws to determine the final game winner.  

---

## ▶️ Sample Output  

Here’s what a typical game output might look like:  

```plaintext  
Round [1] begins:  
Your Choice: 📄 Paper  
Computer Choice: ✂️ Scissors  
Round Winner: [Computer]  

Round [2] begins:  
Your Choice: 🪨 Stone  
Computer Choice: 🪨 Stone  
Round Winner: [No Winner]  

Final Game Results:  
Rounds Played: 5  
Player Wins: 2  
Computer Wins: 3  
Draws: 0  
Winner: Computer  
