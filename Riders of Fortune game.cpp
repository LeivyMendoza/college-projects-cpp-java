#include <iostream>
//#include <cstdlib>
#include <ctime>

const int ROWSIZE = 2;
const int COLSIZE = 28;
const char PLAYER = 'P';
const char DRAGON = 'D';
const char EMPTYSPACE = 'E';
const char MAPSPACE = 42;
const int DRAGONLOCATION = 27;
int playerLocation = 0;
int currentWeapon = 0;
int playerXP = 0;
bool mustMove = false;

void initTheBoard(char[][COLSIZE]);
void printTheBoard(const char[][COLSIZE]);
void initMonsters(char[][COLSIZE], char, int);
void initWeapons(char[][COLSIZE], char);
int movement(char[][COLSIZE], int);
bool gameplay(char[][COLSIZE]);
bool ifEncounterDragon(char[][COLSIZE]);
bool exploreSameSpace(int);
bool encounterMonster(int);
void equipWeapon(int);
void emptySpace();
void mustRollDice();
int randomInit();
int rollDice();
int menu();

enum Weapons {
    crossbow = 3,
    fail,
    broadsword,
    dragonslayer,
    spellofthegods
};

enum Monsters {
    mouse = 3,
    wolf,
    lion,
    zombie,
    gorilla,
    dragon = 10
};

int main() {
    srand(time(NULL));
    bool gameStatus;
    char theBoard[ROWSIZE][COLSIZE];

    initTheBoard(theBoard);

    do {
        printTheBoard(theBoard);
        gameStatus = gameplay(theBoard);
    } while (gameStatus);

    return 0;
}

bool gameplay(char board[][COLSIZE]) {
    int input = 0;
    input = menu();

    switch (input) {
        case 1: playerLocation = movement(board, playerLocation);
            if (ifEncounterDragon(board)) {
                return false;
            }
            mustMove = false;
            break;
        case 2: if (exploreSameSpace(input)) {
                break;
            }

            switch (board[1][playerLocation]) {
                case 'C': equipWeapon(crossbow);
                    break;
                case 'F': equipWeapon(fail);
                    break;
                case 'B': equipWeapon(broadsword);
                    break;
                case 'D': equipWeapon(dragonslayer);
                    break;
                case 'S': equipWeapon(spellofthegods);
                    break;
                case 'M': if (!encounterMonster(mouse)) {
                        return false;
                    }
                    break;
                case 'W': if (!encounterMonster(wolf)) {
                        return false;
                    }
                    break;
                case 'L': if (!encounterMonster(lion)) {
                        return false;
                    }
                    break;
                case 'Z': if (!encounterMonster(zombie)) {
                        return false;
                    }
                    break;
                case 'G': if (!encounterMonster(gorilla)) {
                        return false;
                    }
                    break;
                case 'E': emptySpace();
                    break;
                case 'P': mustRollDice();
                    break;
            }
            break;
    }
    return true;
}

void initTheBoard(char board[][COLSIZE]) {
    int randomSpace = 0;

    for (int col = 0; col < COLSIZE; col++) {
        board[0][col] = MAPSPACE;
        board[1][col] = EMPTYSPACE;
    }

    board[0][0] = PLAYER;
    board[0][27] = DRAGON;
    board[1][0] = PLAYER;
    board[1][27] = DRAGON;

    /*
        Weapons
        ----------
        Crossbow == C,
        Fail == F
        BroadSword == B
        DragonSlayer == D
        SpellOfTheGods == S
     */

    initWeapons(board, 'C');
    initWeapons(board, 'F');
    initWeapons(board, 'B');
    initWeapons(board, 'D');
    initWeapons(board, 'S');

    /*    
        Monsters
        ---------        
        Mouse == M
        Wolf == W
        Lion == L
        Zombie == Z
        Gorrila == G
     */

    initMonsters(board, 'M', 3);
    initMonsters(board, 'W', 3);
    initMonsters(board, 'L', 3);
    initMonsters(board, 'Z', 3);
    initMonsters(board, 'G', 2);
}

void initMonsters(char board[][COLSIZE], char monster, int monsterCount) {
    int count = 0;
    int randomSpace = 0;
    do {
        randomSpace = randomInit();

        if (board[1][randomSpace] == EMPTYSPACE) {
            board[1][randomSpace] = monster;
            count++;
        }
    } while (count < monsterCount);
}

void initWeapons(char board[][COLSIZE], char weapon) {
    int randomSpace = 0;
    do {
        randomSpace = randomInit();
        if (board[1][randomSpace] == EMPTYSPACE) {
            board[1][randomSpace] = weapon;
        }
    } while (board[1][randomSpace] != weapon);
}

int movement(char board[][COLSIZE], int index) {
    int random = 0;

    random = rollDice();

    board[0][index] = MAPSPACE;
    for (unsigned int i = 0; i < 300000000; i++);

    index += random;

    board[0][index] = PLAYER;

    return index;
}

int menu() {
    int input = 0;
    std::cout << "Please choose an option from the following menu:\n";
    std::cout << "------------------------------------------------\n";
    std::cout << "1) Travel to another space\n";
    std::cout << "2) Explore the current space\n";
    std::cin >> input;

    return input;
}

void equipWeapon(int weapon) {
    if (currentWeapon < weapon) {
        currentWeapon = weapon;
        std::cout << "You found and equipped a ";
        switch (weapon) {
            case 3: std::cout << "CrossBow!\n";
                break;
            case 4: std::cout << "Fail!\n";
                break;
            case 5: std::cout << "BroadSword!\n";
                break;
            case 6: std::cout << "DragonSlayer!\n";
                break;
            case 7: std::cout << "Spell of the Gods!\n";
                break;
        }
        for (unsigned int i = 0; i < 1000000000; i++);
        mustMove = true;
    } else {
        std::cout << "You found a ";
        switch (weapon) {
            case 3: std::cout << "CrossBow";
                break;
            case 4: std::cout << "Fail";
                break;
            case 5: std::cout << "BroadSword";
                break;
            case 6: std::cout << "DragonSlayer";
                break;
            case 7: std::cout << "Spell of the Gods";
                break;
        }
        std::cout << " but your current weapon is stronger\n";
        for (unsigned int i = 0; i < 1000000000; i++);
        mustMove = true;
    }
    return;
}

bool encounterMonster(int monster) {
    int attackAmount = 0;
    attackAmount = currentWeapon + rollDice();
    if (attackAmount >= mouse) {
        std::cout << "You've encountered a ";
        switch (monster) {
            case 3: std::cout << "Mouse";
                break;
            case 4: std::cout << "Wolf";
                break;
            case 5: std::cout << "Lion";
                break;
            case 6: std::cout << "Zombie";
                break;
            case 7: std::cout << "Gorilla";
                break;
        }
        std::cout << " which stood no chance against you\n";
        for (unsigned int i = 0; i < 1000000000; i++);
        playerXP += 2;
        mustMove = true;
        return true;
    } else {
        std::cout << "You did not stand a chance against the ";
        switch (monster) {
            case 3: std::cout << "Mouse\n";
                break;
            case 4: std::cout << "Wolf\n";
                break;
            case 5: std::cout << "Lion\n";
                break;
            case 6: std::cout << "Zombie\n";
                break;
            case 7: std::cout << "Gorilla\n";
                break;
        }
        return false;
    }
}

bool ifEncounterDragon(char board[][COLSIZE]) {
    int attackAmount = 0;

    if (playerLocation >= DRAGONLOCATION) {
        board[0][DRAGONLOCATION] = PLAYER;
        printTheBoard(board);

        std::cout << "You've reached the DRAGON...\n";
        for (unsigned int i = 0; i < 1500000000; i++);

        if (playerXP < 5) {
            std::cout << "\n\"Alas, the dragon’s eyes stare at you and "
                    << "places you under his spell.\nYou try to move "
                    << "but fail to do so and find yourself torched by "
                    << "the dragon’s fire.\nIf only you had more "
                    << "experience, you could have seen it coming.\"";
        } else {
            attackAmount = currentWeapon + rollDice();
            if (attackAmount >= dragon) {
                std::cout << "\n\"Due to your cunning and experience, "
                        << "you have defeated the deadly dragon.\n"
                        << "Your quest has ended good sir.\nYou’ve "
                        << "obtained the Chalice of knowledge and all "
                        << "of earth’s mysteries are revealed.\"";
            } else {
                std::cout << "Sorry you did not stand a chance against"
                        << " the all mighty DRAGON\nGAMEOVER\n";
            }
        }
        return true;
    }
    return false;
}

bool exploreSameSpace(int input) {
    if (input == 2 && mustMove) {
        std::cout << "Sorry you can not explore the same space twice\n";
        for (unsigned int i = 0; i < 1000000000; i++);
        return true;
    }
    return false;
}

void emptySpace(void) {
    std::cout << "\"There is nothing for you to do, so "
            << "you reflect upon your adventures thus far. You "
            << "take the time to train and enhance your "
            << "reflexes\n\"";
    for (unsigned int i = 0; i < 1000000000; i++);
    playerXP += 1;
    mustMove = true;
    return;
}

void mustRollDice(void) {
    std::cout << "Sorry you must travel to another space"
            << " on your first turn\n";
    for (unsigned int i = 0; i < 1000000000; i++);
    return;
}

void printTheBoard(const char board[][COLSIZE]) {
    system("clear");

    for (int col = 0; col < COLSIZE; col++) {
        std::cout << board[0][col];
    }
    std::cout << "\n\n";
}

int rollDice(void) {
    int random = 0;
    random = (rand() % 6) + 1;
    return random;
}

int randomInit(void) {
    int random = 0;
    random = (rand() % 26) + 1;
    return random;
}