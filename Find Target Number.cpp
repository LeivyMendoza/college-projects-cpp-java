#include <iostream>
#include <fstream>
#include <iomanip>

int range(void);
int fillArray(int [], int);
int searchNum(const int [], int, int);
int menu(const int [], int, int);
int minNum = 0;
int maxNum = 0;
int targetNum = 0;

int main() {
    const int ARRAY_SIZE = 200;
    int numbers[ARRAY_SIZE];
    int ifnotFound = 0;
    
    range();
    fillArray(numbers, ARRAY_SIZE);
    std::cout << "Enter your number from " << minNum << " to " << maxNum << ": ";
    std::cin >> targetNum;
    
    ifnotFound = searchNum(numbers, ARRAY_SIZE, targetNum);
    if (ifnotFound == -1){
        std::cout << "Not found\n";
    }
    
    menu(numbers, ARRAY_SIZE, targetNum);
    
}

int range(void) {
    std::cout << "Select a minimum and maximum "
    << "where the minimum is less than the maximum)\n";
    std::cout << "Enter the min number (1 to 1000): ";
    std::cin >> minNum;
    std::cout << "Enter the max number (1 to 1000): ";
    std::cin >> maxNum;
    while (minNum > maxNum) {
        std::cout << "Enter the max number (1 to 1000): ";
        std::cin >> maxNum;
    }
    return 0;
}

int fillArray(int num[], int size) {
    int count = 0;
    std::ifstream inputFile;
    
    inputFile.open("numbers.txt");
    
    while (count < size && inputFile >> num[count]) {
        if (num[count] > minNum && num[count] < maxNum ){
            count++;
        }
    }
    inputFile.close();
    return 0;
}

int searchNum(const int num[], int size, int userNum) {
    int count = 0;
    int index = -1;
    
    while (count < size) {
        if (num[count] == userNum) {
            std::cout << "Found at index: " << count << "\n";
            index = count;
        }
        count++;
    }
    return index;
}

int menu(const int num[], int size, int userNum) {
    int count = 0;
    char input;
    do {
        std::cout << "Would you like to: \n";
        std::cout << std::setw(16) << "Print (O)dds\n";
        std::cout << std::setw(17) << "Print (E)vens\n";
        std::cout << std::setw(17) << "Print (L)ower\n";
        std::cout << std::setw(18) << "Print (H)igher\n";
        std::cout << std::setw(16) << "(Q)uit\n";
        
        std::cin >> input; 
        
        switch (input) {
          case ('O') :  std::cout << "Printing Odds\n";
                            while (count < size) {
                            if (num[count] % 2 == 1) {
                                std::cout << count << ": " << num[count] << "\n";
                            }
                            count++;
                        }
          break;
          
          case ('E') :  std::cout << "Printing Evens\n";
                            while (count < size) {
                            if (num[count] % 2 == 0) {
                                std::cout << count << ": " << num[count] << "\n";
                            }
                            count++;
                        }
          break;
          
          case ('L') : std::cout << "Printing Lower\n";
                            while (count < size) {
                            if (num[count] < userNum) {
                                std::cout << count << ": " << num[count] << "\n";
                            }
                            count++;
                        }
          break;
          
          case ('H') :  std::cout << "Printing Higher\n";
                            while (count < size) {
                            if (num[count] > userNum) {
                                std::cout << count << ": " << num[count] << "\n";
                            }
                            count++;
                        }
          break;
          
          case ('Q') : break;
        } 
    } while (input != 'Q');
    return 0;
}