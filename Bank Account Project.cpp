/* This program validates the account number and charge amount. 
The program then determines if the current charge amount exceeds the account balance. */

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

int accountNumber = 0;
float chargeAmount = 0;
const int TOTALACCOUNTS = 18;
int masterCount = 0;
std::vector<int> accounts(TOTALACCOUNTS);
std::vector<int> accounts2(TOTALACCOUNTS);
std::vector<float> currentBalance(TOTALACCOUNTS);
std::vector<float> maxBalance(TOTALACCOUNTS);

int fillVector(int);
void sortAccount(int);
int searchAccount (const std::vector<int>, int, int);
void searchCount(int, int);
void verifyPayment(float);

int main() {
    std::cout << "Enter your account number: "; 
    std::cin >> accountNumber;
    std::cout << "Enter your charge amount: ";
    std::cin >> chargeAmount;
    while (chargeAmount < 0) {
        std::cout << "Please enter a positive number\n";
        std::cout << "Enter your charge amount: ";
        std::cin >> chargeAmount;
    }
    
    fillVector(TOTALACCOUNTS);
    
    sortAccount(TOTALACCOUNTS);
    
    if (searchAccount(accounts, TOTALACCOUNTS, accountNumber) == 1) {
        std::cout << "Account:" << accountNumber << " invalid.\n";
        std::cout << "Press Enter to exit";

        return 1;
    }
    
    searchCount(TOTALACCOUNTS, accountNumber);
    
    verifyPayment(chargeAmount);
    
    std::cout << "Press Enter to exit";
    
    return 0;
}

int fillVector(int rows) {
    int count = 0;
    std::ifstream inputFile;
    
    inputFile.open("valid_accounts.txt");
    
    while (count < rows) {
        inputFile >> accounts[count];
        inputFile >> currentBalance[count];
        inputFile >> maxBalance[count];
        count++;
    }
    inputFile.close();
    return 0;
}

void copyAccountVector (int size) {
    int count = 0;
    for (count = 0; count < size; count++) {
        accounts2[count] = accounts[count];
    }
    return;
}

void sortAccount(int size) {
    int start = 0;
    int minIndex = 0;
    int minValue = 0;
    
    for (start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = accounts[start];
        for (int index = start + 1; index < size; index++) {
            if (accounts[index] < minValue) {
                minValue = accounts[index];
                minIndex = index;
            }
        }
        accounts[minIndex] = accounts[start];
        accounts[start] = minValue;
    }
    return;
}

int searchAccount (const std::vector<int> vector, int size, int account) {
    int first = 0;
    int last = size - 1;
    int middle;

    while (first <= last) {
        middle = (first + last) / 2;
        if (vector[middle] == account) {
            return 0;
        } else if (vector[middle] > account) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }
    return 1;
}

void searchCount(int size, int account) {
    int count = 0;
    
    while (count < size) {
        if (accounts2[count] == account) {
            masterCount = count;
        }
        count++;
    }
    return;
}

void verifyPayment(float charge) {
    
    double balance = 0;
    balance = currentBalance[masterCount] + charge;
    
    if (balance > maxBalance[masterCount]) {
        std::cout << "Account:" << accountNumber << " invalid.\n";
        std::cout << "Insufficient Funds\n";
    } else {
        std::cout << "Account:" << accountNumber << " valid.\n";
        std::cout << "Charge for $" << std::setprecision(2) 
        << std::fixed << charge << " is accepted.\n";
    }
}