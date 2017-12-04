// This program verifies if the password provided meets the stated criteria.

#include <iostream>
#include <cctype>
#include <cstring>

bool checkLENGHT(const char[], int);
bool checkUPPERCASE(const char[], int);
bool checkLOWERCASE(const char[], int);
bool checkDIGIT(const char[], int);
bool checkSYMBOL(const char[], int);
bool checkCONSECUTIVE(const char[], int);

int main() {
    const int SIZE = 16;
    char password[SIZE];
    
    std::cout << "Enter your password: ";
    std::cin.getline(password, SIZE);
    std::cout << "\nPassword: ";

    if (!checkLENGHT(password, SIZE)) {
        return 1;
    }
    
    if (!checkUPPERCASE(password, SIZE)) {
        return 2;
    }
    
    if (!checkLOWERCASE(password, SIZE)) {
        return 3;
    }
    
    if (!checkDIGIT(password, SIZE)) {
        return 4;
    }
    
    if (!checkSYMBOL(password, SIZE)) {
        return 5;
    }
    
    if (!checkCONSECUTIVE(password, SIZE)) {
        return 6;
    }
    
    std::cout << "Passed\n";
    std::cout << "Press enter to end:";
    return 0;
}

bool checkLENGHT(const char key[], int size) {
    int lenght = 0;
    lenght = strlen(key);
    if (lenght < size - 1) {
        std::cout << "\n\tis too short\n";
        std::cout << "Press enter to end:";
        return false;
    }
    return true;
}

bool checkUPPERCASE(const char key[], int size) {
    int index = 0;
    for (int count = 0; count < size - 1; count++) {
        if (isupper(key[count])) {
            index += 1;
        } 
    }
    if (index >= 2) {
        return true;
    }
    std::cout << "\n\tdoes not have at least two uppercase letter\n";
    std::cout << "Press enter to end:";
    return false;
}

bool checkLOWERCASE(const char key[], int size) {
    int index = 0;
    for (int count = 0; count < size - 1; count++) {
        if (islower(key[count])) {
            index += 1;
        } 
    }
    if (index >= 1) {
        return true;
    }
    std::cout << "\n\tdoes not have at least one lowercase letter\n";
    std::cout << "Press enter to end:";
    return false;
}

bool checkDIGIT(const char key[], int size) {
    int index = 0;
    for (int count = 0; count < size - 1; count++) {
        if (isdigit(key[count])) {
            index += 1;
        } 
    }
    if (index >= 1) {
        return true;
    }
    std::cout << "\n\tdoes not contain a digit\n";
    std::cout << "Press enter to end:";
    return false;
}

bool checkSYMBOL(const char key[], int size) {
    int index = 0;
    for (int count = 0; count < size - 1; count++) {
        if (ispunct(key[count])) {
            index += 1;
        } 
    }
    if (index >= 1) {
        return true;
    }
    std::cout << "\n\tdoes not contain a symbol\n";
    std::cout << "Press enter to end:";
    return false;
}

bool checkCONSECUTIVE(const char key[], int size) {
    for (int count = 0; count < size - 1; count++) {
        if (key[count] == key[count + 1]) {
            std::cout << "\n\tcontains a duplicate consecutive symbol\n";
            std::cout << "Press enter to end:";
            return false;
        } 
    }
    return true;
}