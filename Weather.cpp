#include <iostream>
#include <iomanip>
#include <fstream>

const int ARRAY_MONTH = 12;
const int ARRAY_DAYS = 30;
const int ARRAY_COL = 5;
char numbers[ARRAY_MONTH][ARRAY_DAYS];
int number2[ARRAY_MONTH][ARRAY_COL];

int fillArray(char[][ARRAY_DAYS], int);
int fillArray2(const char[][ARRAY_DAYS], int);
void printArray(const int[][ARRAY_COL], int);
void total(const int[][ARRAY_COL], int);
int mostSunnyDAY(const int[][ARRAY_COL], int);

int main() {
    std::cout << "\tRainy" << std::setw(10) <<"Flooding" << std::setw(10) 
    << "Cloudy" << std::setw(10) << "Sunny" 
    << std::setw(15) << "Armegeddon\n";
    
    fillArray(numbers, ARRAY_MONTH);
    
    fillArray2(numbers, ARRAY_MONTH);
    
    printArray(number2, ARRAY_MONTH);
    
    total(number2, ARRAY_MONTH);
    
    mostSunnyDAY(number2, ARRAY_MONTH);
    
    std::cout << "press Enter to continue";

}

int fillArray(char num[][ARRAY_DAYS], int sizeR) {
    int count = 0;

    std::ifstream inputFile;
    
    inputFile.open("RainOrShine.txt");
    
    for (int x = 0; x < sizeR; x++) {
        for (int y = 0; y < ARRAY_DAYS; y++) {
            inputFile >> num[x][y];
        }
    }
    inputFile.close();
    return 0;
}

int fillArray2(const char forecast[][ARRAY_DAYS], int sizeR) {
    for (int row = 0; row < sizeR; row++) {
        for (int col = 0; col < ARRAY_DAYS; col++) {
            if (forecast[row][col] == 'R') {
                number2[row][0] += 1;
            } else if (forecast[row][col] == 'F') {
                number2[row][1] += 1;
            } else if (forecast[row][col] == 'C') {
                number2[row][2] += 1;
            } else if (forecast[row][col] == 'S') {
                number2[row][3] += 1;
            } else if (forecast[row][col] == 'A') {
                number2[row][4] += 1;
            }
        }
    }
    return 0;
}

void printArray(const int array[][ARRAY_COL], int size) {
    for (int x = 0; x < size; x++) {
        if (x == 0) {
            std::cout << "Jan";
            } else if (x == 1) {
                std::cout << "Feb";
            } else if (x == 2) {
                std::cout << "Mar";
            } else if (x == 3) {
                std::cout << "Apr";
            } else if (x == 4) {
                std::cout << "May";
            } else if (x == 5) {
                std::cout << "Jun";
            } else if (x == 6) {
                std::cout << "Jul";
            } else if (x == 7) {
                std::cout << "Aug";
            } else if (x == 8) {
                std::cout << "Sep";
            } else if (x == 9) {
                std::cout << "Oct";
            } else if (x == 10) {
                std::cout << "Nov";
            } else if (x == 11) {
                std::cout << "Dec";
            }
        for (int y = 0; y < ARRAY_COL; y++) {
             std::cout << std::setw(9) << array[x][y];
        }
        std::cout << "\n";
    }
}

void total(const int array[][ARRAY_COL], int size) {
    std::cout << "Total";
    for (int col = 0; col < ARRAY_COL; col++) {
        int total = 0;
        for (int row = 0; row < size; row++) {
            total += array[row][col];
        }
    std::cout << setpercision << std::setw(8.5) << total;
    }
}

int mostSunnyDAY(const int num[][ARRAY_COL], int size) {
    int count = 0;
    int x = 0;
    int mostSunny = num[0][x];
    
    for (int x = 0; x < 3; x++) {
        for (count = 0; count < size; count++) {
            if (num[count][x] > mostSunny) {
                mostSunny = num[count][x];
            }
        }
    }   
    std::cout << "\nThe sunniest month is: Apr with "
    << mostSunny << " days of Sun.\n";
    return 0;
}

