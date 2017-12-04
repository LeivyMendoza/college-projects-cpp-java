#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

struct Weather {
  std::string month;
  std::string day;
  double highTEMP;
  double lowTEMP;
  double rainfall;
};

void fillWeatherStruct(Weather[]);
double totalRAIN(const Weather[], int);
double avgTEMP(const Weather[], int);
int highestTEMP(const Weather[], int);
int lowestTEMP(const Weather[], int);

int main() {
    const int SIZE = 652;
    Weather analysis[SIZE]; 
    int high = 0;
    int low = 0;
    
    fillWeatherStruct(analysis);
    high = highestTEMP(analysis, SIZE);
    low = lowestTEMP(analysis, SIZE);
    
    std::cout << "Annual Rain Analysis\n";
    std::cout << "Total Rain:" << std::setw(26) << std::setprecision(2) 
    << std::fixed << totalRAIN(analysis, SIZE) << "\n";
    std::cout << "Average temp:" << std::setw(23) << std::setprecision(2) 
    << std::fixed << avgTEMP(analysis, SIZE) << "\n";
    std::cout << "The highest temp is: " << analysis[high].highTEMP << " in "
    << analysis[high].month << " on " << analysis[high].day << "\n";
    std::cout << "The Lowest temp is: " << analysis[low].lowTEMP << " in "
    << analysis[low].month << " on " << analysis[low].day << "\n";
    std::cout << "Press enter to continue.\n";
    return 0;
}

void fillWeatherStruct(Weather w[]) {
    int count = 0;
    std::ifstream inputFile;
    
    inputFile.open("input.txt");
    
    while (inputFile) {
        inputFile >> w[count].month;
        inputFile >> w[count].day;
        inputFile >> w[count].highTEMP;
        inputFile >> w[count].lowTEMP;
        inputFile >> w[count].rainfall;
        count++;
    }
    inputFile.close();
    return;
}

double totalRAIN(const Weather w[], int size) {
    int count = 0;
    double total = 0;
    for (count = 0; count < size; count++) {
        total += w[count].rainfall;
    }
    return total;
}

double avgTEMP(const Weather w[], int size) {
    int count = 0;
    double avg = 0;
    double total = 0;
    for (count = 0; count < size; count++) {
        total += w[count].highTEMP;
        total += w[count].lowTEMP;
        avg = total / (size * 2);
    }
    return avg;
}

int highestTEMP(const Weather w[], int size) {
    int count = 0;
    double highest = 0;
    int temp = 0;
    for (count = 0; count < size; count++) {
        if (w[count].highTEMP > highest) {
            highest = w[count].highTEMP;
            temp = count;
        }
    }
    return temp;
}

int lowestTEMP(const Weather w[], int size) {
    int count = 0;
    double lowest = 0;
    int temp = 0;
    for (count = 0; count < size; count++) {
        if (w[count].lowTEMP < lowest) {
            lowest = w[count].lowTEMP;
            temp = count;
        }
    }
    return temp;
}