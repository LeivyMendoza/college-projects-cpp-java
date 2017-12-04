#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    
    const int MONTHS = 12;
    const int DAYS = 30;
    char forecast[MONTHS][DAYS];
    
    int count = 0;
    
    int row = 0;
    int col = 0;
    std::ifstream inputFile;
    
    inputFile.open("RainOrShine.txt");
    
     for (int x = 0; x < MONTHS; x++) {
        for (int y = 0; y < DAYS; y++) {
            inputFile >> forecast[x][y];
        }
    }

    inputFile.close();
    
   
    for (int x = 0; x < MONTHS; x++) {
        for (int y = 0; y < DAYS; y++) {
            std::cout << std::setw(2) << forecast[x][y] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}