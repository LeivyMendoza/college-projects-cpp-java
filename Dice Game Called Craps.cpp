#include <iostream>
#include <cstdlib>
#include <ctime>

int rollDice(void);
int firstRoll(void);
int makePoint(int);

int main() {
    int points = 0;
    int winLose = 0;
    points = firstRoll(); 
    if (points == 0 || points == 1) {
        return 0;
    } else {
        do {
        winLose = makePoint(points);
        } while (winLose == 0);
    }
}

int rollDice(void) {
    int random = 0;
    random = (rand() % 6) + 1;
    return random;
}

int firstRoll(void) {
    int total = 0;
    srand((int)time(0));
    total = rollDice() + rollDice();
    if (total == 7 || total == 11) {
        std::cout << "You rolled: " << total << "\n";
        std::cout << "You Win!\n";
        return 0;
    } else if (total == 2 || total == 3 || total == 12) {
        std::cout << "You rolled: " << total << "\n";
        std::cout << "You Lose!\n";
        return 1;
    } else {
        return total;
    }
}

int makePoint(int point) {
    int otherRoll = 0;
    otherRoll = rollDice() + rollDice();
    if (otherRoll == 7) {
        std::cout << "You Lose!\n";
        return -1;
    } else if (otherRoll == point) {
        std::cout << "You Win!\n";
        return 1;
    } else {
        return 0;
    }
}